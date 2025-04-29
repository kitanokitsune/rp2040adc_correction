/*  
 *  Required Library: Raspberry Pi Pico/RP2040 by earlephilhower
 *  IDE Settings:
 *    Target Board: "Raspberry Pi Pico", "Pico W", "Pico 2" or "Pico 2W"
 *    Flash Size:   "2MB (no FS)" or "4MB (no FS)"
 *    CPU Speed:    "125 MHz"
 *    Optimize:     "Optimize More (-O2)"
 */

#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/adc.h"
#include <EEPROM.h>

/* USB serial baud rate (bps) */
#define USB_SERIAL_BAUD 115200

/*****************************************************************************
      USB serial send
 *****************************************************************************/
#define USB_SEND_BUF_SIZE 63
/* -----------------------------------------------------------*/
void usb_serial_write(uint8_t * data, int len) {
  static uint8_t sendbuffer[USB_SEND_BUF_SIZE+1];
  static int sendlength = 0;

  if (!Serial) return;

  if (len >= (USB_SEND_BUF_SIZE)) len = (USB_SEND_BUF_SIZE) - 1;

  if ( (len == 0) || (sendlength+len >= (USB_SEND_BUF_SIZE)) ) {
    if (sendlength > 0) {
      Serial.write(sendbuffer, sendlength);
      sendlength = 0;
    }
  }

  for (; len > 0; --len) {
    sendbuffer[sendlength++] = *(data++);
  }
  sendbuffer[sendlength] = '\0';
}

void usb_serial_write_flush(uint8_t * data, int len) {
  usb_serial_write(data, len);
  usb_serial_write(nullptr, 0);
}
/*****************************************************************************
      USB serial read
 *****************************************************************************/
#define USB_READ_BUF_SIZE (63)
#define CR (0x0d)
#define LF (0x0a)
char * usb_serial_readline_nb(void)
{
  static int len = 0;
  static char readbuffer[USB_READ_BUF_SIZE + 1];
  int available, c, i;

  if (!Serial) return nullptr;

  available = Serial.available();
  for ( i = 0 ; i < available ; i++ ) {

    /* Truncate when buffer overflow */
    if ( len >= USB_READ_BUF_SIZE ) {
      readbuffer[len] = '\0';
      len = 0;
      return readbuffer;
    }

    c = Serial.read();

    /* End of line */
    if ( c == CR || c == LF ) {
      if (len > 0) {
        readbuffer[len] = '\0';
        len = 0;
        return readbuffer;
      } else {
        len = 0;
        return nullptr;
      }
    }

    readbuffer[len] = (char)c;
    len++;

  }

  return nullptr;
}


/*****************************************************************************
      Format ADC Results
 *****************************************************************************/
int adc_format(uint8_t * buf, uint16_t * adata, int num)
{
  int i, len;
  uint16_t d, dig;

  len = 0;
  for (i = 0 ; i < max(num, 1) ; ++i) {

    if ( i > 0 ) {
      buf[len] = ',';
      ++len;
    }

    for ( dig = 1000 ; dig > 0 ; dig = dig / 10 ) {
      d = (adata[i] / dig) % 10;
      if ( dig >= 10 && adata[i] < dig ) {
        buf[len] = ' ';
      } else {
        buf[len] = '0' + d;
      }
      ++len;
    }

  }
  buf[len] = '\n';
  ++len;
  buf[len] = '\0';

  return len;
}


/*****************************************************************************
      Code for CPU CORE0
 *****************************************************************************/
#define PWM_BIT     (15)  /* PWM_BIT in [12, 13, 14, 15, 16] */
#define PWM_PIN     (21) /* GPIO21 */
#define PWM_WRAP    ((1<<(PWM_BIT))-1)
#define PWM_CLK_DIV (1<<max(0, 16-(PWM_BIT)))

volatile uint16_t pwm_duty;
volatile uint slice_num;
volatile bool eeprom_active = false;
char unique_id[ 2 * PICO_UNIQUE_BOARD_ID_SIZE_BYTES + 2 ];

/* -----------------------------------------------------------*/
void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  /* Force DC/DC operation mode to PWM in order to reduce ripple noise */
#if defined(ARDUINO_RASPBERRY_PI_PICO) || defined(ARDUINO_RASPBERRY_PI_PICO_2)
  pinMode(23, OUTPUT);
  digitalWrite(23, HIGH);
#elif defined(ARDUINO_RASPBERRY_PI_PICO_W) || defined(ARDUINO_RASPBERRY_PI_PICO_2W)
  pinMode(LED_BUILTIN+1, OUTPUT); /* WL_GPIO1 */
  digitalWrite(LED_BUILTIN+1, HIGH); /* PFM:WL_GPIO1=LOW, PWM:WL_GPIO1=HIGH */
#endif

  gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);
  slice_num = pwm_gpio_to_slice_num(PWM_PIN);
  pwm_set_clkdiv_int_frac(slice_num, PWM_CLK_DIV, 0);
  pwm_set_wrap(slice_num, PWM_WRAP);
  pwm_duty = 0;
  pwm_set_chan_level(slice_num, PWM_CHAN_B, pwm_duty); /* (PWM_PIN % 2)==0 ? CHAN_A : CHAN_B */
  pwm_set_enabled(slice_num, true);

  adc_init();
  adc_gpio_init(26);  /* A0 = GPIO26 */
  analogReadResolution(12);

  /********************************/
  /*  SETUP COMMUNICATION DEVICE  */
  /********************************/

  /* start USB serial device */
  Serial.begin(USB_SERIAL_BAUD);

  /* Get Pico Board Serial Number */
  pico_get_unique_board_id_string(unique_id,  2 * PICO_UNIQUE_BOARD_ID_SIZE_BYTES + 1);
}


/* ------------------------------------------------------------------*/
/* Main Loop                                                         */
enum COMMAND {
  CMD_PASS,
  CMD_GET_SERIAL,
  CMD_LED,
  CMD_PWM_SET_DUTY,
  CMD_ADC_READ,
  CMD_ADC_READ_WITH_CORRECTION,
  CMD_EEPROM_BEGIN,
  CMD_EEPROM_READ,
  CMD_EEPROM_WRITE,
  CMD_EEPROM_COMMIT,
  /*--------------*/
  CMD_UNKNOWN
};

int8_t const *adc_err;
void loop() {

  static enum COMMAND cmd = CMD_PASS;
  int len, i;
  char *p;
  uint32_t param[2];
  uint8_t buf[256];
  uint16_t adata[16];

  p = usb_serial_readline_nb();

  /**********************/
  /* Decode Instruction */
  /**********************/
  if ( p != nullptr ) {
    while ( *p == ' ' ) p++;
    switch ( p[0] ) {

      /* -------- GET SERIAL NUMBER -------- */
      case 'n': cmd = CMD_GET_SERIAL;
        break;

      /* -------- LED ON/OFF -------- */
      case 'l': cmd = CMD_LED;
        p++;
        while ( *p == ' ' ) p++;
        if ( *p == '1' ) {
          param[0] = 1;
        } else {
          param[0] = 0;
        }
        break;

      /* -------- SET PWM DUTY -------- */
      case 'p': cmd = CMD_PWM_SET_DUTY;
        param[0] = 0;
        p++;
        while ( *p == ' ' ) p++;
        while ( *p >= '0' && *p <= '9' ) {
          param[0] = param[0] * 10 + (*p - '0');
          p++;
          if ( param[0] > PWM_WRAP ) param[0] = PWM_WRAP;
        }
        break;

      /* -------- ADC READ -------- */
      case 'a': cmd = CMD_ADC_READ;
        param[0] = 0;
        p++;
        while ( *p == ' ' ) p++;
        while ( *p >= '0' && *p <= '9' ) {
          param[0] = param[0] * 10 + (*p - '0');
          p++;
          if ( param[0] > 12 ) param[0] = 12;
        }
        break;

      /* -------- ADC READ WITH CORRECTION -------- */
      case 'A': cmd = CMD_ADC_READ_WITH_CORRECTION;
        param[0] = 0;
        p++;
        while ( *p == ' ' ) p++;
        while ( *p >= '0' && *p <= '9' ) {
          param[0] = param[0] * 10 + (*p - '0');
          p++;
          if ( param[0] > 12 ) param[0] = 12;
        }
        break;

      /* -------- EEPROM BEGIN -------- */
      case 'b': cmd = CMD_EEPROM_BEGIN;
        break;

      /* -------- EEPROM READ -------- */
      case 'r': cmd = CMD_EEPROM_READ;
        param[0] = 0;
        p++;
        while ( *p == ' ' ) p++;
        while ( *p >= '0' && *p <= '9' ) {
          param[0] = param[0] * 10 + (*p - '0');
          p++;
          if ( param[0] > 4095 ) param[0] = 4095;
        }
        break;

      /* -------- EEPROM WRITE -------- */
      case 'w': cmd = CMD_EEPROM_WRITE;
        param[0] = 0;
        p++;
        while ( *p == ' ' ) p++;
        while ( *p >= '0' && *p <= '9' ) {
          param[0] = param[0] * 10 + (*p - '0');
          p++;
          if ( param[0] > 4095 ) param[0] = 4095;
        }
        param[1] = 0;
        p++;
        while ( *p == ' ' || *p == ',' ) p++;
        while ( *p >= '0' && *p <= '9' ) {
          param[1] = param[1] * 10 + (*p - '0');
          p++;
          if ( param[1] > 255 ) param[1] = 255;
        }
        break;

      /* -------- EEPROM COMMIT -------- */
      case 'c':
        if ( p[1] == 'o' &&
             p[2] == 'm' &&
             p[3] == 'm' &&
             p[4] == 'i' &&
             p[5] == 't' &&
             p[6] == '\0') {
          cmd = CMD_EEPROM_COMMIT;
        } else {
          cmd = CMD_UNKNOWN;
        }
        break;

      /* -------- DEFAULT -------- */
      default:
        cmd = CMD_UNKNOWN;
    }
  }

  /********************/
  /* Dispatch Command */
  /********************/
  switch ( cmd ) {

    /* -------- GET SERIAL NUMBER -------- */
    case CMD_GET_SERIAL:
      len = sprintf((char *)buf, "%s\n",unique_id);
      usb_serial_write_flush(buf, len);
      cmd = CMD_PASS;
      break;

    /* -------- LED ON/OFF -------- */
    case CMD_LED:
      if ( param[0] == 1) {
        digitalWrite(LED_BUILTIN, HIGH);
        len = sprintf((char *)buf, "LED On\n");
      } else {
        digitalWrite(LED_BUILTIN, LOW);
        len = sprintf((char *)buf, "LED Off\n");
      }
      usb_serial_write_flush(buf, len);
      cmd = CMD_PASS;
      break;

    /* -------- SET PWM DUTY -------- */
    case CMD_PWM_SET_DUTY:
      pwm_set_chan_level(slice_num, PWM_CHAN_B, param[0]);
      len = sprintf((char *)buf, "Set PWM duty:%5d\n",param[0]);
      usb_serial_write_flush(buf, len);
      cmd = CMD_PASS;
      break;

    /* -------- ADC READ -------- */
    case CMD_ADC_READ:
      i = 0;
      do {                           /* 1 loop = 66.12 usec */
        delayMicroseconds(61);       /* 61 usec */
        adata[i] = analogRead(A0);   /*  4 usec */
        i++;
      } while ( i<param[0] );
      len = adc_format(buf, adata, param[0]);
      usb_serial_write_flush(buf, len);
      cmd = CMD_PASS;
      break;

    /* -------- ADC READ WITH CORRECTION -------- */
    case CMD_ADC_READ_WITH_CORRECTION:
      if ( !eeprom_active ) {
        len = sprintf((char *)buf, "nop\n");
      } else {
        i = 0;
        do {
          delayMicroseconds(61);
          adata[i] = analogRead(A0);
          i++;
        } while ( i<param[0] );
        i = 0;
        do {
          adata[i] = adata[i] + adc_err[adata[i]];
          i++;
        } while ( i<param[0] );
        len = adc_format(buf, adata, param[0]);
      }
      usb_serial_write_flush(buf, len);
      cmd = CMD_PASS;
      break;

    /* -------- EEPROM BEGIN -------- */
    case CMD_EEPROM_BEGIN:
      if ( !eeprom_active ) {
        EEPROM.begin(4096);
        adc_err = reinterpret_cast<int8_t const *>(EEPROM.getConstDataPtr());
        eeprom_active = true;
      }
      len = sprintf((char *)buf, "EEPROM Emulation started!\n");
      usb_serial_write_flush(buf, len);
      cmd = CMD_PASS;
      break;

    /* -------- EEPROM READ -------- */
    case CMD_EEPROM_READ:
      if ( eeprom_active ) {
        len = sprintf((char *)buf, "%3d\n", EEPROM.read(param[0]));
      } else {
        len = sprintf((char *)buf, "nop\n");
      }
      usb_serial_write_flush(buf, len);
      cmd = CMD_PASS;
      break;

    /* -------- EEPROM WRITE -------- */
    case CMD_EEPROM_WRITE:
      if ( eeprom_active ) {
        EEPROM.write(param[0], (byte)param[1]);
        len = sprintf((char *)buf, "Write EEPROM[%4d]=%3d\n", param[0], (byte)param[1]);
      } else {
        len = sprintf((char *)buf, "nop\n");
      }
      usb_serial_write_flush(buf, len);
      cmd = CMD_PASS;
      break;

    /* -------- EEPROM COMMIT -------- */
    case CMD_EEPROM_COMMIT:
      if ( eeprom_active ) {
        EEPROM.commit();
        len = sprintf((char *)buf, "EEPROM commit!\n");
      } else {
        len = sprintf((char *)buf, "nop\n");
      }
      usb_serial_write_flush(buf, len);
      cmd = CMD_PASS;
      break;

    case CMD_UNKNOWN:
      len = sprintf((char *)buf, "unknown command\n");
      usb_serial_write_flush(buf, len);
      cmd = CMD_PASS;

    /* -------- DEFAULT -------- */
    default: break;
  }

}
