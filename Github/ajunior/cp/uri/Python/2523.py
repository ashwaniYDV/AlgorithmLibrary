#!/usr/bin/python3
# -*- coding: utf-8 -*-

while True:
    try:
        alphabet = input()
        input()
        for i in input().split():
            print(alphabet[int(i) - 1], end='')
        print()
    except:
        break
