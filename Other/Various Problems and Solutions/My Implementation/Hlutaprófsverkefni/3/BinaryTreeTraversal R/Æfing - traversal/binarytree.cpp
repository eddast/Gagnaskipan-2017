#include <iostream>
#include "binarytree.h"

using namespace std;

BinaryTree::BinaryTree()
{
    root = NULL;
}

///This builds some hard-coded test trees.  Leave it alone :)
BinaryTree::BinaryTree(int code)
{
    if(code == FIRST_CODE) {
        root = new BinaryTreeNode('p', new BinaryTreeNode('r', new BinaryTreeNode('e', NULL, new BinaryTreeNode('o', new BinaryTreeNode('r', new BinaryTreeNode('d', NULL, NULL), NULL), new BinaryTreeNode('e', new BinaryTreeNode('r', NULL, NULL), NULL))), new BinaryTreeNode('_', NULL, new BinaryTreeNode('c', NULL, NULL))), new BinaryTreeNode('o', NULL, new BinaryTreeNode('r', new BinaryTreeNode('r', new BinaryTreeNode('e', NULL, NULL), new BinaryTreeNode('c', NULL, NULL)), new BinaryTreeNode('t', NULL, NULL))));
    }
    else if(code == SECOND_CODE) {
        root = new BinaryTreeNode('i', NULL, new BinaryTreeNode('t', new BinaryTreeNode('_', new BinaryTreeNode('o', new BinaryTreeNode('n', NULL, NULL), new BinaryTreeNode('r', new BinaryTreeNode('d', new BinaryTreeNode('r', NULL, NULL), new BinaryTreeNode('e', NULL, NULL)), NULL)), new BinaryTreeNode('o', new BinaryTreeNode('c', NULL, NULL), new BinaryTreeNode('r', NULL, new BinaryTreeNode('e', new BinaryTreeNode('r', NULL, NULL), new BinaryTreeNode('c', NULL, NULL))))), NULL));
    }
    else if(code == THIRD_CODE) {
        root = new BinaryTreeNode('t', new BinaryTreeNode('_', new BinaryTreeNode('p', NULL, NULL), new BinaryTreeNode('r', NULL, new BinaryTreeNode('e', new BinaryTreeNode('d', new BinaryTreeNode('r', new BinaryTreeNode('o', NULL, NULL), new BinaryTreeNode('o', new BinaryTreeNode('t', new BinaryTreeNode('s', NULL, NULL), NULL), NULL)), NULL), NULL))), new BinaryTreeNode('c', NULL, new BinaryTreeNode('e', new BinaryTreeNode('c', NULL, NULL), new BinaryTreeNode('r', NULL, new BinaryTreeNode('r', new BinaryTreeNode('o', NULL, NULL), NULL)))));
    }
    else {
        root = NULL;
    }
}

BinaryTree::~BinaryTree()
{
    if(root != NULL) {
        delete root;
    }
}

void BinaryTree::printPreorder(ostream& out) {
    /// TODO: Implement this!
    /// Add helping functions for recursion as needed
}

void BinaryTree::printInorder(ostream& out) {
    /// TODO: Implement this!
    /// Add helping functions for recursion as needed
}

void BinaryTree::printPostorder(ostream& out) {
    /// TODO: Implement this!
    /// Add helping functions for recursion as needed
}
