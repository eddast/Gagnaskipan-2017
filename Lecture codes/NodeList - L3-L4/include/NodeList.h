/* GSKI 2017
 * Lecture code
 * Linked list
 * Singular linked:
 * 01.16.17 - 18.01.17
 * Updated to doubly linked:
 * 23.01.17
 */

#ifndef NODELIST_H
#define NODELIST_H
#include "Node.h"
#include <iostream>
#include "Game.h"

using namespace std;

class EmptyException{};

// Actions for the node ADT (functions)
// Constucts lists
class NodeList
{
    public:
        NodeList();
        virtual ~NodeList();

        // Inserts node to list with value n
        //void headInsert(int n);
        //void tailInsert(int n);
        void insert(Game Game);
        void remove();
        void moveToPrevious();
        void moveToNext();

        // Returns value of head/tail, makes no changes to list
        Game peekHead() const;
        Game peekTail() const;

        // Removes first/last node
        void headRemove();
        void tailRemove();

        // True if list is empty
        bool isEmpty() const;

        // Overriding << operator
        friend ostream& operator <<(ostream& out, const NodeList& list);

        // This for some reason needed to be public
        // Is however private in lecture
        Node *head;
        Node *tail;
        Node *curr;

    private:
        // Results in exception if list is empty
        void checkEmpty() const;
        int size;
        int currPos;
};

#endif // NODELIST_H
