#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "binarytreenode.h"

#include <ostream>

#define FIRST_CODE 1
#define SECOND_CODE 2
#define THIRD_CODE 3

using namespace std;

class BinaryTree
{
    public:
        BinaryTree();
        BinaryTree(int code);
        virtual ~BinaryTree();

        ///Implement these operations
        void printPreorder(ostream& out);
        void printInorder(ostream& out);
        void printPostorder(ostream& out);

        ///You can add recursive operations to this
        ///class or to the BinaryTreeNode class,
        ///whichever you feel more comfortable with.

    private:
        ///This is the root of the tree.
        ///It is a BinaryTreeNode pointer, just like any other node in the tree.
        BinaryTreeNode *root;

        /// Recursive printing of inorder, preorder and postorder
        void preorder_recursive(BinaryTreeNode* node, ostream& out);
        void inorder_recursive(BinaryTreeNode* node, ostream& out);
        void postorder_recursive(BinaryTreeNode* node, ostream& out);
};

#endif // BINARYTREE_H
