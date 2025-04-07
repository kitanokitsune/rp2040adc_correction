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
    elif d >= 4070:
        y = d + 16
    elif d >= 3840:
        y = d + 15
    elif d >= 3632:
        y = d + 14
    elif d >= 3328:
        y = d + 13
    elif d >= 3244:
        y = d + 12
    elif d >= 3200:
        y = d + 11
    elif d >= 3152:
        y = d + 12
    elif d >= 2848:
        y = d + 11
    elif d >= 2784:
        y = d + 10
    elif d >= 2560:
        y = d + 9
    elif d >= 2306:
        y = d + 10
    elif d >= 2144:
        y = d + 9
    elif d >= 2048:
        y = d + 8
    elif d >= 1839:
        y = d + 9
    elif d >= 1776:
        y = d + 8
    elif d >= 1536:
        y = d + 7
    elif d >= 1280:
        y = d + 8
    elif d >= 1092:
        y = d + 7
    elif d >= 864:
        y = d + 6
    elif d >= 768:
        y = d + 5
    elif d >= 593:
        y = d + 4
    elif d >= 335:
        y = d + 3
    elif d >= 255:
        y = d + 2
    elif d >= 160:
        y = d + 1
    else:
        y = d

    return y
