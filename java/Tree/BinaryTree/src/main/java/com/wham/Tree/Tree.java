package com.wham.Tree;

class Tree {
    public Node root;

    Tree() {
        root = null;
    }

    public void insert(int value) {
        root = insert_helper(root, value);
    }

    /**
     * Delete a node with a given value. Deletion will fall under three cases
     * 1. If node has no children, simply set parents points to null
     * 2. If the node has a single child, we splice out the node by pointing the nodes 
     *    parent to the child
     * 3. If the node has two children, we splice out the nodes sucessor and replace the node's
     *    key with the sucessor and satelliate data  
     * 
     * @param value
     */
    public void delete(int value) {

    }

    public Node deleteHelper(Node current, int value) {
        if (current == null) {
            return current;
        }
        if (value < current.value) {
            current.left = deleteHelper(current.left, value);
        } else if (value > current.value) {
            current.right = deleteHelper(current.right, value);
        } else {
            // node with no children or one children
            if (current.left == null) {
                return current.right;
            } else if (current.right == null) {
                return current.left;
            }
}        
        

        return current;
    }

    public int minValue(Node current) {
        if (root == null) {
            return Integer.MAX_VALUE;
        }
        int minValue = root.value;
        while (current != null) {
            minValue = current.left.value;
            current = current.left;
        }
        return minValue;
    }

    /**
     * If new value is lower than current, recurse left
     * If new value is greater than current, recurse right 
     * If the current value is null we've reached a left node and we
     * can insert
     * @param node
     */
    private Node insert_helper(Node current, int value) {
        if (current == null) {
            current = new Node(value);
            return current;
        }
        if (value < current.value) {
            current.left = insert_helper(current.left, value);
        } else if (value > current.value) {
            current.right = insert_helper(current.right, value);
        }
        return current;
    }

    public boolean contains(int value) {
        return contains_helper(root, value);
    }

    public boolean contains_helper(Node current, int value) {
        if (current == null) {
            return false;
        }
        if (value < current.value) {
            contains_helper(current.left, value);
        } else if (value > current.value) {
            contains_helper(current.right, value);
        }
        return true;
    }

    /**
     * Visit left, current, then right to visit in order
     * @param node
     */
    void inOrderTraversal(Node node) {
        if (node != null) {
            inOrderTraversal(node.left);
            System.out.println(node.value);
            inOrderTraversal(node.right);
        }
    }
    
    /**
     * Visit current node then children
     * 
     * @param node
     */
    void preOrderTraversal(Node node) {
        if (node != null) {
            System.out.println(node.value);
            preOrderTraversal(node.left);
            preOrderTraversal(node.right);
        }
    }

    /**
     * Visits children and then current node 
     * 
     * @param node
     */
    void postOrderTraversal(Node node) {
        if (node != null) {
            postOrderTraversal(node.left);
            postOrderTraversal(node.right);
            System.out.println(node.value);
        }
    }
}