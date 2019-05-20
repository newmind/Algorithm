# 2170

import sys
import heapq

def logging_time(original_fn):
  def wrapper_fn(*args, **kwargs):
    import time
    start_time = time.time()
    result = original_fn(*args, **kwargs)
    end_time = time.time()
    print("logging_time : {} sec".format(end_time-start_time))
    return result
  return wrapper_fn

def runtime(f):
    def wrapper(*args, **kwargs):
        import timeit
        start = timeit.default_timer()
        result = f(*args, **kwargs)
        end = timeit.default_timer()
        print("runtime : {} sec".format(end - start))
        return result
    return wrapper

# @runtime
@logging_time
def line_sweeping_heapq(lines):
  hq = heapq.heapify(lines)
  length = 0
  x, y = heapq.heappop(lines)
  while len(lines) > 0:
    x2, y2 = heapq.heappop(lines)
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
  n = int(sys.stdin.readline())
  arr = [sys.stdin.readline().rstrip() for i in range(n)]

  lines = [[0, 0] for _ in range(n)]
  for i in range(n):
    a, b = arr[i].split()
    lines[i][0] = int(a)
    lines[i][1] = int(b)

  # lines = [[1, 3], [2, 5], [3, 5], [6, 7]]

  line_sweeping_heapq(lines)