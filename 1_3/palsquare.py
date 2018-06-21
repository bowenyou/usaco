# -*- coding: utf-8 -*-
"""
ID: bowen.y1
LANG: PYTHON3
TASK: palsquare
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

fin = open('palsquare.in', 'r')
fout = open('palsquare.out', 'w')

B = int(fin.readline().strip())

for i in range(1, 301):
      s = conv_base(i*i, B)
      
      if s == s[::-1]:
            fout.write(conv_base(i, B)[::-1] + ' ' + str(s) + '\n')
