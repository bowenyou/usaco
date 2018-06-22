# -*- coding: utf-8 -*-
"""
ID: bowen.y1
LANG: PYTHON3
TASK: barn1
"""

import sys
sys.stderr.write('message')

fin = open('barn1.in', 'r')
fout = open('barn1.out', 'w')

N = [int(x) for x in fin.readline().split()]

m = N[0]
s = N[1]
c = N[2]

occ = [0]*s

for i in range(c):
      occ[int(fin.readline().strip())-1] = 1

lo = 0
hi = len(occ)-1
while occ[lo] != 1:
      lo += 1
while occ[hi] != 1:
      hi -= 1

gap = []
t = lo

while t < hi:
      while occ[t] == 1 and t < hi:
            t += 1
      j = t
      while occ[j] != 1 and j < hi:
            j += 1
      gap.append(j-t)
      t = j

gap.sort()
gap = gap[::-1]

n = 0
for i in range(m-1):
      if i >= len(gap):
            break
      n += gap[i]


fout.write(str(hi-lo-n+1) + '\n')
      
fin.close()
fout.close()