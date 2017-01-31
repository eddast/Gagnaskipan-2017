#include "Set.h"

const int INITIAL_CAPACITY = 8;

Set::Set(){
    setSize = 0;
    capacity = INITIAL_CAPACITY;
    content = new int[capacity];
}

Set::~Set(){
    if (content != NULL)
        delete[] content;
}

//Add to set
void Set::add(int n){
    if (exists(n)){
        return;
    }
    if (setSize == capacity){
        cout << "Resizing array capacity..." << endl;
        resizeArr();
        cout << "Capacity resized." << endl;
    }

    content[setSize] = n;
    setSize++;
}

//Boolean check if element exists
bool Set::exists(int n){
    for (int i = 0; i < setSize; i++){
        if(content[i] == n)
            return true;
    }
    return false;
}

//Increases memory capacity for our dynamic array
void Set::resizeArr(){
    capacity = capacity * 2;            //capacity doubled for Array
    int *tmpArr = new int[capacity];    //tmpArr with more capacity created

    for (int i = 0; i >= setSize; i++)  //Copy from content
        tmpArr[i] = content[i];

        delete[] content;               //content "deleted"
        content = new int[capacity];    //then created as new with double capacity

        content = tmpArr;              //change content to tmpArr -> more memory
}

//Operator overloading for << operator
ostream& operator <<(ostream& outs, Set &currset){
    for (int i = 0; i < currset.setSize; i++)
    {
        outs << currset.content[i] << " ";
    }
    return outs;
}

