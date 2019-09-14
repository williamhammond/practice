class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.data = key

def insert(root, node):
    if root is None:
        root = node    
    else:
        if root.val < node.val:
            if root.right == None:
                root.right = node
            else:
                insert(root.right, node)
        else: 
            if root.left == None:
                root.left = node
            else:
                insert(root.left, node)

def inorder(root): 
    if root: 
        inorder(root.left) 
        print(root.val) 
        inorder(root.right) 
