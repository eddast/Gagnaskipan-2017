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

using namespace std;


class NodeList
{
    public:
        NodeList();
        virtual ~NodeList();

        void headInsert(int n);
        void tailInsert(int n);

        friend ostream& operator <<(ostream& out, const NodeList& list);

        // This for some reason needed to be public
        // Is however private in lecture
        Node *head;


    protected:

    private:
};

#endif // NODELIST_H
