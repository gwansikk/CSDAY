# KGS / O(n)

import sys
input = sys.stdin.readline

n = int(input())
fileList = dict()

for _ in range(n):
    extension = (input().split("."))[1].strip() # 확장자 이름 끝에 개행 문자를 삭제하기 위해 strip() 사용
    
    if not extension in fileList:
        fileList[extension] = 1
    else:
        fileList[extension] += 1

fileListSorted = sorted(fileList.items()) # 딕셔너리는 sorted를 사용해야함

for key, value in fileListSorted: # 딕셔너리는 key, value로 대치하여 접근할 수 있음
    print(key, value) 