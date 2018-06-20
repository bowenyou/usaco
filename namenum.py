# -*- coding: utf-8 -*-
"""
ID: bowen.y1
LANG: PYTHON3
TASK: namenum
"""

import sys
sys.stderr.write('message')

fin = open('namenum.in', 'r')
fin2 = open('dict.txt', 'r')
fout = open('namenum.out', 'w')

s = fin.readline().strip()
d = [l.strip() for l in fin2.readlines()]

map = {'A': '2', 'B': '2', 'C': '2',
       'D': '3', 'E': '3', 'F': '3',
       'G': '4', 'H': '4', 'I': '4',
       'J': '5', 'K': '5', 'L': '5',
       'M': '6', 'N': '6', 'O': '6',
       'P': '7', 'R': '7', 'S': '7',
       'T': '8', 'U': '8', 'V': '8',
       'W': '9', 'X': '9', 'Y': '9',
       'Q': '-1', 'Z': '-1'}

m = []

for n in d:
      temp = list(n)
      for i in range(len(temp)):
            temp[i] = map[n[i]]
      temp = ''.join(temp)
      m.append(temp)

count = 0

for i in range(len(m)):
      if s == m[i]:
         count += 1
         fout.write(d[i] + '\n')

if count == 0:
      fout.write('NONE\n')

fin.close()
fin2.close()
fout.close()
