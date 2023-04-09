# O(n^2)
import sys

t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())
    contact = sorted([str(sys.stdin.readline().strip()) for _ in range(n)])
    check = True

    for i in range(len(contact) - 1):
        if contact[i] == contact[i + 1][:len(contact[i])]:  # prefix 발견 시 바로
            check = False
            break

    print("YES" if check else "NO")
