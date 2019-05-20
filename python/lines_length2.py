# 2170

import sys
import queue

def line_sweeping(lines):
  length = 0
  x, y = lines[0]
  for i in range(1, len(lines)):
    x2, y2 = lines[i]
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
  n = int(input())
  # lines = queue.PriorityQueue(maxsize=n)
  lines = [[0, 0] for _ in range(n)]
  for i in range(n):
    a, b = map(int, sys.stdin.readline().split())
    lines[i][0] = a
    lines[i][1] = b
    # n -= 1

  lines.sort()

  # arr = [[1, 3], [-2, 5], [3, 5], [6, 7]]
  # for x in arr:
  #   lines.put(x)

  line_sweeping(lines)