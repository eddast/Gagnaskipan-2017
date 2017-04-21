#include <iostream>
#include "binarytree.h"

using namespace std;

BinaryTree::BinaryTree()
{
    root = NULL;
}

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

void BinaryTree::printPreorder() {
    if(root != NULL) {
        root->printPreorder();
        // eða þetta: printPreorder(root);
    }
    cout << endl;
}

void BinaryTree::printInorder() {
    if(root != NULL) {
        root->printInorder();
        // eða þetta: printInorder(root);
    }
    cout << endl;
}

void BinaryTree::printPostorder() {
    if(root != NULL) {
        root->printPostorder();
        // eða þetta: printPostorder(root);
    }
    cout << endl;
}

///Possible option is implementing these methods here
///but I'm implementing them on the Node to simplify
///the references to child nodes.

void BinaryTree::printPreorder(BinaryTreeNode *node) {
    cout << node->data;
    if(node->left != NULL) {
        printPreorder(node->left);
    }
    if(node->right != NULL) {
        printPreorder(node->right);
    }
}

void BinaryTree::printInorder(BinaryTreeNode *node) {
    if(node->left != NULL) {
        printInorder(node->left);
    }
    cout << node->data;
    if(node->right != NULL) {
        printInorder(node->right);
    }
}

void BinaryTree::printPostorder(BinaryTreeNode *node) {
    if(node->left != NULL) {
        printPostorder(node->left);
    }
    if(node->right != NULL) {
        printPostorder(node->right);
    }
    cout << node->data;
}
