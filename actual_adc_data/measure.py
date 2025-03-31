#!/usr/bin/env python
# coding: UTF-8

'''
Receive ADC data from Raspberry Pi Pico by USB serial, and write it to a csv file.

(1) Mount a Raspberry Pi Pico/W/2/2W device to ADC test board.
(2) Connect the Pico device to Host-PC by USB.
(3) Open "picofirmware.ino" with Arduino-IDE on the Host-PC.
(4) Compile the firmware and download it to the device.
(5) Run this python program on the Host-PC, then push START button (SW1) on the test board.
(6) Wait until the program finishes. (It takes about 50 minutes).
'''

# ---------------------------------------------------------
# Specify parameters if need.
# ---------------------------------------------------------
#COM='COM5'         # default: Autodetect Pico USB Serial
#BAUD=115200        # default: 115200
#OUTFILE='_a.csv'   # default: '_a.csv'

# ---------------------------------------------------------
# import
# ---------------------------------------------------------
import serial
from serial.tools import list_ports
from time import time
from sys import exit

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

try:
    OUTFILE
except NameError:
    OUTFILE='_a.csv'

# ---------------------------------------------------------
# Open Serial Port
# ---------------------------------------------------------
print('Open serial devide {} at baud rate {}bps'.format(COM, BAUD))
uart = serial.Serial(port=COM, baudrate=BAUD, timeout=60)

tstart = time()
# ---------------------------------------------------------
# Read from a Pico & Write to a file
# ---------------------------------------------------------
with open(OUTFILE, 'w') as f:
    while True:
        data = uart.readline().decode()
        if not data:
            break
        l = [ int(x) for x in data.split(',') ]
        i = l[0]
        f.write(data)
        print(i)

uart.close()

# Show elapsed time
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
