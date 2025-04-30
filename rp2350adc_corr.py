#!/usr/bin/env python
# coding: UTF-8


def rp2350adc_correction(d):
    '''
    rp2350 ADC Correction
      d     : 12 bit ADC readout (0~4095)
      return: corrected ADC value
    '''
    if d >= 4079:
        y = 4095
    elif d >= 3905:
        y = d + 16
    elif d >= 3839:
        y = d + 15
    elif d >= 3489:
        y = d + 14
    elif d >= 3327:
        y = d + 13
    elif d >= 3105:
        y = d + 12
    elif d >= 2816:
        y = d + 11
    elif d >= 2783:
        y = d + 10
    elif d >= 2559:
        y = d + 9
    elif d >= 2304:
        y = d + 10
    elif d >= 2144:
        y = d + 9
    elif d >= 2047:
        y = d + 8
    elif d >= 1824:
        y = d + 9
    elif d >= 1792:
        y = d + 8
    elif d >= 1535:
        y = d + 7
    elif d >= 1280:
        y = d + 8
    elif d >= 1089:
        y = d + 7
    elif d >= 833:
        y = d + 6
    elif d >= 767:
        y = d + 5
    elif d >= 576:
        y = d + 4
    elif d >= 319:
        y = d + 3
    elif d >= 255:
        y = d + 2
    elif d >= 160:
        y = d + 1
    else:
        y = d

    return y
