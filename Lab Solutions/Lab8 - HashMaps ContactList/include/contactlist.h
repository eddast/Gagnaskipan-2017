#ifndef CONTACTLIST_H
#define CONTACTLIST_H
#include "ContactNode.h"

class ContactList
{
    public:
        // Constructor of an empty linked list
        ContactList() : head(NULL), tail(NULL), size(0) {}

        // Destructor
        virtual ~ContactList()
        {
            // Clears nodes in list
            NodePtr tmp = head;
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
        void tailInsert(string key, Contact value)
        {
            // The new node created and value assigned, next is NULL
            NodePtr newNode = new ContactNode(key, value, NULL);
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

        // Inserts at back of list
        void tailInsert(StringContactPair data)
        {
            // The new node created and value assigned, next is NULL
            NodePtr newNode = new ContactNode(data, NULL);
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
        void headInsert(StringContactPair data)
        {
            // New node created with value as it's data and head as next
            NodePtr newNode = new ContactNode(data, head);
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

        // Inserts in front of list
        void headInsert(string key, Contact value)
        {
            // New node created with value as it's data and head as next
            NodePtr newNode = new ContactNode(key, value, head);
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
        void headRemove()
        {
            // Throws exception if list is empty
            checkEmpty();

            // New pointer to first node created
            // NOT initiated as  = new Node because
            // Deleted anyway in same function
            NodePtr tempPtr = head;
            // Fixing connections
            head = tempPtr->next;
            // Deleting pointer
            delete tempPtr;
            // Size decreases
            size--;
        }

        friend ostream& operator <<(ostream& outs, LinkedList<T>& lis)
        {
            // New node as first node
            NodePtr node = lis.head;
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
        NodePtr head;
        NodePtr tail;
        // Size of list
        int size;
        // Checks if list is empty (only head node)
        bool isEmpty(){return size == 0; }
        // Throws exception if list is empty
        void checkEmpty(){if(isEmpty()){throw EmptyException(); }}
};

typedef ContactList* ListPtr;

#endif // CONTACTLIST_H
