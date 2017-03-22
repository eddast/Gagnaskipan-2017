#include <iostream>
#include "InteractivePhoneBook.h"

int main()
{
    /*InteractivePhoneBook pb;
    pb.start();*/

    ContactList clist;
    clist.add("Lavada Moore", Contact());
    clist.add("Edda Steinunn", Contact());
    cout << "Two in list: " << endl;
    cout << clist << endl;
    clist.get("Edda Steinunn");
    cout << "One in list: " << endl;
    clist.remove("Lavada Moore");
    cout << clist << endl;

    return 0;
}

