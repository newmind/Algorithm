import sys
if __name__ == "__main__":
  N = int(sys.stdin.readline().rstrip())
  for _ in range(N):
    s = str(sys.stdin.readline().rstrip())
    acc = 0
    sum = 0
    for a in s:
      if a == 'O':
        acc += 1
        sum += acc
      else:
        acc = 0

    print(sum)
  
