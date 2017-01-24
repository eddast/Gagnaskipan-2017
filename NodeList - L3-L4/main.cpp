/* GSKI 2017
 * Lecture code
 * Linked list
 * Singular linked:
 * 01.16.17 - 18.01.17
 * Updated to doubly linked:
 * 23.01.17
 */

#include <iostream>
#include "NodeList.h"

using namespace std;

int main()
{
    // TESTING Node:
    // Creating node linked with another node
    Node *n1 = new Node(1, new Node(2, NULL));
    cout << "First node: " << endl
         << *n1 << endl;
    // What's next?
    cout << "Second node: " << endl
         << *(n1->next) << endl;

    // TESTING NodeList
    NodeList nodeList;
    // Head Insert - Stacking
    nodeList.headInsert(1);
    nodeList.headInsert(2);
    nodeList.headInsert(3);
    nodeList.headInsert(4);
    nodeList.headInsert(5);
    cout << nodeList << endl;
    // Tail insert - inserting last
    nodeList.tailInsert(1);
    nodeList.tailInsert(2);
    nodeList.tailInsert(3);
    nodeList.tailInsert(4);
    nodeList.tailInsert(5);
    cout << nodeList << endl;

    return 0;
}
