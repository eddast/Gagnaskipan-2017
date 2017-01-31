#ifndef SET_H
#define SET_H

#include <iostream>
using namespace std;

class Set
{
    public:
        //Constructor: constructs Set object
        Set();
        //Destructor: deletes dynamic memory
        virtual ~Set();
        //Adds elements to set
        void add(int n);
        //Boolean check if element exists in set
        bool exists(int n);
        //Overloading the out operator for Set object
        friend ostream& operator <<(ostream& outs, Set &currset);

    private:
        //The virtual Set is an arr of 8 elements
        //(Updated to dynamic array now)
        int *content;
        //Size of set, how many elements it holds
        int setSize;
        //capacity of set, how large it may get
        int capacity;
        //Increases memory capacity for our dynamic array
        //(Added when updated to dynamic array)
        void resizeArr();
};

#endif // SET_H
