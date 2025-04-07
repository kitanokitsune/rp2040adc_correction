#!/usr/bin/env python
# coding: UTF-8

# ---------------------------------------------------------
# import
# ---------------------------------------------------------
import numpy as np
from scipy.stats import trimboth, trim_mean

# ---------------------------------------------------------
# function definition: load csv data and trim edge data
# ---------------------------------------------------------
def load_adc_data(CSVFILE):
    adcdata = [ [] for i in range(4096) ]
    with open(CSVFILE, 'r') as f:
        for sdata in f:
            if not sdata:
                break
            s = sdata.split(',')
            n = int(s[0])/8.0
            l = trimboth( [int(i) for i in s[1:]] , 0.2 )
            for c in l:
                adcdata[c].append(n)
    return adcdata

# ---------------------------------------------------------
# function definition: calculate adc errors in statistics
# ---------------------------------------------------------
def cal_err(data):
    err = []
    for i in range(4096):
        v = data[i]
        if v:
            err.append(trim_mean(v, 0.2)-i)
        else:
            if i:
                err.append(err[i-1])
            else:
                err.append(0.0)
    return err


# ---------------------------------------------------------
# main
# ---------------------------------------------------------

### Set output style
STYLE='PYTHON'             # 'C' or 'PYTHON' (case insensitive)
BOOL_ADJ_OFFSET=False      # True or False

### Read ADC data and calculate average error
adcerr1 = np.array(cal_err(load_adc_data('rp2350adc1.csv')))
adcerr2 = np.array(cal_err(load_adc_data('rp2350adc2.csv')))
adcerr3 = np.array(cal_err(load_adc_data('rp2350adc3.csv')))
adcerr4 = np.array(cal_err(load_adc_data('rp2350adc4.csv')))
adcerr5 = np.array(cal_err(load_adc_data('rp2350adc5.csv')))

adcerr = (adcerr1+adcerr2+adcerr3+adcerr4+adcerr5)/5.0
#adcerr = adcerr5


### Fill dummy data near GND and VCC due to incompletion of OpAMP's output rail
for n in range(25):
    adcerr[n] = adcerr[25]
for n in range(4071, 4096):
    adcerr[n] = adcerr[4070]

### adjust offset: adcerr[25] = 0.0
if BOOL_ADJ_OFFSET:
    d = adcerr[25]
    for n in range(4096):
        adcerr[n] = adcerr[n] - d

### Calculate correction factors: correct_value = adc_readout + correction_factor
v = []
for n in range(4096):
    v.append(min(4095, max(0, int(n + adcerr[n] + 0.5))) - n)

### Output correction factors in C/C++ or PYTHON code format
if STYLE.upper() == 'PYTHON':
    print('# correct_value = adc_readout + rp2350adc_err[adc_readout]')
    print('rp2350adc_err = [')
    for j in range(256):
        s = '    '
        for i in range(16):
            s = s + '{:>3}'.format(v[j*16 + i]) + ','
        s = s + '  # {:>4} - {:>4}'.format(j*16, j*16+15)
        print(s)
    print(']')
elif STYLE.upper() == 'C':
    print('/* correct_value = adc_readout + rp2350adc_err[adc_readout] */')
    print('int8_t rp2350adc_err[] = {')
    for j in range(256):
        s = '    '
        for i in range(16):
            if i==15 and j==255:
                s = s + '{:>3}'.format(v[j*16 + i]) + ' '
            else:
                s = s + '{:>3}'.format(v[j*16 + i]) + ','
        s = s + '  /* {:>4} - {:>4} */'.format(j*16, j*16+15)
        print(s)
    print('};')
