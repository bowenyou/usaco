# -*- coding: utf-8 -*-
"""
ID: bowen.y1
LANG: PYTHON3
TASK: gift1
"""

import sys
sys.stderr.write('message')

fin = open('gift1.in', 'r')
fout = open('gift1.out', 'w')

np = int(fin.readline().strip())

people = dict()
peoplelist = []

for i in range(np):
      s = fin.readline().strip()
      people[s] = 0
      peoplelist.append(s)

for i in range(np):
      s = fin.readline().strip()
      n = [int(x) for x in fin.readline().split()]
      if n[1] != 0:
            people[s] -= n[0]
            for j in range(n[1]):
                  people[fin.readline().strip()] += int(n[0]/n[1])
            people[s] += n[0] % n[1]
      else:
            people[s] += n[0]

for p in peoplelist:
      fout.write(p + ' ' + str(people[p]) + '\n')

fin.close()
fout.close()