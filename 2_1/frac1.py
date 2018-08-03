# -*- coding: utf-8 -*-
"""
ID: bowen.y1
LANG: PYTHON3
TASK: frac1
"""

import sys
sys.stderr.write('message')

fin = open('frac1.in', 'r')
fout = open('frac1.out', 'w')

N = int(fin.readline().strip())

def solve(n1, d1, n2, d2):
      
      if (d1 + d2 > N):
            return;
      
      solve(n1, d1, n1+n2, d1+d2)
      fout.write(str(n1+n2) + '/' + str(d1+d2) + '\n')
      solve(n1+n2, d1+d2, n2, d2)
      
fout.write('0/1\n')
solve(0, 1, 1, 1)
fout.write('1/1\n')
      
fin.close()
fout.close()