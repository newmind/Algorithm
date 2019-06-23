import sys

# 피보나치 6
#  * boj.kr/11444
#  * 행렬곱셈 또는
#  홀수 번째와 짝수 번째 피보나치수를 모두 더 작은 피보나치 수의 합 또는 곱을 이용해서 구할 수 있습니다.

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

if __name__ == "__main__":
  a = int(sys.stdin.readline())
  print(fibo(a))
