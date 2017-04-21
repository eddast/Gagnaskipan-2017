#ifndef NETINCOME_H
#define NETINCOME_H

#include "income.h"

class NetIncome : public Income
{
    public:
        NetIncome();
        virtual ~NetIncome();

        void setMonthlyPayments(double monthlyPayments);
        double calculateAnnual();

    private:
        double monthlyPayments;
};

#endif // NETINCOME_H
