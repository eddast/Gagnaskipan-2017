#include <iostream>
#include "binarytreenode.h"

using namespace std;

BinaryTreeNode::BinaryTreeNode()
{
    left = NULL;
    right = NULL;
}

BinaryTreeNode::BinaryTreeNode(char data, BinaryTreeNode *left, BinaryTreeNode *right)
{
    this->data = data;
    this->left = left;
    this->right = right;
}

BinaryTreeNode::~BinaryTreeNode()
{
    if(left != NULL) {
        delete left;
    }
    if(right != NULL) {
        delete right;
    }
}

void BinaryTreeNode::printPreorder() {
    cout << data;
    if(left != NULL) {
        left->printPreorder();
    }
    if(right != NULL) {
        right->printPreorder();
    }
}

void BinaryTreeNode::printInorder() {
    if(left != NULL) {
        left->printInorder();
    }
    cout << data;
    if(right != NULL) {
        right->printInorder();
    }
}

void BinaryTreeNode::printPostorder() {
    if(left != NULL) {
        left->printPostorder();
    }
    if(right != NULL) {
        right->printPostorder();
    }
    cout << data;
}
