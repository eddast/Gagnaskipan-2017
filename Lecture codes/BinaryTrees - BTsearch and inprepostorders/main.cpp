#include <iostream>
#include "binarytree.h"
#include "bstset.h"

using namespace std;

int main()
{
    BinaryTree tree;
    cout << tree << endl;

    tree.findoradd('d');
    tree.findoradd('h');

    cout << tree << endl;
    cout << endl;

    cout << "------------------------------" << endl;
    cout << "Testing BST SET" << endl;

    BSTset bset;
    cout << bset << endl;
    if(bset.contains('a')){
        cout << "contains a" << endl;
    }
    else
    {
        cout << "doesn't contain a" << endl;
    }
        if(bset.contains('d')){
        cout << "contains d" << endl;
    }
    else
    {
        cout << "doesn't contain d" << endl;
    }
        if(bset.contains('f')){
        cout << "contains f" << endl;
    }
    else
    {
        cout << "doesn't contain f" << endl;
    }
        if(bset.contains('t')){
        cout << "contains t" << endl;
    }
    else
    {
        cout << "doesn't contain t" << endl;
    }

    return 0;
}
