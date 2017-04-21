#include <iostream>
#include "queue.h"
#include "animal.h"

class Animal
{
    public:
        virtual ~Animal(){}

        virtual void makeSound() = 0;
        virtual void print(ostream &outs) = 0;

        friend ostream& operator <<(ostream& outs, Animal* &animal)
        {
            animal->print(outs);
            return outs;
        }
};

class Cat: public Animal
{
    public:
        Cat(){}
        virtual ~Cat(){}
        void makeSound(){cout << "Meow! "; }
        virtual void print(ostream &outs){outs << "Cat"; }
};

class Dog: public Animal
{
    public:
        Dog(){}
        virtual ~Dog(){}
        void makeSound(){cout << "Woof! "; }
        void print(ostream &outs){outs << "Dog"; }
};

class Bird: public Animal
{
    public:
        Bird(){}
        virtual ~Bird(){}
        void makeSound(){cout << "Tweet! "; }
        void print(ostream &outs){outs << "Bird"; }
};



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
