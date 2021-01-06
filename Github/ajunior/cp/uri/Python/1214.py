#!/usr/bin/python3
# -*- coding: utf-8 -*-

n = int(input())
for i in range(n):
    avg = 0
    above = 0
    v = list(input().split())
    for i in v[1:]:
        avg += int(i)

    avg = round(avg / int(v[0]), 3)

    for i in v[1:]:
        if int(i) > avg: above += 1

    print('%.3f%%' %(above / int(v[0]) * 100))
