#ifndef NETINCOME_H
#define NETINCOME_H
#include "income.h"


class NetIncome : public Income
{
    public:
        virtual ~NetIncome(){}
        void setMonthlyPayments(double montlyPayments);
        double calculateAnnual();
    private:
        double montlyPayments;
};

#endif // NETINCOME_H
