import sys
if __name__ == "__main__":
  a = int(sys.stdin.readline())
  b = int(sys.stdin.readline())
  c = int(sys.stdin.readline())

  s = str(a*b*c)

  arr = [0] * 10

  for a in s:
    arr[ord(a)-ord('0')] += 1

  for a in arr:
    print(a)