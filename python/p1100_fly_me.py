import sys

# 규칙
# https://www.acmicpc.net/problem/1011
# http://blog.naver.com/PostView.nhn?blogId=occidere&logNo=220982644540&categoryNo=0&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView


input = sys.stdin.readline

def f(x, y):
  if (y - x < 3): return y - x
  diff = y-x
  i = 1
  while True:
    Npow2 = i**2
    # [N**2 - N + 1, N**2] <= Npow2 < [N**2 - N + 1, N**2 + N]
    if Npow2 - i + 1 <= diff and diff <= Npow2:
      return i * 2 - 1
    elif Npow2 < diff and diff <= Npow2 + i:
      return i * 2
    i += 1


if __name__ == "__main__":
# 2
# 0 7
# 0 10
# 1
# 0 16

  n = int(input())
  for _ in range(n):
    x, y = map(int, sys.stdin.readline().rstrip().split())
    print(f(x, y))
