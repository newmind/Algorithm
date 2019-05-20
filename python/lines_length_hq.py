# 2170

import sys
import heapq

def line_sweeping_heapq(lines):
  length = 0
  x, y = heapq.heappop(lines)
  while len(lines) > 0:
    x2, y2 = heapq.heappop(lines)
    if x2 > y:
      length += y - x
      x = x2
      y = y2
    elif y2 > y:
      y = y2

  length += y - x
  print(length)
######

if __name__ == "__main__":
  n = int(sys.stdin.readline())
  lines = [[0, 0] for _ in range(n)]
  for i in range(n):
    a, b = map(int, sys.stdin.readline().split())
    lines[i][0] = a
    lines[i][1] = b

  lines = [[1, 3], [2, 5], [3, 5], [6, 7]]
  hq = heapq.heapify(lines)

  line_sweeping_heapq(lines)