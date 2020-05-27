# # https://csacademy.com/contest/interview-archive/task/all-bst-preorders/


def all_bst_preorders(size):
    class Node:
        def __init__(self, item):
            self.key = item
            self.left = None
            self.right = None

        def __repr__(self):
            return f'NODE[{self.key}, L/R: {self.left}, {self.right}]'

    def preorder(root, l):
        if root:
            l.append(root.key)
            preorder(root.left, l)
            preorder(root.right, l)
        return l

    def buildTree(start, end):
        l = []

        if (start > end):
            l.append(None)
            return l

        for i in range(start, end + 1):
            leftTree = buildTree(start, i - 1)
            rightTree = buildTree(i + 1, end)

            for j in range(len(leftTree)):
                left = leftTree[j]
                for k in range(len(rightTree)):
                    right = rightTree[k]
                    node = Node(i)
                    node.left = left
                    node.right = right
                    l.append(node)
                    print(node)
        return l

    for tree in buildTree(1, size):
        print(*preorder(tree, []), sep=' ', end='\n')


# size = int(input())
size = 2
all_bst_preorders(size)
