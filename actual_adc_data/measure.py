#!/usr/bin/env python
# coding: UTF-8

# ---------------------------------------------------------
# Specify parameters if need.
# ---------------------------------------------------------
#COM='COM5'         # default: Autodetect Pico USB Serial
#BAUD=115200        # default: 115200
#OUTFILE='_a.csv'   # default: auto numbering

# ---------------------------------------------------------
# import
# ---------------------------------------------------------
import serial
from serial.tools import list_ports
from time import time, sleep
from sys import exit, stderr, argv
argc = len(argv)-1
import os.path
import os


# ---------------------------------------------------------
# Print Usage
# ---------------------------------------------------------
def printusage(pname):
    stderr.write('=== Host program to measure ADC errors on Raspberry Pi Pico/W/2/2W board ===\n'.format(pname))
    stderr.write('(https://github.com/kitanokitsune/rp2040adc_correction)\n')
    stderr.write('Usage: [python] {} FOLDER [-r]\n'.format(pname))
    stderr.write('Options:\n')
    stderr.write('    FOLDER  Path to a folder where ADC data are saved.\n')
    stderr.write('            The folder must exist. ("." is acceptable)\n')
    stderr.write('    -r      Decremental input (default=incremental)\n')


# ---------------------------------------------------------
# Check arguments
# ---------------------------------------------------------
if argc < 1:
    printusage(argv[0])
    exit(1)

folder = os.path.normpath(argv[1])

if not os.path.isdir(folder):
    stderr.write('Error! "{}" is not existing folder!\n\n'.format(argv[1]))
    printusage(argv[0])
    exit(1)

is_reverse = False
if argc > 1:
    if argv[2] == '-r':
        is_reverse = True

# ---------------------------------------------------------
# Autodetect Pi Pico USB devide
# ---------------------------------------------------------
try:
    COM
except NameError:
    COM=None
if not COM:
    print('Autodetect...')
    ports = list_ports.comports()
    for p in ports:
        if p.vid == 0x2e8a:  # Raspberry Pi Pico USB Vendor ID:2E8A
            COM=p.device
            break
    if not COM:
        print('Error: Raspberry Pi Pico USB serial port is not present.')
        exit(1)

try:
    BAUD
except NameError:
    BAUD=115200

# ---------------------------------------------------------
# Open Serial Port
# ---------------------------------------------------------
print('Open serial devide {} at baud rate {}bps'.format(COM, BAUD))
uart = serial.Serial(port=COM, baudrate=BAUD, timeout=60)

tstart = time()
# ---------------------------------------------------------
# Read from a Pico & Write to a file
# ---------------------------------------------------------
uart.write('n\n'.encode())
SN = uart.readline().decode().strip()

try:
    OUTFILE
except NameError:
    folder = os.path.normpath(os.path.join(folder, SN))
    if os.path.isdir(folder):
        OUTFILE = ''
        for n in range(1,100):
            s = os.path.normpath(os.path.join(folder, '{}.csv'.format(n)))
            if not os.path.exists(s):
                OUTFILE = s
                break
        if not OUTFILE:
            stderr.write('Error: exceed maximum number of files\n')
            uart.close()
            exit(1)
    elif not os.path.exists(folder):
        os.makedirs(folder)
        OUTFILE = os.path.normpath(os.path.join(folder, '1.csv'))
    else:
        OUTFILE = '_a.csv'

uart.write('l 1\n'.encode())
dummy = uart.readline()

if is_reverse:
    pwm_duties = [ k for k in range(32767, -1, -1) ]
else:
    pwm_duties = [ k for k in range(32768) ]
uart.write('p {}\n'.format(pwm_duties[0]).encode())
sleep(1.0)
dummy = uart.readline()


with open(OUTFILE, 'w') as f:
    f.write('# {}\n'.format(SN))
    for duty in pwm_duties:
        uart.write('p {}\n'.format(duty).encode())
        dummy = uart.readline()
        sleep(0.045) # wait for LPF settling time
        f.write('{:5d},'.format(duty))
        uart.write('a 12\n'.encode())
        f.write((uart.readline().decode()))
        stderr.write('{:5d}\n'.format(duty))

uart.write('l 0\n'.encode())
dummy = uart.readline()
uart.close()
stderr.write('----------------------------------------\n')
stderr.write(' {}\n'.format(OUTFILE))
stderr.write('----------------------------------------\n')

elapsed = int(time() - tstart + 0.5)
h = int(elapsed / 3600.0)
m = int((elapsed % 3600) / 60.0)
s = elapsed % 60
t = '{}s'.format(s)
if h>0 or m>0:
    t = '{}m'.format(m) + t
if h>0:
    t = '{}h'.format(h) + t
print('elapsed time: {}.'.format(t))
