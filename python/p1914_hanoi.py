import sys

# 1914
# hanoi

input = sys.stdin.readline

def hanoi(n, from_pos, to_pos, aux_pos):
    if n == 1:
        print(str(from_pos) + ' ' + str(to_pos))
        return
    hanoi(n - 1, from_pos, aux_pos, to_pos)
    print(str(from_pos) + ' ' + str(to_pos))
    hanoi(n - 1, aux_pos, to_pos, from_pos)

if __name__ == "__main__":
    n = int(input())

    steps = 2**n - 1
    print(steps)
    if n <= 20:
      hanoi(n, 1, 3, 2)