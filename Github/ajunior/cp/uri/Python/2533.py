#!/usr/bin/python3
# -*- coding: utf-8 -*-

while True:
    try:
        grades_total = 0
        workloads_total = 0

        m = int(input())
        for i in range(m):
            n, c = map(int, input().split())
            grades_total += n * c
            workloads_total += c

        print('%.4f' %(grades_total / (workloads_total * 100)))
    except:
        break
