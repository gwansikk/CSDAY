import imp


import math

N, K = map(int, input().split())
CalcNumber = 0

# 먼저 최대한 많이 나눠준다.
while N >= K:
    # K로 안떨어지면 -1
    if(N % K != 0):
        N = N - 1;
        CalcNumber += 1
    
    N = N / K;
    CalcNumber += 1

# K로 나눌 수 없을 경우
CalcNumber += math.ceil(N-1)
print(CalcNumber)