#ifndef MEASUREMENT_H
#define MEASUREMENT_H
#include <string>


class Measurement
{
    public:
        Measurement();
        virtual ~Measurement();

        std::string address;
        double value;

        bool operator <(const Measurement &mes) const;

    protected:

    private:
};

#endif // MEASUREMENT_H
