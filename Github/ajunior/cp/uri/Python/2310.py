#!/usr/bin/python3
# -*- coding: utf-8 -*-

saq_t, blq_t, atq_t, saq_r, blq_r, atq_r = 0, 0, 0, 0, 0, 0

n = int(input())
for i in range(n):
    input()

    # Tentativas
    x, y, z = map(int, input().split())
    saq_t += x
    blq_t += y
    atq_t += z

    # Realizados
    x, y, z = map(int, input().split())
    saq_r += x
    blq_r += y
    atq_r += z

print('Pontos de Saque: %.2f %%.' %((saq_r / saq_t) * 100))
print('Pontos de Bloqueio: %.2f %%.' %((blq_r / blq_t) * 100))
print('Pontos de Ataque: %.2f %%.' %((atq_r / atq_t) * 100))