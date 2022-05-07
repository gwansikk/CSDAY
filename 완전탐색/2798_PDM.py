# O(n^2)
import sys
input = sys.stdin.readline

num, target = map(int, input().split())
arr = list(map(int, input().split()))
i, j, k, sum, result = 0,0,0,0,0

for i in range(num-2):
    fir = arr[i]
    for j in range(i,num-2):
        sec = arr[j + 1]
        for k in range(j,num - 2):
            thr = arr[k + 2]
            sum = fir + sec + thr
            if ((sum > result) and (sum <= target)):
                result = sum

print(result)