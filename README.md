# RP2040 A/D non-linearity correction

The purpose of this project is to improve the non-linearity of the ADC in the RP2040 microcontroller, as described by the errata RP2040-E11, using software.

***Note*** *Lost information cannot be restored. Only improving linearity is possible.*

## RP2040 ADC non-linearity
The following graphs show ADC errors on actual Raspberry Pi Pico/Pico W devices which I possess. (The raw data are [here](./actual_adc_data/data_rp2040/). These data are measured by [*measure.py*](./actual_adc_data/measure.py) with [this firmware](./actual_adc_data/picofirmware) and [this circuit](./actual_adc_data/adc_test_board_schematic.pdf). They are in [./actual_adc_data](./actual_adc_data) folder.)

Y-axis is ADC error and X-axis is ADC readout (***not ADC input***).  
[<img src="./actual_adc_data/data_rp2040/rp2040adc1.png" width="300">](./actual_adc_data/data_rp2040/rp2040adc1.png)
[<img src="./actual_adc_data/data_rp2040/rp2040adc2.png" width="300">](./actual_adc_data/data_rp2040/rp2040adc2.png)
[<img src="./actual_adc_data/data_rp2040/rp2040adc3.png" width="300">](./actual_adc_data/data_rp2040/rp2040adc3.png)
[<img src="./actual_adc_data/data_rp2040/rp2040adc4.png" width="300">](./actual_adc_data/data_rp2040/rp2040adc4.png)
[<img src="./actual_adc_data/data_rp2040/rp2040adc5.png" width="300">](./actual_adc_data/data_rp2040/rp2040adc5.png)  
The enormous discontinuities are observed at 512, 1536, 2560 and 3584.

## General-Purpose Correction Code
By averaging the errors of the above five devices, I obtained the following code.
```Python
def rp2040adc_correction(d):
    '''
    rp2040 ADC Correction
      d     : 12 bit ADC readout (0~4095)
      return: corrected ADC value
    '''
    if d >= 4082:
        y = 4095
    elif d >= 4022:
        y = d + 13
    elif d >= 3711:
        y = d + 14
    elif d >= 3584:
        y = d + 15
    elif d == 3583:
        y = 3583 + 10
    elif d >= 3454:
        y = d + 5
    elif d >= 2943:
        y = d + 6
    elif d >= 2560:
        y = d + 7
    elif d == 2559:
        y = 2559 + 2
    elif d >= 2431:
        y = d - 2
    elif d >= 2048:
        y = d - 1
    elif d == 2047:
        y = 2047 + 0
    elif d >= 1664:
        y = d + 1
    elif d >= 1536:
        y = d + 2
    elif d == 1535:
        y = 1535 - 3
    elif d >= 1407:
        y = d - 7
    elif d >= 895:
        y = d - 6
    elif d >= 512:
        y = d - 5
    elif d == 511:
        y = 511 - 10
    elif d >= 16:
        y = d - 15
    else:
        y = 0

    return y
```
### Correction result by the general-purpose code
Y-axis is ADC error and X-axis is ADC input (***not ADC readout***).  
[<img src="./images/Figure_1.png" width="300">](./images/Figure_1.png)
[<img src="./images/Figure_2.png" width="300">](./images/Figure_2.png)
[<img src="./images/Figure_3.png" width="300">](./images/Figure_3.png)
[<img src="./images/Figure_4.png" width="300">](./images/Figure_4.png)
[<img src="./images/Figure_5.png" width="300">](./images/Figure_5.png)  
The red line shows the error with correction, and the cyan line shows the error without correction.

## Better Correction by Individual Code
If you can use individual code for each device, that means each device has its own customized firmware, you can use the following formula that gives better correction:

`ADC_CORRECTED = ADC_READOUT + rp2040adc_err[ADC_READOUT]`

Where `rp2040adc_err[]` is the array created by [*calc_err.py*](./actual_adc_data/data_rp2040), and has error data for specific device measured by yourself using [*measure.py*](./actual_adc_data). (Each device needs its own `rp2040adc_err[]`.)
### Correction result by individual code
Y-axis is ADC error and X-axis is ADC input (***not ADC readout***).  
[<img src="./images/Figure_6.png" width="300">](./images/Figure_6.png)
[<img src="./images/Figure_7.png" width="300">](./images/Figure_7.png)
[<img src="./images/Figure_8.png" width="300">](./images/Figure_8.png)
[<img src="./images/Figure_9.png" width="300">](./images/Figure_9.png)
[<img src="./images/Figure_a.png" width="300">](./images/Figure_a.png)  
The red line shows the error with correction, and the cyan line shows the error without correction.
