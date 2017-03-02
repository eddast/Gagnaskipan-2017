#include <iostream>
#include "binarytree.h"
using namespace std;

int main()
{
    BinaryTree tree;
    cout << tree << endl;

    tree.findoradd('d');
    tree.findoradd('h');

    cout << tree << endl;

    return 0;
}
