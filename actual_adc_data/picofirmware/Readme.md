# About this Firmware
A Raspberry Pi Pico/W/2/2W firmware intended for measuring ADC error with [this circuit](../adc_test_board_schematic.pdf).  
If you send a command via the USB-SERIAL (UART), then you will receive its response via the USB-SERIAL.

## Command List
Command names are case sensitive.  
Leading spaces are ignored.
Trailing spaces are ignored except **commit** command.

| Command | Description |
| :---| :---         |
| __n__     | Returns the unique ID of the Pico board (16-digit hexadecimal like D375E05FEA5ACEA5). |
| __l__ __1__   | Turns on the built-in LED, then returns "LED On". |
| __l__ __0__   | Turns off the built-in LED, then returns "LED Off". |
| __p__ *N*   | Sets the PWM duty to *N* (*N* = 0-32767 for decimals), then returns "Set PWM position:*N*". |
| __a__     | Returns an ADC readout value (the decimal number 0-4096). |
| __A__     | It behaves the same as command "__a__" but returns a value calibrated using the value of EEPROM. It returns "nop" before command "__b__" is executed. |
| __a__ *N*   | Reads values of ADC readout in *N* times (*N*=1-12) at intervals of 65us, then returns them with comma separated format (such as "*dddd*, *dddd*, *dddd*", etc.) When *N*<2, reads a value once and returns it ("*dddd*"). |
| __A__ *N*   | It behaves the same as command "__a__ *N*" but returns values calibrated using the values of EEPROM. It returns "nop" before  command "__b__" is executed. |
| __b__     | Begins EEPROM emulation (copying the content of the last 4kB of the flash ROM to the EEPROM emulation buffer). This command always returns "EEPROM Emulation started!"
| __r__ *N*   | Returns the value (decimal 0-255) stored in the EEPROM emulation buffer at address *N* (decimal N=0-4095). It returns "nop" before command "__b__" is executed. |
| __w__ *N,M* | Writes a value *M* (decimal 0-255) to the EEPROM emulation buffer at address *N* (decimal N=0-4095), then returns "EEPROM[*N*]=*M*". If the EEPROM emulation is not started (*i.e.* before command "__b__"), returns "nop" and does nothing. |
| __commit__| Updates the last 4kB of the flash ROM with the content of the EEPROM emulation buffer, then returns "EEPROM commit!". If the EEPROM emulation is not started (*i.e.* before command "__b__"), returns "nop" and does nothing. |

If you enter a command other than the above, "unknown command" is returned.


