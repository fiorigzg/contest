import random

class TreapNode:
    def __init__(self, key, priority=None):
        self.key = key
        self.priority = priority if priority is not None else random.randint(1, 100)
        self.left = None
        self.right = None

def split(root, key):
    if root is None:
        return None, None
    elif key < root.key:
        left, root.left = split(root.left, key)
        return left, root
    else:
        root.right, right = split(root.right, key)
        return root, right

def merge(left, right):
    if left is None:
        return right
    if right is None:
        return left
    if left.priority > right.priority:
        left.right = merge(left.right, right)
        return left
    else:
        right.left = merge(left, right.left)
        return right

def delete(root, key):
    if root is None:
        return None
    if root.key == key:
        return merge(root.left, root.right)
    elif key < root.key:
        root.left = delete(root.left, key)
    else:
        root.right = delete(root.right, key)
    return root

def insert(root, key, priority=None):
    if root is None:
        return TreapNode(key, priority)
    if key < root.key:
        left, right = split(root, key)
        new_node = TreapNode(key, priority)
        return merge(merge(left, new_node), right)
    else:
        left, right = split(root, key + 1)
        new_node = TreapNode(key, priority)
        return merge(merge(left, new_node), right)

def print_treap(root, indent=0):
    if root is not None:
        print_treap(root.right, indent + 4)
        print(" " * indent + f"({root.key}, {root.priority})")
        print_treap(root.left, indent + 4)

# Test the Treap
if __name__ == "__main__":
    root = None
    root = insert(root, 10)
    root = insert(root, 5)
    root = insert(root, 15)
    root = insert(root, 3)
    root = insert(root, 8)

    print("Treap structure:")
    print_treap(root)