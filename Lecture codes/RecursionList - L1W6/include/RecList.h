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

        void addOneTroughout() {head->addOneRecursive(); }

        void swapNodes(T data1, T data2)
        {
            swapNodesRecursive(head, NULL, data1, data2);
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

        ListNode<T>* swapNodesRecursive(ListNode<T>* node, ListNode<T>* swapNode, T data1, T data2){
            if(node == NULL)
                return NULL;
            if(node->data == data1 || node->data == data2){
                if(swapNode == NULL){
                    ListNode<T>* tmpNext = node->next;
                    swapNodesRecursive(node->next, node, data1, data2);

                    if(swapNode != NULL){
                        swapNode->next = tmpNext;
                        return swapNode;
                    }
                    else{
                        return node;
                    }
                }
                else{
                    swapNode->next = node->next;
                    swapNode = node;
                    return swapNode;
                }
            }
            node->next = swapNodesRecursive(node->next, swapNode, data1, data2);
            return node;
        }


};


#endif // LINKEDLIST_H

