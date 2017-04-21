#include <iostream>
#include <vector>

using namespace std;

class Car {

public:
    virtual ~Car(){};
    virtual void print(ostream &outs) {
        outs << "Car";
    }

    friend ostream &operator <<(ostream &outs, Car &car) {
        car.print(outs);
        return outs;
    }
};

class Toyota : public Car {

public:
    virtual ~Toyota(){};
    virtual void print(ostream &outs) {
        Car::print(outs);
        outs << ": Toyota";
    }
};

class Subaru : public Car {

public:
    virtual ~Subaru(){};
    virtual void print(ostream &outs) {
        Car::print(outs);
        outs << ": Subaru";
    }
};

class Corolla : public Toyota {

public:
    virtual ~Corolla(){};
    virtual void print(ostream &outs) {
        Toyota::print(outs);
        outs << " Corolla";
    }
};

class Yaris : public Toyota {

public:
    virtual ~Yaris(){};
    virtual void print(ostream &outs) {
        Toyota::print(outs);
        outs << " Yaris";
    }
};

class Forester : public Subaru {

public:
    virtual ~Forester(){};
    virtual void print(ostream &outs) {
        Subaru::print(outs);
        outs << " Forester";
    }
};

class ParkingLot {

public:
    virtual ~ParkingLot(){};

    void add(Car* car) {
        cars.push_back(car);
    }

    friend ostream &operator <<(ostream &outs, ParkingLot &lot) {
        for(unsigned int i = 0; i < lot.cars.size(); i++) {
            outs << *(lot.cars[i]) << endl;
        }
        return outs;
    }

private:
    vector<Car*> cars;
};

int main() {

    cout << endl;

    Car* car = new Car();
    cout << *car << endl;
    delete car;

    Toyota* toyota = new Toyota();
    cout << *toyota << endl;
    delete toyota;

    car = new Corolla();
    cout << *car << endl;
    delete car;

    cout << endl;

    ParkingLot parkingLot;
    parkingLot.add(new Car());
    parkingLot.add(new Corolla());
    parkingLot.add(new Yaris());
    parkingLot.add(new Car());
    parkingLot.add(new Toyota());
    parkingLot.add(new Car());
    parkingLot.add(new Forester());
    parkingLot.add(new Subaru());
    parkingLot.add(new Corolla());
    cout << parkingLot << endl;

    return 0;
}
