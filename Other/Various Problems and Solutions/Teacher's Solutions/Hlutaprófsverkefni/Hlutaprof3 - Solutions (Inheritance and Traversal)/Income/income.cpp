#include "income.h"

Income::Income()
{
    //ctor
}

Income::~Income()
{
    //dtor
}

void Income::setMonthlyIncome(double monthlyIncome) {
    this->monthlyIncome = monthlyIncome;
}

double Income::calculateAnnual() {
    return 12 * monthlyIncome;
}
