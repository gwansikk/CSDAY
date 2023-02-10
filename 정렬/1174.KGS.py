import sys
from itertools import combinations

n = int(sys.stdin.readline())
num_list = list()

for i in range(1, 11):
    for i in combinations(range(0, 10), i):
        i = list(i)
        i.reverse()
        num_list.append(int("".join(map(str, i))))

num_list.sort()

try:
    print(num_list[n - 1])
except:
    print(-1)

sys.exit(0)
