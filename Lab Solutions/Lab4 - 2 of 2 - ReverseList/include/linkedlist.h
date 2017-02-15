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

        // This is the public reverse function, called from the outside
        // Note that you can make another, private, reverse function
        // that does the actual RECURSION.  It may take a parameter
        // and/or return a value/reference/pointer to aid the process.
        // This function then calls the private function once
        // while the private function does all the actual work.
        void reverse(){
            // Initializing two pointers that will "iterate" recursively to be swapped
            // P1 points to first node and P2 points to second node initially
            ListNode<T>* P1 = head;
            ListNode<T>* P2 = head->next;
            ListNode<T>* prev = NULL;
            // pointer to prev initialized
            // NULL at beginning since we begin in front of the list
            // Node<T>* prev = NULL;

            // With these values we call for the recursive function
            // that "iterates" recursively through list and swaps values
            reverseRecursive(P1, P2, NULL);
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

        // "Iterates" recursively through list, swapping two values at a time
        void reverseRecursive(ListNode<T> *P1, ListNode<T> *P2, ListNode<T> *prev)
        {

        }

};


#endif // LINKEDLIST_H
