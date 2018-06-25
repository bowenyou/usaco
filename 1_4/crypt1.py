# -*- coding: utf-8 -*-
"""
ID: bowen.y1
LANG: PYTHON3
TASK: crypt1
"""

import sys
sys.stderr.write('message')

def check_d(a, b):
      if a == 0:
            return 0
      while a > 0:
            if d[a%10] != 1:
                  return 0
            a = int(a/10)
            b -= 1
      if b == 0:
            return 1
      else:
            return 0

def check_p(a, b):
      if check_d(a, 3) == 0 or check_d(b, 2) == 0 or check_d(a*b, 4) == 0:
            return 0
      while b > 0:
            if check_d(a * (b%10), 3) == 0:
                  return 0
            b = int(b/10)
      return 1


fin = open('crypt1.in', 'r')
fout = open('crypt1.out', 'w')

N = int(fin.readline().strip())
d = [0] * 10

for x in fin.readline().split():
      d[int(x)] = 1

count = 0

for i in range(100, 1000):
      for j in range(10, 100):
            if check_p(i, j) == 1:
                  count += 1




fout.write(str(count) + '\n')
      
fin.close()
fout.close()

