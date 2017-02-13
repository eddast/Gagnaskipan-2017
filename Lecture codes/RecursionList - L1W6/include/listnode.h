#ifndef LISTNODE_H
#define LISTNODE_H

template <class T>
class ListNode
{
    public:
        T data;
        ListNode<T> *next;

        ListNode(T value, ListNode<T> *next) : data(value), next(next) {}

        void addOneRecursive(){
            data++;
            if(next != NULL)
                next->addOneRecursive();
        }

};

#endif // LISTNODE_H

