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


        ///THIS IS WHERE THE REVERSING STARTS
        ///THE ACTUAL RECURSION HAPPENS IN
        ///THE PRIVATE FUNCTION

        void reverse(){
            if(head == NULL){
                throw EmptyException();
            }
            //set the tail to the current head,
            //once it returns itself with the
            //reversed direction of links
            tail = reverse(head);
            //set the new tail's next-link to NULL
            tail->next = NULL;
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


        ///THIS IS THE RECURSION PROPER

        ListNode<T>* reverse(ListNode<T> *node){
            if (node->next == NULL) {
                //If we're at the tail, set the head to the tail.
                head = node;
                return node;
            }
            else{
                //Recurr for next node, so it will
                //go all the way to the end before
                //beginning to switch links
                //When a node is returned, its
                //next-link is set to this node,
                //switching the direction of the
                //link between them.
                reverse(node->next)->next = node;
                return node;
            }
        }

        ListNode<T> *head;
        ListNode<T> *tail;


};


#endif // LINKEDLIST_H
