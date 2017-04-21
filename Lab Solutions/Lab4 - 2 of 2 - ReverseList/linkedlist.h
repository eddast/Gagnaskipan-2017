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
        void reverse(){
            if(head != NULL)
            {
                reverse_recursive(head, NULL, head->next);
            }
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
        void reverse_recursive(ListNode<T>* node, ListNode<T>* node_prev, ListNode<T>* node_next)
        {
            if(node == NULL)
            {
                tail = head;
                head = node_prev;
                return;
            }
            else
            {
                node_next = node->next;
            }
            node->next = node_prev;
            node_prev = node;

            reverse_recursive(node_next, node, node);
        }

        ListNode<T> *head;
        ListNode<T> *tail;

};


#endif // LINKEDLIST_H
