import sys

# 필요 선언
i = 0
n = int(sys.stdin.readline())

def move(n, x, y, t):
    global i

    if (n > 1):
        move(n-1, x, 6-x-y, t)

    if (t == 1):
        print(x, y)
    else:
        i += 1
    
    if (n > 1):
        move(n-1, 6-x-y, y, t)

move(n, 1, 3, 0)
print(i)
move(n, 1, 3, 1)
