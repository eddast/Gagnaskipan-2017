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
        // Constructor
        LinkedList()
        {
            // Only one node because list is singly linked
            head = new Node<T>();
            // Nothing in list besides head
            size = 0;
        }

        // Destructor
        virtual ~LinkedList()
        {
            // Clears nodes in list
            clearList();
            // Deletes head and sets to NULL
            delete head;
            head = NULL;
        }

        // Inserts at back of list
        void tailInsert(T value)
        {
            // The new node created and value assigned
            Node<T>* newNode = new Node<T>;
            // Fixing connections
            newNode->data = value;
            newNode->next = NULL;
            // Temp created that points to head
            Node<T>* tempNode = head;

            if(!isEmpty())
            {
                // Iterate to end of list
                while (tempNode->next != NULL)
                {
                    tempNode = tempNode->next;
                }

                // Last element set to new node
                tempNode->next = newNode;
            }
            // For an empty list, new node set besides head
            else
            {
                head->next = newNode;
            }
            // Size naturally increases by one
            size++;
        }

        // Inserts in front of list
        void headInsert(T value)
        {
            // New node created with value as it's data
            Node<T>* newNode = new Node<T>;
            newNode->data = value;

            // Fixing connections
            newNode->next = head->next;
            head->next = newNode;

            // Size increased by one
            size++;
        }

        T headRemove()
        {
            // Throws exception if list is empty
            checkEmpty();

            // New pointer to first node created
            // NOT initiated as  = new Node because
            // Deleted anyway in same function
            Node<T>* tempPtr = head->next;
            // Storing value to be removed
            T removedVal = tempPtr->data;
            // Fixing connections
            head->next = tempPtr->next;
            // Deleting pointer
            delete tempPtr;
            // Size decreases
            size--;

            return removedVal;
        }

        // Clears everything from list but head node
        void clearList()
        {
            // No action if list is empty already
            if(!isEmpty())
            {
                // NOT initiated as "Node* node = new Node" because
                // Deleted anyway in same function
                Node<T>* tempPtr = head->next;
                // While in scope of list
                while(tempPtr != NULL)
                {
                    // Head->next pointer fixed and node deleted
                    // Repeated until list is empty
                    head->next = tempPtr->next;
                    delete tempPtr;
                    tempPtr = head->next;
                }
                // List size now 0
                size = 0;
            }
        }

        friend ostream& operator <<(ostream& outs, LinkedList<T>& lis)
        {
            // New node as first node
            Node<T>* node = lis.head->next;
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
        Node<T>* head;
        int size;
        // Checks if list is empty (only head node)
        bool isEmpty()
        {
            return size == 0;
        }

        // Throws exception if list is empty
        void checkEmpty()
        {
            if(isEmpty())
            {
                throw EmptyException();
            }
        }
};

#endif // LINKEDLIST_H
