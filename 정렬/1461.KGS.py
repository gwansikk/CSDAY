# O(n)

def calculate_distance(list, m):
    d = []

    for i in range(len(list)//m):
        d.append(abs(list[m*i]))

    if len(list) % m > 0:
        d.append(abs(list[(len(list)//m)*m]))

    return d


n, m = map(int, input().split())
bookPoint = list(map(int, input().split()))
l, r = [], []

# 분류: i가 음수이면 l에 추가, 양수이면 r에 추가
for i in bookPoint:
    l.append(i) if i < 0 else r.append(i)

l.sort()  # 리스트 l을 오름차순으로 정렬, 음수 오름차순임!
r.sort(reverse=True)  # 리스트 r을 내림차순으로 정렬, 가장 멀리 있는 값으로 루트를 선저해야하기 때문

points = calculate_distance(l, m) + calculate_distance(r, m)  # 리턴되는 배열 연결

points.sort()  # 왼쪽, 오른쪽 루트중 가장 큰 루트를 찾기 위함
r = points.pop()  # 가장 큰 숫자 팝, 왕복이 아니기 때문
r += 2*sum(points)  # 남은거 더 해서 왕복

print(r)
