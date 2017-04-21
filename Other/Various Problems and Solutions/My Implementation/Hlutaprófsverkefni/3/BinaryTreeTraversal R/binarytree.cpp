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
    preorder_recursive(root, out);
}

void BinaryTree::printInorder(ostream& out) {
    inorder_recursive(root, out);
}

void BinaryTree::printPostorder(ostream& out) {
    postorder_recursive(root, out);
}

void BinaryTree::preorder_recursive(BinaryTreeNode* node, ostream& out)
{
    if(node != NULL)
    {
        out << node->data;
        preorder_recursive(node->left, out);
        preorder_recursive(node->right, out);
    }
}

void BinaryTree::inorder_recursive(BinaryTreeNode* node, ostream& out)
{
    if(node != NULL)
    {
        inorder_recursive(node->left, out);
        out << node->data;
        inorder_recursive(node->right, out);
    }
}

void BinaryTree::postorder_recursive(BinaryTreeNode* node, ostream& out)
{
    if(node != NULL)
    {
        postorder_recursive(node->left, out);
        postorder_recursive(node->right, out);
        out << node->data;
    }
}
