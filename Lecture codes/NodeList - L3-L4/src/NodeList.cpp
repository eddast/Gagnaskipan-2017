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
    head = new Node (Game(), NULL, NULL);
    tail = new Node (Game(), NULL, head);
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

void NodeList::insert(Game){
    Node *node = new Node (Game(), curr, curr->prev);

    curr->prev->next = node;
    curr->prev = node;

    size++;
    currPos++;
}
void NodeList::remove()
{   if(currPos == size)
    {
    return;
    }

    Node *node = curr;
    // Cut the connection betwee    // Cut the connection between curr+1 to curr
    // Now it points to curr-1n curr+1 to curr
    // Now it points to curr-1 as prev
    curr->prev->next = curr->next;
    // Cut the connection between curr-1 to curr
    // Now it points to curr+1 as next
    curr->next->prev = curr->prev;
    curr = curr->next;

    delete curr;
    curr = node;

    size--;
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

Game NodeList::peekHead() const
{
    checkEmpty();

    return head->game;
}

Game NodeList::peekTail() const
{
    checkEmpty();

    return tail->game;
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
        out << node->game;
        if (node->next != list.tail)
        {
            out << ", ";
        }
        node = node->next;
    }
    return out;
}
