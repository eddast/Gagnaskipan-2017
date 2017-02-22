#include <iostream>
#include "linkedlist.h"
#include <string>
#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

template <class T>
class Queue
{
    public:
        Queue(){}
        virtual ~Queue(){}

        // LIFO: Inserts at back, removes first element
        void add(T value) {que.tailInsert(value); }
        T remove() {return que.headRemove(); }

        friend ostream& operator <<(ostream& outs, Queue<T>& lis){outs << lis.que; return outs; }

    private:
        // "Queue" instance of the LinkedList implementation
        LinkedList<T> que;
};

#endif // QUEUE_H
