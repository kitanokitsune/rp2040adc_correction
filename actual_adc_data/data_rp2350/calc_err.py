#!/usr/bin/env python
# coding: UTF-8

# ---------------------------------------------------------
# Define Chip Name
# ---------------------------------------------------------
#CHIP='rp2350'             # 'rp2040' or 'rp2350'. autodetect if commented out



# ---------------------------------------------------------
# import
# ---------------------------------------------------------
import sys
import os.path
import glob
from scipy.stats import trimboth, trim_mean


# ---------------------------------------------------------
# function definition: ishex
# ---------------------------------------------------------
def ishex(s):
    try:
        int(s, 16)
    except ValueError:
        ret = False
    else:
        ret = True
    return ret



# ---------------------------------------------------------
# function definition: load csv data and trim edge data
# ---------------------------------------------------------
def load_adc_data(CSVFILE):
    adcdata = [ [] for i in range(4096) ]
    pico_id = ''
    with open(CSVFILE, 'r') as f:
        for sdata in f:
            sdata = sdata.strip()
            if not sdata:
                continue
            if sdata.startswith('#'):
                pico_id = sdata[1:].strip()
            else:
                s = sdata.split(',')
                n = int(s[0])/8.0
                l = trimboth( [int(i) for i in s[1:]] , 0.1 )
                for c in l:
                    adcdata[c].append(n)
    return pico_id, adcdata


# ---------------------------------------------------------
# main
# ---------------------------------------------------------

argv = sys.argv
argc = len(argv) - 1
if argc > 0 and os.path.isdir(argv[1]):
    folder = argv[1]
    filelist = glob.glob(os.path.normpath(os.path.join(folder, '*.csv')))
elif argc > 0 and os.path.isfile(argv[1]):
    folder = os.path.dirname(argv[1])
    filelist = [ os.path.normpath(argv[1]) ]
else:
    sys.stderr.write('Usage: {} CSVFILE|DATAFOLDER [-c] [-p]\n'.format(argv[0]))
    sys.stderr.write('Options:\n')
    sys.stderr.write('  -c      Write calibration data to C/C++ header file\n')
    sys.stderr.write('  -p      Write calibration data to Python script file\n')
    sys.exit(1)

if not filelist:
    sys.stderr.write('Error: No CSV file found in {}\n'.format(folder))
    sys.exit(1)



sys.stderr.write('-------- List CSV file(s)\n')
for s in filelist:
    sys.stderr.write('  {}\n'.format(s))



sys.stderr.write('-------- Read CSV file(s)\n')
rawdata = [ [] for n in range(4096) ]
pico_id = ''
for f in filelist:
    i, d = load_adc_data(f)
    if pico_id == '':
        pico_id = i
    elif pico_id != i:
        sys.stderr.write('*ID ERR*\n')
        sys.exit(0)
    for n in range(4096):
        rawdata[n].extend(d[n])

x = []
adcerr = [ [] for n in range(4096) ]
for n in range(4096):
    if rawdata[n]:
        v = trimboth( rawdata[n] , 0.05 )
        x.append(n)
        adcerr[n] = [trim_mean(v, 0.05) - n, max(v) - n, min(v) - n]
sys.stderr.write('  Num of Valid Points = {}\n'.format(len(x)))
sys.stderr.write('  Valid Range = [{},{}]\n'.format(min(x), max(x)))



sys.stderr.write('-------- Info\n')

try:
    CHIP
except NameError:
    if len(pico_id) == 16 and ishex(pico_id):
        if pico_id.startswith('E6'):
            CHIP = 'rp2040'
        else:
            CHIP = 'rp2350'
    else:
        CHIP = ''

sys.stderr.write('  BOARD ID   : {}\n'.format(pico_id))
sys.stderr.write('  CHIP NAME  : {}\n'.format(CHIP))



sys.stderr.write('-------- Interpolation\n')
n = 0
if not 0 in x:
    sys.stderr.write('  Missing data: x = [{:4d}, '.format(0))
    while not n in x:
        n = n + 1
        if n > 4095:
            sys.stderr.write('\nNo valid data\n')
            sys.exit(1)
    sys.stderr.write('{:4d}]\n'.format(n-1))
    for k in range(n):
        adcerr[k] = adcerr[n]

while True:
    while n in x:
        n = n + 1
        if n > 4095:
            break
    if n > 4095:
        break
    sys.stderr.write('  Missing data: x = [{:4d}, '.format(n))
    st = n - 1
    while not n in x:
        n = n + 1
        if n > 4095:
            break
    if n > 4095:
        sys.stderr.write('{:4d}]\n'.format(n-1))
        for k in range(st + 1, 4096):
            adcerr[k] = adcerr[st]
    else:
        sys.stderr.write('{:4d}]\n'.format(n-1))
        stepave = (adcerr[n][0] - adcerr[st][0]) / (n - st)
        stepmax = (adcerr[n][1] - adcerr[st][1]) / (n - st)
        stepmin = (adcerr[n][2] - adcerr[st][2]) / (n - st)
        for k in range(st + 1, n):
            v = [ adcerr[st][0] + stepave*(k-st),
                  adcerr[st][1] + stepmax*(k-st),
                  adcerr[st][2] + stepmin*(k-st) ]
            adcerr[k] = v



sys.stderr.write('-------- Calc ADC errors\n')
adcerrave = [ 0.0 for n in range(4096) ]
adcerrmax = [ 0.0 for n in range(4096) ]
adcerrmin = [ 0.0 for n in range(4096) ]

for k in range(4096):
    adcerrave[k] = adcerr[k][0]
    adcerrmax[k] = adcerr[k][1]
    adcerrmin[k] = adcerr[k][2]

sys.stderr.write('  Err Max: {}\n'.format(max(adcerrmax)))
sys.stderr.write('  Err Min: {}\n'.format(min(adcerrmin)))

v = []
for n in range(4096):
    v.append(min(4095, max(0, int(n + adcerrave[n] + 0.5))) - n)



if argc > 1 and '-p' in argv[2:]:
    sys.stderr.write('-------- Write to Python script file\n')
    FNAME = CHIP+'adc'
    if pico_id:
        FNAME = FNAME + '_' + pico_id
    FNAME = FNAME + '.py'
    FNAME = os.path.normpath(os.path.join(folder, FNAME))
    sys.stderr.write('  {}\n'.format(FNAME))
    with open(FNAME, 'w') as f:
        f.write('''# {} adc correction: Individual Python Code Template

#-----------------------------------------------------------------------------------\n'''.format(CHIP))
        if pico_id:
            f.write('# {}\n\n'.format(pico_id))
        else:
            f.write('# Replace the below {}adc_err[] with your own data\n\n'.format(CHIP))
        f.write(CHIP+'adc_err = [\n')
        for j in range(256):
            s = '    '
            for i in range(16):
                s = s + '{:>3}'.format(v[j*16 + i]) + ','
            s = s + '  # {:>4} - {:>4}'.format(j*16, j*16+15)
            f.write('{}\n'.format(s))
        f.write(']\n\n')
        f.write('''#-----------------------------------------------------------------------------------

def {}adc_correction(d):
    return (d + {}adc_err[d])\n'''.format(CHIP, CHIP))

if argc > 1 and '-c' in argv[2:]:
    sys.stderr.write('-------- Write to C/C++ header file\n')
    FNAME = CHIP+'adc'
    if pico_id:
        FNAME = FNAME + '_' + pico_id
    FNAME = FNAME + '.h'
    FNAME = os.path.normpath(os.path.join(folder, FNAME))
    sys.stderr.write('  {}\n'.format(FNAME))
    with open(FNAME, 'w') as f:
        f.write(
            '''/* {} adc correction: Individual C/C++ Code Template */

/*----------------------------------------------------------------------------------*/\n'''.format(CHIP))
        if pico_id:
            f.write('/* {}                                                                 */\n\n'.format(pico_id))
        else:
            f.write('/* Replace the below {}adc_err[] with your own data                             */\n\n'.format(CHIP))
        f.write('int8_t '+CHIP+'adc_err[] = {\n')
        for j in range(256):
            s = '    '
            for i in range(16):
                if i==15 and j==255:
                    s = s + '{:>3}'.format(v[j*16 + i]) + ' '
                else:
                    s = s + '{:>3}'.format(v[j*16 + i]) + ','
            s = s + ' /* {:>4} - {:>4} */'.format(j*16, j*16+15)
            f.write('{}\n'.format(s))
        f.write('};\n\n')
        f.write(
            '''/*----------------------------------------------------------------------------------*/

inline uint16_t {}adc_correction(uint16_t d)\n'''.format(CHIP))
        f.write('{\n')
        f.write('    return (d + {}adc_err[d]);\n'.format(CHIP))
        f.write('};\n')
