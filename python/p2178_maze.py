import sys
import queue

# http://boj.kr/2178
# 미로탐색

input = sys.stdin.readline

if __name__ == "__main__":
    n, m = list(map(int, input().split()))

    maze = [[0]*m for _ in range(n)]
    for y in range(n):
        l = input().strip()
        for x in range(m):
            maze[y][x] = int(l[x])

    visited = set()

    q = queue.Queue()
    q.put((0,0,1))
    visited.add((0,0))

    while not q.empty():
        x,y,w = q.get()

        if x == m-1 and y == n-1:
            print(w)
            exit

        if y > 0 and maze[y-1][x] == 1:
            if (x, y-1) not in visited:
                q.put((x, y-1, w+1))
                visited.add((x, y-1))
        if x+1 < m and maze[y][x+1] == 1:
            if (x+1, y) not in visited:
                q.put((x+1, y, w+1))
                visited.add((x+1, y))
        if y+1 < n and maze[y+1][x] == 1:
            if (x, y+1) not in visited:
                q.put((x, y+1, w+1))
                visited.add((x, y+1))
        if x > 0 and maze[y][x-1] == 1:
            if (x-1, y) not in visited:
                q.put((x-1, y, w+1))
                visited.add((x-1, y))

