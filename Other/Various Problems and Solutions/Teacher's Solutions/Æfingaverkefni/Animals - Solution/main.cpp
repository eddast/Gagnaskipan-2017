#include <iostream>
#include "queue.h"

using namespace std;

class Animal{

public:
    virtual ~Animal(){}
    virtual void makeSound() = 0;

    virtual void print(ostream& outs) = 0;

    friend ostream& operator <<(ostream& outs, Animal *animal) {
        animal->print(outs);
        return outs;
    }

};

class Cat : public Animal {

public:
    virtual ~Cat(){}
    virtual void print(ostream& outs) {
        outs << "cat";
    }
    virtual void makeSound(){
        cout << "meow" << endl;
    }
};

class Dog : public Animal {

public:
    virtual ~Dog(){}
    virtual void print(ostream& outs) {
        outs << "dog";
    }
    virtual void makeSound(){
        cout << "woof" << endl;
    }
};

class Bird : public Animal {

public:
    virtual ~Bird(){}
    virtual void print(ostream& outs) {
        outs << "bird";
    }
    virtual void makeSound(){
        cout << "tweet" << endl;
    }
};

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
