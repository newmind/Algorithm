# 2170

import sys

def line_sweeping_list(lines : list):
  lines.sort()
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
#   n = int(sys.stdin.readline())
#   arr = [sys.stdin.readline().rstrip() for i in range(n)]

#   lines = [[0, 0] for _ in range(n)]

#   for i in range(n):
#     a, b = arr[i].split()
#     lines[i][0] = int(a)
#     lines[i][1] = int(b)

  import random
  lines = [[random.randint(0, 1000), random.randint(1001, 2000)] for _ in range(1000000)]

  line_sweeping_list(lines)