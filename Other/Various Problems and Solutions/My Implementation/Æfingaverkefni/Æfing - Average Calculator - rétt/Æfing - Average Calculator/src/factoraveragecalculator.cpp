#include "factoraveragecalculator.h"

FactorAverageCalculator::FactorAverageCalculator(int factor)
{
    this->factor = factor;
}

FactorAverageCalculator::~FactorAverageCalculator()
{
    //dtor
}

double FactorAverageCalculator::calculateAverage() {
    return AverageCalculator::calculateAverage() * factor;
}
