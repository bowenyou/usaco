# -*- coding: utf-8 -*-
"""
ID: bowen.y1
LANG: PYTHON3
TASK: milk
"""

import sys
sys.stderr.write('message')

fin = open('milk.in', 'r')
fout = open('milk.out', 'w')

N = [int(x) for x in fin.readline().split()]

total = N[0]

farm = []

for i in range(N[1]):
      farm.append([int(x) for x in fin.readline().split()])

farm.sort(key=lambda x: x[0])

price = 0

for i in range(len(farm)):
      if total == 0:
            break
      if total >= farm[i][1]:
            total -= farm[i][1]
            price += farm[i][0] * farm[i][1]
      else:
            price += farm[i][0] * total
            total -= total


fout.write(str(price) + '\n')
      
fin.close()
fout.close()

