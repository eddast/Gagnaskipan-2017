#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include <string>

using namespace std;

class TreeNode
{
    public:
        TreeNode(): data('\0'), left(NULL), right(NULL) {}
        TreeNode(char data, TreeNode* left, TreeNode* right):
            data(data), left(left), right(right) {}

        virtual ~TreeNode() {}

        char data;
        TreeNode* left;
        TreeNode* right;

    private:

};

#endif // TREENODE_H
