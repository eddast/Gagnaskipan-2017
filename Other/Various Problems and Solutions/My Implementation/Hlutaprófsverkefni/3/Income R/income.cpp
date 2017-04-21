#include "income.h"

// Sets monthly income and stores in a variable
void Income::setMonthlyIncome(double monthlyIncome) {
    this->monthlyIncome = monthlyIncome;
}

// Calculates annual income based on monthly income
double Income::calculateAnnual() {
    return 12 * monthlyIncome;
}
