#ifndef FACTORAVERAGECALCULATOR_H
#define FACTORAVERAGECALCULATOR_H
#include "../averagecalculator.h"

class FactorAverageCalculator: public AverageCalculator
{
    public:
        FactorAverageCalculator(int factor);
        virtual ~FactorAverageCalculator();
        double calculateAverage();

    protected:

    private:
        double factor;
};

#endif // FACTORAVERAGECALCULATOR_H
