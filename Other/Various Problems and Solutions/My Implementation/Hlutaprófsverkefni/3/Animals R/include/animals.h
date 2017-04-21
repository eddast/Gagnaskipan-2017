class Animal
{
    public:
        virtual ~Animal(){}
        virtual void makeSound() = 0;
        virtual void printName(ostream& out) = 0;
        friend ostream& operator <<(ostream& out, Animal* &animal)
        {
            animal->printName(out);
            return out;
        }
};

class Dog: public Animal
{
    public:
        virtual ~Dog(){}
        void makeSound(){cout << "Woof! "; }
        void printName(ostream& out){out << "Dog";};
};

class Cat: public Animal
{
    public:
        virtual ~Cat(){}
        void makeSound(){cout << "Meow! "; }
        void printName(ostream& out){out << "Cat";};
};

class Bird: public Animal
{
    public:
        virtual ~Bird(){}
        void makeSound(){cout << "Tweet! "; }
        void printName(ostream& out){out << "Bird";};
};
