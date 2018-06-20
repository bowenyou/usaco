# -*- coding: utf-8 -*-
"""
ID: bowen.y1
LANG: PYTHON3
TASK: ride
"""

import sys
sys.stderr.write('message')

fin = open('ride.in', 'r')
fout = open('ride.out', 'w')

a = fin.readline().strip()
b = fin.readline().strip()

va = 1
vb = 1

for l in a:
      va *= ord(l) - ord('A') + 1

for l in b:
      vb *= ord(l) - ord('A') + 1
      
if va%47 == vb%47:
      fout.write('GO\n')
else:
      fout.write('STAY\n')

fin.close()
fout.close()
