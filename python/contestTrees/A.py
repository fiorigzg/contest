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


def print_tree_values(node, type):
    if type == "pre_order":
        print(node.value, end=" ")
    if node.left:
        print_tree_values(node.left, type)
    if type == "in_order":
        print(node.value, end=" ")
    if node.right:
        print_tree_values(node.right, type)
    if type == "post_order":
        print(node.value, end=" ")


tree = get_tree("input.txt")
print_tree_values(tree, "in_order")
print("")
print_tree_values(tree, "pre_order")
print("")
print_tree_values(tree, "post_order")
print("")

