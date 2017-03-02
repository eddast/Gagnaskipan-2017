#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "treenode.h"

class BinaryTree
{
    public:
        BinaryTree();
        virtual ~BinaryTree();
        string findoradd(char data, string message);
        friend ostream& operator <<(ostream& out, const BinaryTree& tree);

    protected:

    private:
        TreeNode* &find(TreeNode* &node, char data, int depth);
        void printPreorder(ostream& out, TreeNode* node) const;
        void printPostorder(ostream& out, TreeNode* node) const;
        void printInorder(ostream& out, TreeNode* node) const;

        TreeNode* root;
};

#endif // BINARYTREE_H
