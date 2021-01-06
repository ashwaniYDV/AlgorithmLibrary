#!/usr/bin/python3
# -*- coding: utf-8 -*-

food_table = {'suco de laranja': 120,
              'morango fresco': 85,
              'mamao': 85,
              'goiaba vermelha': 70,
              'manga': 56,
              'laranja': 50,
              'brocolis': 34}

while True:
    t = int(input())
    if t is 0: break
    else:
        vitamin_c = 0
        for i in range(t):
            inp =[]
            inp = input().split()
            n = int(inp[0])
            f = ' '.join(inp[1:])
            vitamin_c += n * food_table[f]

        if vitamin_c > 130:
            print('Menos', vitamin_c - 130, 'mg')
        elif vitamin_c < 110:
            print('Mais', 110 - vitamin_c, 'mg')
        else:
            print(vitamin_c, 'mg')




