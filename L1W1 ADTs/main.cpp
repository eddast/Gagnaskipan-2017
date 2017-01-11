
//L1,W1 9.1.17 ADTs: basic ADTs structure
//Updated to dynamic array based application in L2,W1 11.1.17

#include <iostream>
#include "Set.h"
using namespace std;

int main()
{
    cout << "GSKI - Abstract Data Types: SET" << endl
         << "L1 W1 9.1.17 (ADTs structure)" << endl
         << "L2 W1 9.1.17 (dynamic arrays)" << endl;
    cout << endl;

    //Construct a new set
    Set s1;
    //Add elements to set
    s1.add(1);
     s1.add(2);
      s1.add(3);
       s1.add(4);
    //Print set's elements
    cout << "Set elements: " << s1 << endl;
    //Does the set include 4?
    if(s1.exists(4)) {
        cout << "The set specified includes 4" << endl
             << endl;
    }
    s1.add(5);
     s1.add(6);
      s1.add(7);
       s1.add(8);
    //Filling up to initial capacity
    cout << "Added more elements" << endl
         << "Set elements: " << s1 << endl
         << "Array now up to it's initial capacity limit" << endl
         << endl;
    s1.add(9);
     s1.add(10);
      s1.add(11);
       s1.add(12);
    //Test: Can the set adjust it's capacity correctly?
    cout << "Added more elements" << endl
         << "Set elements: " << s1 << endl
         << endl;
    s1.add(13);
     s1.add(14);
      s1.add(15);
       s1.add(16);
        s1.add(17);
         s1.add(19);
          s1.add(20);
    //Further testing: can the set adjust it's capacity correctly?
    cout << "Added more elements" << endl
         << "Set elements: " << s1 << endl;
    cout << endl;
}
