import sys
input = sys.stdin.readline

N, M = map(int, input().split())

NList = set()
for i in range(N):
    NList.add(input().strip())

MList = set()
for i in range(M):
    MList.add(input().strip())

result = sorted(NList & MList)

print(len(result))
for i in result:
    print(i)