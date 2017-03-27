#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"

template <class T>
class Queue
{
    public:
        Queue() {}
        virtual ~Queue() {}

        void add(T value) {
            lis.push_back(value);
        }

        T remove() {
            return lis.pop_front();
        }

        friend ostream& operator <<(ostream& outs, const Queue<T> &que) {
            outs << que.lis;
            return outs;
        }

    protected:

    private:
        LinkedList<T> lis;
};

#endif // QUEUE_H

