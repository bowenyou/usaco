# -*- coding: utf-8 -*-
"""
ID: bowen.y1
LANG: PYTHON3
TASK: friday
"""

import sys
sys.stderr.write('message')

fin = open('friday.in', 'r')
fout = open('friday.out', 'w')

N = int(fin.readline().strip())

d = [0] * 7

total = 0

for i in range(1900, 1900+N):
      m = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
      if (i%4 == 0 and i%100 != 0) or (i%400 == 0):
            m[1] += 1
      for j in range(len(m)):
            d[(total + 13)%7] += 1
            total += m[j]

fout.write(' '.join([str(i) for i in d[-1:] + d[:-1]]) + '\n')

fin.close()
fout.close()
