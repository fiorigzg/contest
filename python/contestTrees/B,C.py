import sys


sys.setrecursionlimit(10000)


class Node:
    def __init__(self, value, left, right):
        self.value = value
        self.left = left
        self.right = right


def get_tree(file_name):
    with open(file_name) as f:
        n = int(f.readline())
        nodes = list(map(lambda line: list(map(int, line.split())), f.readlines()))

        def make_tree(node):
            [value, left, right] = node
            return Node(value, make_tree(nodes[left]) if left != -1 else None, make_tree(nodes[right]) if right != -1 else None)

        root = make_tree(nodes[0])

        return root


def is_tree_correct(node, min_value, max_value):
    if node == None:
        return True

    # print(node.value, min_value, max_value)
    if max_value <= node.value or min_value > node.value:
        return False

    return is_tree_correct(node.left, min_value, node.value) and is_tree_correct(node.right, node.value, max_value)


tree = get_tree("input.txt")
print("CORRECT" if is_tree_correct(tree, float('-inf'), float('inf')) else "INCORRECT")
