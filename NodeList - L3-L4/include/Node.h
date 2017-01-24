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

class Node
{
    public:
        Node(int value, Node *next);
        virtual ~Node();
        int value;
        Node *next;

        friend ostream& operator <<(ostream& outs, const Node& node);

    private:

};

#endif // NODE_H
