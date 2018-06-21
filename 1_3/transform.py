# -*- coding: utf-8 -*-
"""
ID: bowen.y1
LANG: PYTHON3
TASK: transform
"""

import sys
sys.stderr.write('message')

def rotate(b, N):
      
      nb = [[0 for x in range(N)] for y in range(N)] 
      for r in range(N):
            for c in range(N):
                  nb[c][N-1-r] = b[r][c]
      
      return nb

def reflect(b, N):
      
      nb = [[0 for x in range(N)] for y in range(N)] 
      for r in range(N):
            for c in range(N):
                  nb[r][N-1-c] = b[r][c]
      
      return nb

fin = open('transform.in', 'r')
fout = open('transform.out', 'w')

N = int(fin.readline().strip())

board = []
final = []

for i in range(N):
      board.append(list(fin.readline().strip()))

for i in range(N):
      final.append(list(fin.readline().strip()))

if final == rotate(board, N):
      fout.write(str(1) + '\n')
elif final == rotate(rotate(board, N), N):
      fout.write(str(2) + '\n')
elif final == rotate(rotate(rotate(board, N), N), N):
      fout.write(str(3) + '\n')
elif final == reflect(board, N):
      fout.write(str(4) + '\n')
elif final == rotate(reflect(board, N), N) or \
     final == rotate(rotate(reflect(board, N), N), N) or \
     final == rotate(rotate(rotate(reflect(board, N), N), N), N):
      fout.write(str(5) + '\n')
elif final == board:
      fout.write(str(6) + '\n')
else:
      fout.write(str(7) + '\n')
      
fin.close()
fout.close()
