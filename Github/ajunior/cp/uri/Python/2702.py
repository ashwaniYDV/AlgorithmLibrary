#!/usr/bin/python3
# -*- coding: utf-8 -*-

ca, ba, pa = map(int, input().split())
cr, br, pr = map(int, input().split())

t = 0

if ca < cr : t += cr - ca
if ba < br : t += br - ba
if pa < pr : t += pr - pa

print(t)
