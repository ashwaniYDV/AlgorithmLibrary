#!/usr/bin/python3
# -*- coding: utf-8 -*-

n = int(input())
for i in range(n):
    words = tuple(input().split())
    for word in words:
        print(word[0], end='')

    print()
