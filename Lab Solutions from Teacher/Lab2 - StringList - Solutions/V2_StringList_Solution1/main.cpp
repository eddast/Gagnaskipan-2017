#include <iostream>
#include "StringList.h"

using namespace std;

int main() {

    StringList list1;

    list1.append("fic");
    list1.append("sdf");
    list1.append("wet");
    list1.append("fgh");
    list1.move_to_pos(2);
    cout << list1 << endl;
    list1.clear();
    list1.insert("pod");
    cout << list1 << endl;
    list1.prev();
    list1.append("bxph");
    cout << list1 << endl;
    list1.next();
    cout << list1 << endl;
    try{
        list1.remove();
        cout << list1 << endl;
    }catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException" << endl;
    }

    try{
        list1.remove();
        cout << list1 << endl;
    }catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException" << endl;
    }
    cout << list1 << endl;
    list1.prev();

    cout << list1 << endl;
    list1.insert("ah");

    cout << list1 << endl;

    list1.next();
    cout << list1 << endl;
    list1.next();

    cout << list1 << endl;
    list1.prev();

    cout << list1 << endl;
    list1.append("z");
    cout << list1 << endl;
}

