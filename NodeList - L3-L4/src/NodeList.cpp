/* GSKI 2017
 * Lecture code
 * Linked list
 * Singular linked:
 * 01.16.17 - 18.01.17
 * Updated to doubly linked:
 * 23.01.17
 */

#include "NodeList.h"

using namespace std;

NodeList::NodeList()
{
    // Initializes empty list
    head = NULL;

}

NodeList::~NodeList()
{
    //dtor
}

void NodeList::headInsert(int n){

    // New node points to first node in list (next is value head points to)
    Node *node = new Node(n, head);
    // Head now points to node - node added!
    head = node;
}

void NodeList::tailInsert(int n){
    // Very simple at this point!
    // New node points to NULL because it's the last node
    Node *newNode = new Node(n, NULL);
    // Special case: empty list's head points to new node
    if(head == NULL){
        headInsert(n);
        return;
    }

    Node *node = head;

    while(node->next != NULL){
        node = node->next;
    }
    node->next = newNode;
}

ostream& operator <<(ostream& out, const NodeList& list){

    // Node is head of list
    Node *node = list.head;

    // While list "lasts"
    while(node != NULL){
        out << ", " << node->value;
        node = node->next;
    }
    out << endl;
    return out;
}
