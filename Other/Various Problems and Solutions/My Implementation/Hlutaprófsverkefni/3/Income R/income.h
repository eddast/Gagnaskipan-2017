#ifndef INCOME_H
#define INCOME_H


class Income
{
    public:
        virtual ~Income(){}
        void setMonthlyIncome(double monthlyIncome);
        double calculateAnnual();

    private:
        double monthlyIncome;
};

#endif // INCOME_H
