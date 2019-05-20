# 2170

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
  lines = []
  n = int(input())
  while n > 0:
    a, b = map(int, input().split())
    lines.append([a, b])
    n -= 1

  # lines = [[1, 3], [2, 5], [3, 5], [6, 7]]
  lines.sort()
  line_sweeping(lines)