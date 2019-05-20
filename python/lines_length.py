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

if __name__ == "__main__":
#   n = int(sys.stdin.readline())
#   arr = [sys.stdin.readline().rstrip() for i in range(n)]

#   lines = [[0, 0] for _ in range(n)]

#   for i in range(n):
#     a, b = arr[i].split()
#     lines[i][0] = int(a)
#     lines[i][1] = int(b)

  # 위의 미리 할당보다, 라인읽어서 바로 split map 이 빠름. append도 빠르네
  n = int(sys.stdin.readline())
  lines = []
  for i in range(n):
    a, b = map(int, sys.stdin.readline().rstrip().split())
    lines.append((a, b))

  line_sweeping_list(lines)