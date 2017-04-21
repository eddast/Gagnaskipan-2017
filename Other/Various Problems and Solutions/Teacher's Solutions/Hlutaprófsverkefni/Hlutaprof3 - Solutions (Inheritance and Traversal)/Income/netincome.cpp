#include "netincome.h"

NetIncome::NetIncome()
{
    //ctor
}

NetIncome::~NetIncome()
{
    //dtor
}

void NetIncome::setMonthlyPayments(double monthlyPayments) {
    this->monthlyPayments = monthlyPayments;
}

double NetIncome::calculateAnnual() {
    return Income::calculateAnnual() - 12 * monthlyPayments;
}
