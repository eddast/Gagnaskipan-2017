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
    // TESTING NodeList
    NodeList nodeList;


    // Testing empty exception
    try
    {
        nodeList.peekHead();
    }
    catch(EmptyException)
    {
        cout << "List is empty, no head node." << endl;
    }
   /* // Testing Head Insert - Stacking
    nodeList.headInsert(1);
    nodeList.headInsert(2);
    nodeList.headInsert(3);
    nodeList.headInsert(4);
    nodeList.headInsert(5);
    cout << "list: " << nodeList << endl;
    cout << "current head: " << nodeList.peekHead() << endl;
    cout << "current tail: " << nodeList.peekTail() << endl;
    // Testing Tail insert - inserting last
    nodeList.tailInsert(1);
    nodeList.tailInsert(2);
    nodeList.tailInsert(3);
    nodeList.tailInsert(4);
    nodeList.tailInsert(5);
    cout << "list: " << nodeList << endl;
    cout << "current head: " << nodeList.peekHead() << endl;
    cout << "current tail: " << nodeList.peekTail() << endl;

    //Testing headRemove function
    try
    {
        cout << "Calling headRemove" << endl;
        nodeList.headRemove();
        cout << "list: " << nodeList << endl;
        cout << "current head: " << nodeList.peekHead() << endl;
        nodeList.headRemove();
        cout << "list: " << nodeList << endl;
        cout << "current head: " << nodeList.peekHead() << endl;

    }
    catch(EmptyException){
        cout << "List empty!" << endl;
    }

    //Testing tailRemove func
    try
    {
        cout << "Calling tailRemove" << endl;
        nodeList.tailRemove();
        cout << "list: " << nodeList << endl;
        cout << "current tail: " << nodeList.peekTail() << endl;
        nodeList.tailRemove();
        cout << "list: " << nodeList << endl;
        cout << "current tail: " << nodeList.peekTail() << endl;

    }
    catch(EmptyException){
        cout << "List empty!" << endl;
    }*/
    nodeList.insert(1);
    cout << "list: " << nodeList << endl;
    nodeList.insert(2);
    cout << "list: " << nodeList << endl;
    nodeList.insert(3);
    cout << "list: " << nodeList << endl;
    nodeList.insert(4);
    cout << "list: " << nodeList << endl;
    nodeList.insert(5);
    cout << "list: " << nodeList << endl;
    nodeList.moveToPrevious();
    nodeList.moveToPrevious();
    nodeList.insert(11);
    cout << "list: " << nodeList << endl;

    return 0;
}
