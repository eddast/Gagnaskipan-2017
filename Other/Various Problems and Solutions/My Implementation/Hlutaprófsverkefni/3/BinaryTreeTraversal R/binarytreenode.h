#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

#include <cstddef>

class BinaryTreeNode
{
    public:
        BinaryTreeNode();
        BinaryTreeNode(char data, BinaryTreeNode *left, BinaryTreeNode *right);
        virtual ~BinaryTreeNode();

        ///This is what matters here, the data and
        ///pointers to the left and right children
        ///of this node.
        char data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        ///You can add operations to this class or directly to
        ///the BinaryTree class, whichever you feel more comfortable with.

};

#endif // BINARYTREENODE_H
