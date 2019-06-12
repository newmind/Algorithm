import sys
if __name__ == "__main__":
  N = 5
  sum = 0
  for _ in range(N):
    n = int(sys.stdin.readline().rstrip())
    if n < 40:
        n = 40
    sum += n

  print(sum//5)
  
