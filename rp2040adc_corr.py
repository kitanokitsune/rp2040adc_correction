#!/usr/bin/env python
# coding: UTF-8


def rp2040adc_correction(d):
    '''
    rp2040 ADC Correction
      d     : 12 bit ADC readout (0~4095)
      return: corrected ADC value
    '''
    if d >= 4081:
        y = 4095
    elif d >= 3711:
        y = d + 14
    elif d >= 3584:
        y = d + 15
    elif d == 3583:
        y = 3583 + 10
    elif d >= 3455:
        y = d + 5
    elif d >= 2943:
        y = d + 6
    elif d >= 2560:
        y = d + 7
    elif d == 2559:
        y = 2559 + 3
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
