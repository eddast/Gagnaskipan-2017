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

        void push(T value){sta.headInsert(value); }
        T pop(){return sta.headRemove(); }
        friend ostream& operator <<(ostream& outs, Stack<T>& lis){outs << lis.sta; return outs; }
    private:
        LinkedList<T> sta;
};

#endif // STACK_H
