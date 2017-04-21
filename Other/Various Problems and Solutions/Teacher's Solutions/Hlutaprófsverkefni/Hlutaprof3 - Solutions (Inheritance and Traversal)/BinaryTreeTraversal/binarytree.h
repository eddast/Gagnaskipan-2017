#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "binarytreenode.h"

#define FIRST_CODE 1
#define SECOND_CODE 2
#define THIRD_CODE 3

class BinaryTree
{
    public:
        BinaryTree();
        BinaryTree(int code);
        virtual ~BinaryTree();

        void printPreorder();
        void printInorder();
        void printPostorder();

    protected:

    private:
        BinaryTreeNode *root;

        void printPreorder(BinaryTreeNode *node);
        void printInorder(BinaryTreeNode *node);
        void printPostorder(BinaryTreeNode *node);

};

#endif // BINARYTREE_H
