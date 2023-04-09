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

# 왜 숫자가 아닌 문자열로 받아서 한 이유!!
# 123, 12, 1245 를 int형으로 정렬하면 -> 12, 123, 1245
# 문자열 경우 -> '12', '1245', '123'
