import sys


def isPalindrome(word):
    return word == word[::-1]


def isCanPalindrome(text):
    left, right = 0, len(text) - 1

    while left < right:
        if text[left] != text[right]:
            # 왼쪽 문자를 제거하거나 오른쪽 문자를 제거하여 회문인지 확인
            return isPalindrome(text[left:right]) or isPalindrome(text[left+1:right+1])
        left += 1
        right -= 1

    return True


input = sys.stdin.readline
n = int(input())

for _ in range(n):
    word = input().strip()

    if isPalindrome(word):
        print(0)
    elif isCanPalindrome(word):
        print(1)
    else:
        print(2)

# 회문 0 / 유사 1 / 그 외 2
# 홀수면 유사

# 1번 방법
# 처음부터 문자를 하나씩 빼서 회문인지 확인한다.
# 최악의 경우 O(N^2)이다.

# 2번 방법
# 회문은 문자열 첫 부분과 끝 부분이 서로 대칭이다.
# 첫 부분과 끝 부분을 비교하며
# 다른 문자가 나오면 왼쪽 문자를 제거하거나 오른쪽 문자를 제거하여 회문인지 확인한다.
