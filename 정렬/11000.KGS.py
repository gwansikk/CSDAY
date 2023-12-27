import sys
from heapq import heappush, heappop

N = int(sys.stdin.readline())
c = sorted([list(map(int, sys.stdin.readline().split()))
           for _ in range(N)])  # List Comprehension

room = []
heappush(room, c[0][1])  # 첫 수업 끝나는 시간

for i in range(1, N):
    # 강의의 시작 시간이 현재 강의 끝나는 시간 보다 작으면
    if c[i][0] < room[0]:  # 인덱스 0은 가장 작은 값 (빨리끝나는 강의실)
        heappush(room, c[i][1])  # 새로운 강의실
    else:
        # 기존 시간을 없애고, 이어서 진행
        heappop(room)
        heappush(room, c[i][1])

print(len(room))


# 조건
# 1. 끝나는 시간보다 같거나 큰 시작 시간을 가진 강의가 있으면, 이어서 할 수 있다.
# 2. 위 경우가 아니면 새로 강의실을 만들어야 한다.
# 3. 빨리 종료되는 강의실에 붙여야한다. 공백이 생기면 최소가 되지 않음.
