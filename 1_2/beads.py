# -*- coding: utf-8 -*-
"""
ID: bowen.y1
LANG: PYTHON3
TASK: beads
"""

import sys
sys.stderr.write('message')

fin = open('beads.in', 'r')
fout = open('beads.out', 'w')

N = int(fin.readline().strip())
s = fin.readline().strip()

s = s+s

max = 0

for i in range(N):
      current = 0
      c = s[i]
      if c == 'w':
            t = 0
      else:
            t = 1
      j = i
      while t <= 2:
            while j < N+i and (s[j] == c or s[j] == 'w'):
                   current +=  1
                   j += 1
            t += 1
            c = s[j]
      if current > max:
            max = current

fout.write(str(max) + '\n')

fin.close()
fout.close()


