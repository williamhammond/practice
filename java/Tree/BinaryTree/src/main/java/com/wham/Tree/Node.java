package com.wham.Tree;

class Node {
    public Integer value;
    public Node left;
    public Node right;

    Node(int value) {
        this.value = value;
        right = null;
        left = null;
    }
}