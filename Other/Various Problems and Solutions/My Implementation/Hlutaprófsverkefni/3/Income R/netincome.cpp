#include "netincome.h"

// Sets monthly payments and stores in a variable
void NetIncome::setMonthlyPayments(double monthlyPayments) {
    this->montlyPayments = monthlyPayments;
}

// Uses Income's calculateAnnual() but also subtracts
// monthly payments for every month
double NetIncome::calculateAnnual() {
    return Income::calculateAnnual() - (12 * montlyPayments);
}
