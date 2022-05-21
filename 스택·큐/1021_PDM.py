import sys
input = sys.stdin.readline
from collections import deque

max, cycle = map(int, input().split())
list = deque(range(1,max+1))
numbers = deque(map(int, input().split()))

count = 0

while numbers:
    mid = len(list)//2
    if list.index(numbers[0]) > mid: # 오른쪽으로 회전
        while list[0] != numbers[0]:
            list.appendleft(list.pop())
            count += 1
        list.popleft()
        numbers.popleft()
    else: # 왼쪽으로 회전
        while list[0] != numbers[0]:
            list.append(list.popleft())
            count += 1
        list.popleft()
        numbers.popleft()

print(count)