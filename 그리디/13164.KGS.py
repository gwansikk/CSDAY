# O(n)
n, k = map(int, input().split())
arr = list( map(int, input().split()))
res = 0
temp = list();

for i in range(0, n-1):
    temp.append(arr[i + 1] - arr[i])

temp.sort();

for i in range(n-k):
    res += temp[i]

print(res)