#include <iostream>
#include <vector>

using namespace std;

class Car
{
    public:
        virtual ~Car(){}
        virtual void print(ostream& out){
            out << "Car";
        }
        friend ostream& operator <<(ostream& out, Car &car)
        {
            car.print(out);
            return out;
        }
};

class Toyota : public Car
{
    public:
        virtual ~Toyota(){}
        virtual void print(ostream& out){
            Car::print(out);
            out << ": Toyota";
        }
};

class Subaru : public Car
{
    public:
        virtual ~Subaru(){}
        virtual void print(ostream& out){
            Car::print(out);
            out << ": Subaru";
        }
};

class Yaris : public Toyota
{
    public:
        virtual ~Yaris(){}
        virtual void print(ostream& out){
            Toyota::print(out);
            out << ": Yaris";
        }
};

class Corolla : public Toyota
{
    public:
        virtual ~Corolla(){}
        virtual void print(ostream& out){
            Toyota::print(out);
            out << ": Corolla";
        }
};

class Forester : public Subaru
{
    public:
        virtual ~Forester(){}
        virtual void print(ostream& out){
            Subaru::print(out);
            out << ": Forester";
        }
};

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

class machine
{
public:
    virtual ~machine(){}
    virtual void do_something() = 0;
    int check_tmp(){return cc; }
private:
    int cc = 9;
};

class plane : public machine
{
public:
    virtual ~plane(){}
    void do_something(){cout << "I'm flying!" << endl;}
};

class bill : public machine
{
public:
    virtual ~bill(){}
    void do_something(){cout << "I'm driving!" << endl;}
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

    bill c;
    c.do_something();
    cout << c.check_tmp();
    plane p;
    p.do_something();
    cout << p.check_tmp();

    //machine m;
    //cout << m.check_tmp();

    return 0;
}
