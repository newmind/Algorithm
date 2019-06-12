import sys
input=sys.stdin.readline

if __name__ == "__main__":
    l = list(map(int, input().split()))
    if l[0] == 1:
        found = True
        for x in range(1, 8):
            if l[x] != l[x-1] + 1:
                found = False
                break

        if found:
            print('ascending')
            sys.exit(0)

    if l[0] == 8:
        found = True
        for x in range(1, 8):
            if l[x] != l[x-1] - 1:
                found = False
                break

        if found:
            print('descending')
            sys.exit(0)

    print('mixed')