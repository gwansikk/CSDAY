n, k = map(int, input().split())

dp = [[0] * (n + 1) for _ in range(k + 1)] # 2차원 배열 생성, 0으로 초기화
dp[0][0] = 1 # 시작점 1, 0은 무조건 1개로 됨 0

# DP 계산
for i in range(1, k + 1):
    for j in range(n + 1):
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

print(dp[k][n]) 