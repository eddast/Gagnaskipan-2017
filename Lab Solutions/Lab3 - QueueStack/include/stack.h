#include <iostream>
#include "linkedlist.h"
#include <string>
#ifndef STACK_H
#define STACK_H

using namespace std;

template <class T>
class Stack
{
    public:
        Stack(){}
        virtual ~Stack(){}

        // FIFO: Inserts at front, removes first element
        void push(T value){sta.headInsert(value); }
        T pop(){return sta.headRemove(); }

        friend ostream& operator <<(ostream& outs, Stack<T>& lis){outs << lis.sta; return outs; }

    private:
        // "Stack" instance of the LinkedList implementation
        LinkedList<T> sta;
};

#endif // STACK_H
