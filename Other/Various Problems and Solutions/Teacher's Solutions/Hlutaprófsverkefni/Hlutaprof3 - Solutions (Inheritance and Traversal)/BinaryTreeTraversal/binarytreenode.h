#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

#include <cstddef>

class BinaryTreeNode
{
    public:
        BinaryTreeNode();
        BinaryTreeNode(char data, BinaryTreeNode *left, BinaryTreeNode *right);
        virtual ~BinaryTreeNode();

        char data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        void printPreorder();
        void printInorder();
        void printPostorder();

};

#endif // BINARYTREENODE_H
