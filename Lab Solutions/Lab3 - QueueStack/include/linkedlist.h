#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <iostream>
using namespace std;

class EmptyException{};

template <class T>
struct Node
{
    // Node has some type data and pointer to next node
    T data;
    Node<T>* next;

    // Default node has empty data and NULL as next node
    Node() : data(), next(NULL) { }
    // Node with values initiated
    Node(T val, Node *next = NULL)
    : data(val), next(next) { }
};

template <class T>
class LinkedList
{
    public:
        // Constructor of an empty linked list
        LinkedList() : head(NULL), tail(NULL), size(0) {}

        // Destructor
        virtual ~LinkedList()
        {
            // Clears nodes in list
            Node<T>* tmp = head;
            while (tmp != NULL)
            {
                tmp = tmp->next;
                delete head;
                head = tmp;
            }
            // preventing dangling pointers
            head = NULL;
            tail = NULL;
        }

        // Inserts at back of list
        void tailInsert(T value)
        {
            // The new node created and value assigned, next is NULL
            Node<T>* newNode = new Node<T>(value, NULL);
            // If list is empty, head points to new node
            if (size == 0)
            {
                head = newNode;
            }
            // If list is not empty, last node points to new node
            else
            {
                tail->next = newNode;
            }
            // And in any case, tail becomes new node
            tail = newNode;

            // Size naturally increases by one
            size++;
        }

        // Inserts in front of list
        void headInsert(T value)
        {
            // New node created with value as it's data and head as next
            Node<T>* newNode = new Node<T>(value, head);
            // Head now points to new node
            head = newNode;
            // If list was empty, node is first and last so tail points to node, too
            if(size == 0)
            {
                tail = newNode;
            }

            // Size increased by one
            size++;
        }

        // Removes first element of list
        T headRemove()
        {
            // Throws exception if list is empty
            checkEmpty();

            // New pointer to first node created
            // NOT initiated as  = new Node because
            // Deleted anyway in same function
            Node<T>* tempPtr = head;
            // Storing value to be removed
            T removedVal = tempPtr->data;
            // Fixing connections
            head = tempPtr->next;
            // Deleting pointer
            delete tempPtr;
            // Size decreases
            size--;

            return removedVal;
        }

        friend ostream& operator <<(ostream& outs, LinkedList<T>& lis)
        {
            // New node as first node
            Node<T>* node = lis.head;
            while(node != NULL){
                // Outputs data of nodes while iterating through list
                outs << node->data;
                if (node->next != NULL)
                {
                    outs << " ";
                }
                node = node->next;
            }
            return outs;
        }

    private:
        // Head and tail pointers, determining first and last node
        Node<T>* head;
        Node<T>* tail;
        // Size of list
        int size;
        // Checks if list is empty (only head node)
        bool isEmpty(){return size == 0; }
        // Throws exception if list is empty
        void checkEmpty(){if(isEmpty()){throw EmptyException(); }}
};

#endif // LINKEDLIST_H
