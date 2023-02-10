#O(n)

import sys
input = sys.stdin.readline

num = int(input())

def search(kwd):
    result.append(int(kwd))
    for j in range(0,int(kwd[-1])):
        search(kwd + str(j))

if num > 1023:
    print(-1)
else:
    result = []
    for i in range(10):
        search(str(i))
    print(sorted(result)[num-1])