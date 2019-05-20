import queue
import heapq
import sys

def logging_time(original_fn):
  def wrapper_fn(*args, **kwargs):
    import time
    start_time = time.time()
    result = original_fn(*args, **kwargs)
    end_time = time.time()
    print("WorkingTime[{}]: {} sec".format(original_fn.__name__, end_time-start_time))
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

@logging_time
def line_sweeping_list(lines : list):
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

@logging_time
def line_sweeping_pq(lines : queue):
  length = 0
  x, y = lines.get()
  while not lines.empty():
    x2, y2 = lines.get()
    if x2 > y:
      length += y - x
      x = x2
      y = y2
    elif y2 > y:
      y = y2

  length += y - x
  print(length)

@logging_time
def line_sweeping_heapq(lines):
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


if __name__ == "__main__":
  import random
  import timeit
  import time

  lines = [[random.randint(0, 1000), random.randint(1001, 2000)] for _ in range(1000000)]

  lines1 = lines[:]
  print('list.sort()')
  start_time = time.time()
  lines1.sort()
  end_time = time.time()
  print("WorkingTime: {} sec".format(end_time-start_time))
  line_sweeping_list(lines1)

  lines2 = lines[:]
  print('\nqueue.PriorityQueue()  put')
  start_time = time.time()
  pq = queue.PriorityQueue()
  for x in lines2:
    pq.put(x)
  end_time = time.time()
  print("WorkingTime: {} sec".format(end_time-start_time))
  line_sweeping_pq(pq)

  lines3 = lines[:]
  print('\nheapq.heapify(lines)')
  start_time = time.time()
  hq = heapq.heapify(lines)
  end_time = time.time()
  print("WorkingTime: {} sec".format(end_time-start_time))
  line_sweeping_heapq(lines3)
