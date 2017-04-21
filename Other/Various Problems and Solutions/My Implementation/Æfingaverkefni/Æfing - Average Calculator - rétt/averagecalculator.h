#ifndef AVERAGECALCULATOR_H
#define AVERAGECALCULATOR_H

#include "doublevector.h"

class AverageCalculator
{
    public:
        AverageCalculator();
        virtual ~AverageCalculator();

        void addNumber(double value);

        double calculateAverage();

    private:
        DoubleVector vec;

};

#endif // AVERAGECALCULATOR_H
