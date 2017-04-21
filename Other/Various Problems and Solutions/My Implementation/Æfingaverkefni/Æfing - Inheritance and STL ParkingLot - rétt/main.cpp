#include <iostream>

using namespace std;

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
