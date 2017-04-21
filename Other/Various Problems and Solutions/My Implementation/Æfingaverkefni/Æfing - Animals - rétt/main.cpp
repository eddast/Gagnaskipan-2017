#include <iostream>
#include "queue.h"

using namespace std;

int main() {

    Queue<Animal*> q;


    q.add(new Dog());
    q.add(new Cat());
    q.add(new Bird());
    q.add(new Bird());
    q.add(new Dog());
    q.add(new Bird());
    q.add(new Cat());

    ///Must overload ostream << operator for
    ///Animal* (POINTER), for this to write
    ///out "cat dog dog bird..."
    cout << q << endl;

    Animal *animal;
    try {
        while(true) {
            animal = q.remove();
            ///Must overload makeSound for each animal
            ///and make sure it's virtual so the correct
            ///animal sound is output
            animal->makeSound();
            delete animal;
        }
    }
    catch(EmptyException) {
    }

}
