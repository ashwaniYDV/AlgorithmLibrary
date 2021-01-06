#!/usr/bin/python3
# -*- coding: utf-8 -*-

reindeers = ['Dasher', 'Dancer', 'Prancer', 'Vixen', 'Comet', 'Cupid', 'Donner', 'Blitzen', 'Rudolph']
a = []
a = map(int, input().split())
print(reindeers[(sum(a) % 9) - 1])