#include <iostream>
#include "binarytree.h"
using namespace std;

int main()
{
    BinaryTree tree;
    cout << tree << endl;
    cout << endl;

    cout << tree.findoradd('d', "stafurinn d") << endl;
    cout << tree.findoradd('h', "stafurinn h") << endl;

    cout << tree << endl;
    cout << endl;

    cout << "message for g: " << tree.findoradd('g', "uppfaerd skilabod fyrir g") << endl;

    return 0;
}
