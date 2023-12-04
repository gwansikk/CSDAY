from bisect import bisect
import sys

input = sys.stdin.readline

n = int(input())
port = list(map(int, input().split()))

array = [port[0]]

for i in range(1, n):
    if port[i] > array[-1]:
        # array의 마지막 값보다 크다면 array에 추가한다.
        # 겹치지지 않는다는 의미
        array.append(port[i])
    else:
        # array에서 port[i]가 들어갈 위치를 찾아서 그 위치에 port[i]를 넣는다.
        # 겹치기 때문에 기존 값에 덮어 씌운다
        array[bisect(array, port[i])] = port[i]
