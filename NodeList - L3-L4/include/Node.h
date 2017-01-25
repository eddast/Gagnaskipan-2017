/* GSKI 2017
 * Lecture code
 * Linked list
 * Singular linked:
 * 01.16.17 - 18.01.17
 * Updated to doubly linked:
 * 23.01.17
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

// The ADT for node
class Node
{
    public:
        Node(int value, Node *next, Node *prev){this->next = next; this->prev = prev; this->value = value;}
        int value;
        Node *next;
        Node *prev;

    private:

};

#endif // NODE_H
