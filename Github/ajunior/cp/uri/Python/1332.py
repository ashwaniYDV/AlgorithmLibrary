#!/usr/bin/python3
# -*- coding: utf-8 -*-

n = int(input())
for i in range(n):
    number = input()
    if len(number) > 3: print(3)
    elif number[0] == 'o' and number[1] == 'n' or \
         number[1] == 'n' and number[2] == 'e' or \
         number[0] == 'o' and number[2] == 'e': print(1)
    else: print(2)
