#ifndef STACK_H
#define STACK_H

#include "linkedlist.h"

template <class T>
class Stack
{
    public:
        Stack() {}
        virtual ~Stack() {}

        void push(T value) {
            lis.push_front(value);
        }
        T pop() {
            return lis.pop_front();
        }

        friend ostream& operator <<(ostream& outs, const Stack<T> &stac) {
            outs << stac.lis;
            return outs;
        }

    protected:

    private:
        LinkedList<T> lis;
};

#endif // STACK_H

