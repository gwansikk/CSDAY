import sys

# 필요 선언
cnt, first, end = 0, 0, 0;
input = sys.stdin.readline

L = int(input())
S = list(map(int, input().split()))
N = int(input())

# 집합 S 정렬
S.sort()

# 첫번째 요소가 N보다 클경우
if (N <= S[0]):
    first = 0
    end = S[0]
else:
    # N보다 첫번째로 큰 값 찾기
    for i in range(L):
        if(N <= S[i]):
            first = S[i-1] #인덱스가 -1로 되면 리스트의 끝 값으로 설정이됨.
            end = S[i]
            break

# 구간이 없을 경우
if (end == N):
    print(0)
else:
    # 구간이 있을 경우
    for i in range(first + 1, end):
        for j in range(i + 1, end):
            if (i <= N and N <= j):
                cnt = cnt + 1;
    
    print(cnt)
