import sys

# 피보나치 6
#  boj.kr/11444
#  행렬곱셈 또는
#  홀수 번째와 짝수 번째 피보나치수를 모두 더 작은 피보나치 수의 합 또는 곱을 이용해서 구할 수 있습니다.
# https://www.acmicpc.net/blog/view/28

input = sys.stdin.readline

def fibo(n):
  if n < 2:
    return n
  fib_2 = 0
  fib_1 = 1
  for i in range(2, n+1):
    fib_1 = fib_2 + fib_1
    fib_2 = fib_1 - fib_2
  return fib_1

d = {}
def fast_fibo(n):
  if n <= 0:
    return 0
  elif n == 1:
    return 1
  elif n == 2:
    return 1
  elif n in d:
    return d[n]
  else:
    if n%2 == 1:
      m = (n+1) / 2
      t1 = fast_fibo(m)
      t2 = fast_fibo(m-1)
      d[n] = t1*t1 + t2*t2
      return d[n]
    else:
      m = n/2
      t1 = fast_fibo(m-1)
      t2 = fast_fibo(m)
      d[n] = (2*t1 +t2)*t2
      return d[n]

if __name__ == "__main__":
  a = int(sys.stdin.readline())
  # print(fibo(a))
  print(fast_fibo(a))
