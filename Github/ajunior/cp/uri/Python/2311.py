#!/usr/bin/python3
# -*- coding: utf-8 -*-

n = int(input())
for i in range(n):
    diver = input()
    difficulty = float(input())
    scores = [float(x) for x in input().split()]
    scores.remove(max(scores))
    scores.remove(min(scores))
    print('%s %.2f' %(diver, sum(scores) * difficulty))
