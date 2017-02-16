#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef>
#include <iostream>

#include "listnode.h"

using namespace std;

class EmptyException { };

template <class T>
class LinkedList
{
    public:
        LinkedList() {
            head = NULL;
            tail = NULL;
        }

        virtual ~LinkedList() {
            ListNode<T> *tmp = head;
            while(head != NULL) {
                head = head->next;
                delete tmp;
                tmp = head;
            }
            head = NULL;
            tail = NULL;
        }

        void push_front(T value) {
            head = new ListNode<T>(value, head);
            if(tail == NULL) {
                tail = head;
            }
        }

        void push_back(T value) {
            if(head == NULL) {
                push_front(value);
            }
            else {
                ListNode<T> *newNode = new ListNode<T>(value, NULL);
                tail->next = newNode;
                tail = newNode;
            }
        }

        T pop_front() {
            if(head == NULL) {
                throw EmptyException();
            }
            T data = head->data;
            ListNode<T> *tmpNode = head;
            head = head->next;
            if(head == NULL) {
                tail = head;
            }
            delete tmpNode;
            return data;
        }

        // Only serves as an initiator of parameters
        // and as an empty check
        void reverse(){
            // Exception thrown if user tries reversing an empty list
            if (head == NULL){throw EmptyException(); }
            // Calls function that recursively reverses list
            else {reverseRecursive(head, NULL, NULL); }
        }

        friend ostream& operator <<(ostream& outs, const LinkedList<T> &lis) {
            ListNode<T> *tmpNode = lis.head;
            while(tmpNode != NULL) {
                outs << tmpNode->data << " ";
                tmpNode = tmpNode->next;
            }
            return outs;
        }

    private:
        ListNode<T> *head;
        ListNode<T> *tail;

        ListNode<T>* reverseRecursive(ListNode<T> *node, ListNode<T> *nodeprv, ListNode<T> *nodenext)
        {
            // Base case: node returned if node has become NULL, i.e. list end is reached
            // thus, ending the whole recursive algorithm
            if(node == NULL)
            {
                // Fixing head and tail
                tail = head;
                head = nodeprv;
                return node;
            }
            // If we're not ready to end loop, nodenext set
            else
            {
                nodenext = node->next;
            }
            // Next of node points to prev
            node->next = nodeprv;

            // previous node set to current node and node set to next node
            // for next recursive call
            nodeprv = node;
            node = nodenext;

            return reverseRecursive(node, nodeprv, nodenext);
        }

};


#endif // LINKEDLIST_H
