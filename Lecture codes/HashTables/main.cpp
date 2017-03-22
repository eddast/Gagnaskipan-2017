#include <iostream>
#include <random>
#include <ctime>
#include "hashtable.h"

using namespace std;

///* TEST FUNCTION TO TEST FIND
void test_find(HashTable<int> h, string key)
{
    try{
        cout << "value for key " << key << ": " << h.find(key) << endl;
    }
    catch(ElementNotFoundException e){
        cout << "Element not found in table with key " << key << endl;
    }
}

///* TRYING OUT RAND() AND SRAND()
int generate_random()
{
    srand(time(NULL));
    int r = rand() % 10;

    return r;
}

int main()
{
    ///* INPUTTING IN HASHMAP
    HashTable<int> h;
    h.insert("five", 5);
    h.insert("two", 2);
    h.insert("six", 6);
    h.insert("three", 3);
    h.insert("one", 1);
    h.insert("four", 4);

    ///* TESTING FIND IN HASHMAP
    test_find(h, "five");
    test_find(h, "one");
    test_find(h, "six");
    test_find(h, "seven");

    ///* TRYING OUT RAND() AND SRAND()
    cout << "\nA few random values from 0-10: " << endl;
    cout << "number: " << generate_random() << endl;
    cout << "number: " << generate_random() << endl;

    return 0;
}
