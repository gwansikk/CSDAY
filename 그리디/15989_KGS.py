# O(n)

t = int(input())

DP = [1] * 10001

for i in range(2, 10001):
    DP[i] = DP[i] + DP[i - 2]

for i in range(3, 10001):
    DP[i] = DP[i] + DP[i - 3]

for _ in range(t):
    print(DP[int(input())])
