n, k = map(int, input().split())
number = list(map(int, input().split()))
result = []
sum = 0

for i in range(n-1):
    result.append(number[i+1] - number[i])

result.sort()

for i in range(n-k):
    sum += result[i]

print(sum)

'''
N과 K를 입력받음
잼민이 숫자를 입력받고 각 칸의 차이를 배열에 넣음
낮은 숫자순서로 sort
N-K의 값만큼 배열의 앞에서부터 더함.
=> result
'''