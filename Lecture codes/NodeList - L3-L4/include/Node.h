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
#include "Game.h"

using namespace std;

// The ADT for node
class Node
{
    public:
        // Constructs a single node with corresponding values
        Node(Game game, Node *next, Node *prev){this->game = game; this->next = next; this->prev = prev;}

        Game game;
        // Pointers
        Node *next;
        Node *prev;

    private:

};

#endif // NODE_H
