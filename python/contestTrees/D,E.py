import math


class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right
        self.height = 1
        self.size = 1


def update_info(node):
    node.height = max(height(node.left), height(node.right)) + 1
    node.size = size(node.left) + size(node.right) + 1


def height(node):
    return node.height if node else 0


def size(node):
    return node.size if node else 0


def right_rotate(node):
    res_node = node.left
    node.left = res_node.right
    res_node.right = node
    update_info(node)
    update_info(res_node)
    return res_node


def left_rotate(node):
    res_node = node.right
    node.right = res_node.left
    res_node.left = node
    update_info(node)
    update_info(res_node)
    return res_node


def get_factor(node):
    return height(node.right) - height(node.left)


def balance(node):
    update_info(node)
    factor = get_factor(node)
    if factor >= 2:
        if get_factor(node.right) < 0:
            node.right = right_rotate(node.right)
        return left_rotate(node)
    if factor <= -2:
        if get_factor(node.left) > 0:
            node.left = left_rotate(node.left)
        return right_rotate(node)
    return node


def insert(node, value):
    if node is None:
        return Node(value)
    if value == node.value:
        return node
    if value < node.value:
        node.left = insert(node.left, value)
    else:
        node.right = insert(node.right, value)
    return balance(node)


def delete(node, value):
    if node is None:
        return None
    if value < node.value:
        node.left = delete(node.left, value)
    elif value > node.value:
        node.right = delete(node.right, value)
    else:
        if node.left is None:
            return node.right
        if node.right is None:
            return node.left
        min_larger_node = get_min(node.right)
        node.value = min_larger_node.value
        node.right = delete(node.right, min_larger_node.value)
    return balance(node)


def get_min(node):
    while node.left is not None:
        node = node.left
    return node


def exists(node, value):
    while node:
        if value == node.value:
            return True
        elif value < node.value:
            node = node.left
        else:
            node = node.right
    return False


def next(node, value):
    child = None
    while node:
        if node.value > value:
            child = node
            node = node.left
        else:
            node = node.right
    return child.value if child else "none"


def prev(node, value):
    parent = None
    while node:
        if node.value < value:
            parent = node
            node = node.right
        else:
            node = node.left
    return parent.value if parent else "none"


def kth(node, k):
    while node:
        left_size = size(node.left)
        if k <= left_size:
            node = node.left
        elif k > left_size + 1:
            k -= left_size + 1
            node = node.right
        else:
            return node.value
    return "none"


def exec_commands(file_name):
    tree = None
    with open(file_name) as f:
        for line in f:
            parts = line.strip().split()
            if len(parts) != 2:
                continue
            text, value = parts[0], int(parts[1])
            if text == "insert":
                tree = insert(tree, value)
            elif text == "delete":
                tree = delete(tree, value)
            elif text == "exists":
                print("true" if exists(tree, value) else "false")
            elif text == "next":
                print(next(tree, value))
            elif text == "prev":
                print(prev(tree, value))
            elif text == "kth":
                print(kth(tree, value))


exec_commands("input.txt")
