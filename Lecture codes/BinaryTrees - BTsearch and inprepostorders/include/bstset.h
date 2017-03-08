#ifndef BSTSET_H
#define BSTSET_H
#include "treenode.h"

class BSTset
{
    public:
        BSTset();
        virtual ~BSTset();

        void insert (char data);
        void remove (char data);
        bool contains(char data);
        bool isLeaf(TreeNode* node);
        int size();

        friend ostream& operator <<(ostream& out, BSTset set);

    protected:

    private:
        TreeNode* root;
        int count;
        TreeNode* &find(TreeNode* &node, char data);
        void printInorder(ostream& out, TreeNode* node);
};

#endif // BSTSET_H
