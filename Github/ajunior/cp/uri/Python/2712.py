#!/usr/bin/python3
import re

i = int(input())
for x in range(i):
    placa = input()
    if not re.match(r'[A-Z]{3}-\d{4}$', placa, flags=0): print('FAILURE')
    else:
        if placa.endswith(('1', '2')): print('MONDAY')
        if placa.endswith(('3', '4')): print('TUESDAY')
        if placa.endswith(('5', '6')): print('WEDNESDAY')
        if placa.endswith(('7', '8')): print('THURSDAY')
        if placa.endswith(('9', '0')): print('FRIDAY')