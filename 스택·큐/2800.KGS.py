# O(n^3)

import sys
from itertools import combinations

# rstrip 은 오른쪽부터 파리미터 스트링을 제거, ()일 경우 \n 개행을 제거
inputString = sys.stdin.readline().rstrip()  # String

bracketList = []
stack = []
result = set()  # 집합 자료형, 중복 X


for index, value in enumerate(list(inputString)):
    if value == '(':
        stack.append(index)
    elif value == ')':
        start = stack.pop()  # 닫는 순간 가장 마지막에 넣은 ( 를 뺀다
        end = index
        bracketList.append([start, end])  # [열은 위치, 닫은 위치] 의 배열

for index in range(1, len(bracketList) + 1):  # 갯수
    combination = combinations(bracketList, index)  # 리스트안에서 조합

    for j in combination:
        temp = list(inputString)  # 원래 문장을 가져옴

        for k in j:
            start, end = k  # [열은 위치, 닫은 위치] 형태이기 때문에 자동으로 맵핑
            temp[start] = ''
            temp[end] = ''

            result.add(''.join(temp))  # temp는 List 형태이기 때문에 합쳐서 / '' 구분자

for i in sorted(list(result)):
    print(i)
