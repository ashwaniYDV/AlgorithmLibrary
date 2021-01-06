#!/usr/bin/python3
# -*- coding: utf-8 -*-

while True:
    try:
        n = int(input())
        votes = [int(x) for x in input().split()]
        if sum(votes) >= (n / 3) * 2: print('impeachment')
        else: print('acusacao arquivada')
    except:
        break
