package com.wham.Tree;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        Tree tree = new Tree();

        tree.insert(1);
        tree.insert(8);
        tree.insert(7);

        tree.inOrderTraversal(tree.root);
    }
}
