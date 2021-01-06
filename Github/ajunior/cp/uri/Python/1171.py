#!/usr/bin/python3
# -*- coding: utf-8 -*-

import operator

numbers = []

n = int(input())
for i in range(n):
    numbers.append(input())

d = {int(x):numbers.count(x) for x in numbers}

for k, v in sorted(d.items()):
     print(k, 'aparece', v, 'vez(es)')
