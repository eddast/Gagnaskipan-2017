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
    tail = NULL;

}

NodeList::~NodeList()
{
    Node *node = head;
    while(node->next != NULL)
    {
        head = node;
        node = node->next;
        delete head;
    }
    head = NULL;
    tail = NULL;
}

void NodeList::headInsert(int n){

    // New node points to first node in list (next is value head points to)
    Node *node = new Node(n, head);
    if(head == NULL)
    {
        // If head is NULL, empty list, tail and head point
        // both to node
        tail = node;
    }
    // Head now points to node - node added!
    head = node;
}

void NodeList::tailInsert(int n){
    // Special case: empty list's head points to new node
    if(head == NULL){
        headInsert(n);
        return;
    }
    // New node with next as null
    Node *node = new Node(n,NULL);
    // Tail->next set as node
    tail->next = node;
    // Tail now moved to node
    tail = node;
}

int NodeList::peekHead() const
{
    checkEmpty();

    return head->value;
}

int NodeList::peekTail() const
{
    checkEmpty();

    return tail->value;
}

bool NodeList::isEmpty() const
{
    return (head == NULL);
}

void NodeList::checkEmpty() const
{
    if (isEmpty())
    {
        throw EmptyException();
    };
}

void NodeList::headRemove()
{
    checkEmpty();

    Node *node = head;
    head = head->next;
    delete node;

    if(head == NULL){
        tail = NULL;
    }
}

void NodeList::tailRemove()
{

}

ostream& operator <<(ostream& out, const NodeList& list){

    // Node is head of list
    Node *node = list.head;

    // While list "lasts"
    while(node != NULL){
        out << node->value;
        if (node->next != NULL)
        {
            out << ", ";
        }
        node = node->next;
    }
    return out;
}
