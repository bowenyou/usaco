# -*- coding: utf-8 -*-
"""
ID: bowen.y1
LANG: PYTHON3
TASK: dualpal
"""

import sys
sys.stderr.write('message')

digits = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'

def conv_base(a, b):
      
      s = ''
      while a > 0:
            s += digits[a%b]
            a = int(a/b)
      
      return s

fin = open('dualpal.in', 'r')
fout = open('dualpal.out', 'w')

N = [int(x) for x in fin.readline().split()]

S = N[1] + 1

n = 0

while n < N[0]:
      npal = 0
      for i in range(2, 11):
            temp = conv_base(S, i)
            if temp == temp[::-1]:
                  npal += 1
            if npal >= 2:
                  n += 1
                  fout.write(str(S) + '\n')
                  break
      S += 1
      
fin.close()
fout.close()
