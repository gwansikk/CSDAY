from collections import defaultdict
import sys
input = sys.stdin.readline


class Node:
    def __init__(self):
        self.word = False
        self.children = {}  # 딕녀너리


class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, word):
        node = self.root

        for char in word:
            if char not in node.children:
                # 해당 문자가 자식에 없을 경우, 노드를 생성
                node.children[char] = Node()
            # 자식의 노드로 이동
            node = node.children[char]

        # 마지막 노드 표시
        node.word = True

    def search(self, word):
        node = self.root
        string = ''

        for char in word:
            string += char

            if char not in node.children:
                return string

            node = node.children[char]

        if node.word:
            # 해당 문자열이 마지막 노드이면
            string += str(nameCountDict[string]+1)
        return string


N = int(input())

tree = Trie()
nameCountDict = defaultdict(int)  # 이름이 몇 번 나왔는지 저장하는 dict, 없으면 0으로 리턴

for _ in range(N):
    word = input().rstrip()  # 공백 없이 입력받기
    print(tree.search(word))

    if (nameCountDict[word] == 0):
        tree.insert(word)

    nameCountDict[word] += 1
