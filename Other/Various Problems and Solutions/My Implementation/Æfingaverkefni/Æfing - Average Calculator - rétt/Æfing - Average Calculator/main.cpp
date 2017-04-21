#include <iostream>
#include "averagecalculator.h"
#include "factoraveragecalculator.h"

using namespace std;

int main(int argc, char **argv)
{

    AverageCalculator avg;
    avg.addNumber(1.0);
    avg.addNumber(3.0);
    avg.addNumber(2.0);
    avg.addNumber(4.0);
    avg.addNumber(2.0);

    cout << "Should be 2.4: " << avg.calculateAverage() << endl;

    FactorAverageCalculator favg(2);
    favg.addNumber(1.0);
    favg.addNumber(3.0);
    favg.addNumber(2.0);
    favg.addNumber(4.0);
    favg.addNumber(2.0);

    cout << "Should be 4.8: " << favg.calculateAverage() << endl;

    FactorAverageCalculator faavg(4);
    faavg.addNumber(1.0);
    faavg.addNumber(3.0);
    faavg.addNumber(2.0);
    faavg.addNumber(4.0);
    faavg.addNumber(2.0);

    cout << "Should be 9.6: " << faavg.calculateAverage() << endl;
    return 0;
}
