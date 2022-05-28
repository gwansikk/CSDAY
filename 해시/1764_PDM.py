import sys
input = sys.stdin.readline

N, M = map(int, input().split())
list = []
result = []

for i in range(N):
    list.append(input().strip())
list.sort()

for i in range(M):
    name = input().strip()
    for j in range(N):
        if list[j] > name:
            break
        if list[j] == name:
            result.append(name)

result.sort()

print(len(result))
for i in result:
    print(i)