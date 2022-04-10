import sys
input = sys.stdin.readline

class Node:
  def __init__(self, root, left, right):
    self.item = root
    self.left = left
    self.right = right

def PreOrder(node):
  print(node.item, end="")
  if node.left != '.':
    PreOrder(tree[node.left])
  if node.right != '.':
    PreOrder(tree[node.right])

def InOrder(node):
  if node.left != '.':
    InOrder(tree[node.left])
  print(node.item, end="")
  if node.right != '.':
    InOrder(tree[node.right])

def PostOrder(node):
  if node.left != '.':
    PostOrder(tree[node.left])
  if node.right != '.':
    PostOrder(tree[node.right])
  print(node.item, end="")

n = int(input())
tree = {}

for _ in range(n):
  node, left, right = map(str, input().split())
  tree[node] = Node(root=node, left=left, right=right)

PreOrder(tree['A'])
print()
InOrder(tree['A'])
print()
PostOrder(tree['A'])
print()