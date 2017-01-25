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
    head = new Node (0, NULL, NULL);
    tail = new Node (0, NULL, head);
    head->next = tail;
    curr = tail;
    size = 0;
    currPos = 0;

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
/*
void NodeList::headInsert(int n){

    // New node points to first node in list (next is value head points to)
    Node *node = new Node(n, head, NULL);
    if(head == NULL)
    {
        // If head is NULL, empty list, tail and head point
        // both to node
        tail = node;
    }
    // Head now points to node - node added!
    else
    {
        head->prev = node;
    }
    head = node;
}

void NodeList::tailInsert(int n){
    // Special case: empty list's head points to new node
    if(head == NULL){
        headInsert(n);
        return;
    }
    // New node with next as null and prev as tail
    Node *node = new Node(n, NULL, tail);
    // Tail->next set as node
    tail->next = node;
    // Tail now moved to node
    tail = node;
}
*/

void NodeList::insert(int n){
    Node *node = new Node (n, curr, curr->prev);

    curr->prev->next = node;
    curr->prev = node;

    size++;
    currPos++;
}
void NodeList::remove(int n)
{   if(currPos == size)
    {
    return;
    }

    Node *node = curr;
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    curr = curr->next;

    size--;

    delete node;
}

void NodeList::moveToPrevious()
{
    if(currPos >= 0)
    {
        curr = curr->prev;
        currPos--;
    }
}

void NodeList::moveToNext()
{
    if(currPos < size)
    {
        curr = curr->next;
        currPos++;
    }
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
    return (size == 0);
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
    head->prev = NULL;
    delete node;

    if(head == NULL){
        tail = NULL;
    }
}

void NodeList::tailRemove()
{
    checkEmpty();

    Node *node = tail;
    tail = tail->prev;
    if(tail == NULL){
          head = NULL;
    }
    else{
        tail->next = NULL;
    }
    delete node;
}

ostream& operator <<(ostream& out, const NodeList& list){

    // Node is head of list
    Node *node = list.head->next;

    // While list "lasts"
    while(node->next != NULL){
        out << node->value;
        if (node->next != NULL)
        {
            out << ", ";
        }
        node = node->next;
    }
    return out;
}
