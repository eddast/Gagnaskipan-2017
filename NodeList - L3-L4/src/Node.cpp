/* GSKI 2017
 * Lecture code
 * Linked list
 * Singular linked:
 * 01.16.17 - 18.01.17
 * Updated to doubly linked:
 * 23.01.17
 */

#include "Node.h"

Node::Node(int value, Node *next)
{
    this->next = next;    // Only one node in beginning
    this->value = value;
}

Node::~Node()
{
    //dtor
}

ostream& operator <<(ostream& outs, const Node& node)
{
    outs << "value: " << node.value << ", next: " << node.next << endl;
    return outs;
}
