# 2170

import sys
import queue

def line_sweeping(lines : queue):
  length = 0
  x, y = lines.get()
  while not lines.empty():
    x2, y2 = lines.get()
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
  # n = int(input())
  lines = queue.PriorityQueue(maxsize=n)
  # while n > 0:
  #   a, b = map(int, sys.stdin.readline().split())
  #   lines.put([a, b])
  #   n -= 1

  arr = [[1, 3], [-2, 5], [3, 5], [6, 7]]
  for x in arr:
    lines.put(x)

  line_sweeping(lines)