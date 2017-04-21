#include <iostream>
#include "income.h"
#include "netincome.h"

using namespace std;

int main(int argc, char **argv) {

    Income income;
    income.setMonthlyIncome(3500);
    cout << income.calculateAnnual() << endl;

    NetIncome netIncome;
    netIncome.setMonthlyIncome(3500);
    netIncome.setMonthlyPayments(2900);
    cout << netIncome.calculateAnnual() << endl;

    return 0;
}
