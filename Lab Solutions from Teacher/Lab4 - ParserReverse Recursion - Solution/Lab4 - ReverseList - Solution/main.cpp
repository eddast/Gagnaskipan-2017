#include <fstream>
#include "linkedlist.h"

using namespace std;

int main() {

    ifstream fin;
    fin.open("test.txt");

    string inp;
    int param;
    LinkedList<int> *list = NULL;
    while(fin >> inp) {
        if (inp == "new") {
            cout << "Creating a new ReverseList" << endl;
            delete list;
            list = new LinkedList<int>();
        } else if (inp == "push_front") {
            fin >> param;
            cout << "Calling push_front(" << param << ")" << endl;
            list->push_front(param);
            cout << *list << endl;
        } else if (inp == "reverse") {
            try
            {
                cout << "Calling reverse()" << endl;
                cout << "Before reverse: " << *list << endl;
                list->reverse();
                cout << "After reverse: " << *list << endl;

            }
            catch(EmptyException) {
                cout << "Caught EmptyException" << endl;
            }
        } else {
            cout << "INVALID INPUT: " << inp << endl;
        }

    }
    delete list;

    fin.close();

    return 0;
}
