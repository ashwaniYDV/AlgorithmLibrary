#!/usr/bin/python3
# -*- coding: utf-8 -*-

while True:
    try:
        n, a_min, a_max = map(int, input().split())
        guests = []
        for i in range(n):
            g = int(input())
            if g >= a_min and g <= a_max: guests.append(g)

        print(len(guests))
    except:
        break
