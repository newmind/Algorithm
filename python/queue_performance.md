``` sh
> python -m timeit 'import heapq' 'heapq.heapify([[0, 1] for _ in range(1000000)])'
1 loop, best of 5: 226 msec per loop

> python -m timeit 'import heapq'   'arr = []' 'for x in [[0, 1] for _ in range(1000000)]:' '  heapq.heappush(arr,x)'
1 loop, best of 5: 331 msec per loop

> python -m timeit '[[0, 1] for _ in range(1000000)].sort()'
2 loops, best of 5: 200 msec per loop

> python -m timeit 'import queue' 'q = queue.PriorityQueue(maxsize=1000000)' 'for x in [[0, 1] for _ in range(1000000)]:' '  q.put(x)'

```
