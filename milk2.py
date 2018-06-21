# -*- coding: utf-8 -*-
"""
ID: bowen.y1
LANG: PYTHON3
TASK: milk2
"""

import sys
sys.stderr.write('message')

fin = open('milk2.in', 'r')
fout = open('milk2.out', 'w')

n = int(fin.readline())

time = []

for i in range(n):
      time.append([int(x) for x in fin.readline().split()])

time.sort(key=lambda x: x[0])

start = time[0][0]
end  = time[0][1]
cont = end - start

continuous = [end - start]
idle = [0]

for i in range(1, len(time)):
      
      if time[i][0] <= end and time[i][1] >= end:
            cont += time[i][1] - end
            end = time[i][1]
      elif time[i][0] > end:
            continuous.append(cont)
            idle.append(time[i][0] - end)
            start = time[i][0]
            end = time[i][1]
            cont = end - start

fout.write(str(max(continuous)) + ' ' + str(max(idle)) + '\n')
fin.close()
fout.close()