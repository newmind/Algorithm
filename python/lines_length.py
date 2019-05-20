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
# import sys
# input=sys.stdin.readline
# p=[]
# N=int(input())
# for _ in range(N):
# 	a,b=map(int,input().split())
# 	if a>b:a,b=b,a
# 	p.append((a,b))
# p.sort();L=0;s,e=p[0]
# for i in range(1,N):
# 	n,m=p[i]
# 	if e<n:L+=e-s;s,e=n,m
# 	elif e<m:e=m
# print(L+e-s)


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

  # import random
  # lines = [[random.randint(0, 1000), random.randint(1001, 2000)] for _ in range(1000000)]

  line_sweeping_list(lines)