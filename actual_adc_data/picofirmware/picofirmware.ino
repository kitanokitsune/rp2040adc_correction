/*  
 *  ADC test for Raspberry Pi Pico/W/2/2W
 *  
 *  Required Library: Arduino-Pico by earlephilhower
 *  https://github.com/earlephilhower/arduino-pico
 *  
 *  IDE Settings:
 *    Target Board: "Raspberry Pi Pico/W/2/2W"
 *    CPU Speed: "125MHz"
 *    Optimize: "Optimize More (-O2)"
 *  
 */

#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/adc.h"

#define PWM_BIT      (15)  /* PWM_BIT in [12, 13, 14, 15, 16] */
#define NUM_SAMPLES  (10)

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


/*****************************************************************************
      Code for CPU CORE0
 *****************************************************************************/

volatile uint16_t pwm_duty;
volatile uint slice_num;

#define SW1_PIN     (8)  /* GPIO8 */
#define PWM_PIN     (21) /* GPIO21 */

#define PWM_WRAP    ((1<<(PWM_BIT))-1)
#define PWM_CLK_DIV (1<<max(0, 16-(PWM_BIT)))
/* -----------------------------------------------------------*/
void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(SW1_PIN, INPUT_PULLUP);

  /* Wait until SW1_PIN pull-up resistor charges up a capacitor */
  while (digitalRead(SW1_PIN) == LOW) delay(100);

  /* Force DC/DC operation mode to PWM in order to reduce ripple noise */
#if defined(ARDUINO_RASPBERRY_PI_PICO) || defined(ARDUINO_RASPBERRY_PI_PICO_2)
  pinMode(23, OUTPUT);
  digitalWrite(23, HIGH);
#elif defined(ARDUINO_RASPBERRY_PI_PICO_W) || defined(ARDUINO_RASPBERRY_PI_PICO_2W)
  pinMode(LED_BUILTIN + 1, OUTPUT); /* WL_GPIO1 */
  digitalWrite(LED_BUILTIN + 1, HIGH); /* PFM:WL_GPIO1=LOW, PWM:WL_GPIO1=HIGH */
#endif

  /* Setup PWM */
  gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);
  slice_num = pwm_gpio_to_slice_num(PWM_PIN);
  pwm_set_clkdiv_int_frac(slice_num, PWM_CLK_DIV, 0);
  pwm_set_wrap(slice_num, PWM_WRAP);
  pwm_duty = 0;
  pwm_set_chan_level(slice_num, PWM_CHAN_B, pwm_duty); /* (PWM_PIN % 2)==0 ? CHAN_A : CHAN_B */
  pwm_set_enabled(slice_num, true);

  /* Setup ADC */
  adc_init();
  adc_gpio_init(26);  /* A0 = GPIO26 */
  analogReadResolution(12);

  /* Setup USB serial device */
  Serial.begin(USB_SERIAL_BAUD);

  /* Wait for START button */
  while (digitalRead(SW1_PIN) == HIGH) delay(100);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  while (digitalRead(SW1_PIN) == LOW) delay(100);
  delay(1000);

}


/* ------------------------------------------------------------------*/
/* Main Loop                                                         */
void loop() {

  int len, i;
  uint8_t buf[7+(NUM_SAMPLES)*5];
  uint16_t adata[NUM_SAMPLES];
  static bool bLED_ON = true;

  if ( pwm_duty <= PWM_WRAP ) {

    /* Sleep during LPF settling time (80ms) */
    delay(80);

    /* Read ADC for NUM_SAMPLES times at 1ms interval */
    for ( i = 0; i<NUM_SAMPLES; i++ ) {
      adata[i] = analogRead(A0);
      delay(1);
    }

    /* Update PWM duty */
    if ( pwm_duty < PWM_WRAP ) {
      pwm_set_chan_level(slice_num, PWM_CHAN_B, pwm_duty+1);
    } else {
      pwm_set_enabled(slice_num, false);
    }

    len = sprintf((char *)buf, "%5d,%4d,%4d,%4d,%4d,%4d,%4d,%4d,%4d,%4d,%4d\n",
                               pwm_duty,
                               adata[0],
                               adata[1],
                               adata[2],
                               adata[3],
                               adata[4],
                               adata[5],
                               adata[6],
                               adata[7],
                               adata[8],
                               adata[9]
                               );

    /* Write data to communication device */
    usb_serial_write(buf, len);
    if (pwm_duty >= PWM_WRAP) {
      delay(100);
      /* flush serial send buffer */
      usb_serial_write(nullptr, 0);
      Serial.flush();
    }

    pwm_duty++;

  } else {

    if (bLED_ON) {
      digitalWrite(LED_BUILTIN, HIGH);
      bLED_ON = false;
    } else {
      digitalWrite(LED_BUILTIN, LOW);
      bLED_ON = true;
    }

    delay(1000);

  }

}
