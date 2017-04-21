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
