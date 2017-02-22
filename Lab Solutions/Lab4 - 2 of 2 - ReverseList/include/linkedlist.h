#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef>
#include <iostream>
#include "queue.h"
#include "stack.h"
#include "listnode.h"

using namespace std;

class EmptyException { };

template <class T>
class LinkedList : public Queue<T>, public Stack<T>
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

        void push(T value) {
            head = new ListNode<T>(value, head);
            if(tail == NULL) {
                tail = head;
            }
        }

        void add(T value) {
            if(head == NULL) {
                push(value);
            }
            else {
                ListNode<T> *newNode = new ListNode<T>(value, NULL);
                tail->next = newNode;
                tail = newNode;
            }
        }

        T pop() {
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

        T remove(){
            return pop();
        }

        void print(ostream& outs) const{
            ListNode<T> *tmpNode = head;
            while(tmpNode != NULL) {
                outs << tmpNode->data << " ";
                tmpNode = tmpNode->next;
            }
        }

        friend ostream& operator <<(ostream& outs, const LinkedList<T> &lis) {
            lis.print(outs);
            return outs;
        }

    private:
        ListNode<T> *head;
        ListNode<T> *tail;
};


#endif // LINKEDLIST_H
