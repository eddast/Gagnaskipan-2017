#include "averagecalculator.h"

AverageCalculator::AverageCalculator()
{
    //ctor
}

AverageCalculator::~AverageCalculator()
{
    //dtor
}

void AverageCalculator::addNumber(double value) {
    vec.push_back(value);
}

double AverageCalculator::calculateAverage() {
    double total = 0.0;
    for(int i = 0; i < vec.size(); i++) {
        total += vec[i];
    }
    return total / ((double)vec.size());
}
