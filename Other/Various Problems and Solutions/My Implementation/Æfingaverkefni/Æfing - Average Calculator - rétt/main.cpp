#include <iostream>
#include "averagecalculator.h"

using namespace std;

int main(int argc, char **argv)
{

    AverageCalculator avg;
    avg.addNumber(1.0);
    avg.addNumber(3.0);
    avg.addNumber(2.0);
    avg.addNumber(4.0);
    avg.addNumber(2.0);

    cout << avg.calculateAverage() << endl;
    return 0;
}
