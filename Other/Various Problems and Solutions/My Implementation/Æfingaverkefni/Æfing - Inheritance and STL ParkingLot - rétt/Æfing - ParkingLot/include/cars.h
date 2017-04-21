#ifndef CARS_H
#define CARS_H
#include <vector>
#include <iostream>

using namespace std;
/*
// Base class
class Car
{
    public:
        virtual ~Car(){}
        // Virtual print function, meaning calling print can
        // either use this implementation or from derived classes
        // depending on instance
        virtual void print(ostream& out){out << "Car"; }

        // Overridden operator for << for car, including derived classes
        friend ostream& operator <<(ostream& out, Car &car)
        {
            car.print(out);
            return out;
        }
};

// Child class - inherits Car
class Toyota: public Car
{
    public:
        virtual ~Toyota(){}
        // Implements parent's print function
        // Is also a virtual function if Toyota's derived classes
        // implement the function in their scopes
        virtual void print(ostream& out){Car::print(out); out << ": Toyota"; }
};

// Child class - inherits Car
class Subaru: public Car
{
    public:
        virtual ~Subaru(){}
        // Implements parent's print function
        // Is also a virtual function if Toyota's derived classes
        // implement the function in their scopes
        void print(ostream& out){Car::print(out); out << ": Subaru"; }
};

// "Grandchild" class - inherits Toyota that inherits Car
class Corolla: public Toyota
{
    public:
        virtual ~Corolla(){}
        // Implements parent's print function
        // Not virtual because it has no children (derived classes)
        void print(ostream& out){Toyota::print(out); out << " Corolla"; }
};

// "Grandchild" class - inherits Toyota that inherits Car
class Yaris: public Toyota
{
    public:
        virtual ~Yaris(){}
        // Implements parent's print function
        // Not virtual because it has no children (derived classes)
        void print(ostream& out){Toyota::print(out); out << " Yaris"; }
};

// "Grandchild" class - inherits Subaru that inherits Car
class Forester: public Subaru
{
    public:
        virtual ~Forester(){}
        // Implements parent's print function
        // Not virtual because it has no children (derived classes)
        void print(ostream& out){Subaru::print(out); out << " Forester"; }
};

// Stores multiple cars (or more specifically car-pointers)
// in vector - can print cars that have been added to the parking lot
class ParkingLot
{
    public:
        virtual ~ParkingLot(){}
        void add(Car* car){cars.push_back(car); }

        // Writes out car-pointer vector
        friend ostream& operator <<(ostream& out, ParkingLot& parkinglot)
        {
            for(unsigned int i = 0; i < parkinglot.cars.size(); i++)
            {
                out << *(parkinglot.cars[i]) << endl;
            }
            return out;
        }

    private:
        // Vector storing car-pointers
        vector<Car*> cars;

};
*/
#endif // CARS_H
