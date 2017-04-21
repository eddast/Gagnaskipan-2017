#include <iostream>
#include "binarytree.h"

using namespace std;

int main() {

    cout << endl << "Pay lines marked with *->* special notice!" << endl;

    cout << endl << "First Tree:" << endl;
    BinaryTree btree1(FIRST_CODE);
    cout << "->  preorder: ";
    btree1.printPreorder(cout);
    cout << endl;
    cout << "     inorder: ";
    btree1.printInorder(cout);
    cout << endl;
    cout << "   postorder: ";
    btree1.printPostorder(cout);
    cout << endl;

    cout << endl << "Second Tree:" << endl;
    BinaryTree btree2(SECOND_CODE);
    cout << "    preorder: ";
    btree2.printPreorder(cout);
    cout << endl;
    cout << "->   inorder: ";
    btree2.printInorder(cout);
    cout << endl;
    cout << "   postorder: ";
    btree2.printPostorder(cout);
    cout << endl;

    cout << endl << "Third Tree:" << endl;
    BinaryTree btree3(THIRD_CODE);
    cout << "    preorder: ";
    btree3.printPreorder(cout);
    cout << endl;
    cout << "     inorder: ";
    btree3.printInorder(cout);
    cout << endl;
    cout << "-> postorder: ";
    btree3.printPostorder(cout);
    cout << endl;

    return 0;
}
