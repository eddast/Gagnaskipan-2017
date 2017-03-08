#include "bstset.h"

BSTset::BSTset()
{
    root = new TreeNode('a',
                    new TreeNode('b',
                                new TreeNode('d', NULL, NULL),
                                new TreeNode('e', NULL, NULL)),
                    new TreeNode('c',
                                new TreeNode('f', NULL, NULL),
                                new TreeNode('g', NULL, NULL)));
    count = 7;
}

BSTset::~BSTset()
{
    //dtor
}

void BSTset::remove (char data)
{
    TreeNode* &node = find(root, data);

    if(node == NULL)
    {
        return;
    }
    if(isLeaf(node))
    {
        delete node;
        node = NULL;
    }
    else if(node->left != NULL && node->right == NULL)
    {
        TreeNode* tmp = node;
        node = node->left;
        delete tmp;
    }
    else if(node->left == NULL && node->right != NULL)
    {
        TreeNode* tmp = node;
        node = node->left;
        delete tmp;
    }
}

bool BSTset::isLeaf(TreeNode* node) {return (node->left == NULL && node->right == NULL); }


bool BSTset::contains(char data)
{
    return (find(root, data));
}

void BSTset::insert(char data)
{
    TreeNode* &node = find(root, data);
    if(node == NULL){
        node = new TreeNode(data, NULL, NULL);
        count++;
    }
}

int BSTset::size(){return count; }

void BSTset::printInorder(ostream& out, TreeNode* node){
    if(node != NULL)
    {
        printInorder(out, node->left);
        out << node->data << " ";
        printInorder(out, node->right);
    }
}
TreeNode* &BSTset::find(TreeNode* &node, char data)
{
    if(node == NULL || node->data == data) {return node; }
    if(data < node->data){return find(node->left, data); }
    if (data > node->data){return find(node->right, data); }
    else{return node; }
}

ostream& operator <<(ostream& out, BSTset set)
{
    set.printInorder(out, set.root);
    return out;
}


