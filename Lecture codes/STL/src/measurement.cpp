#include "measurement.h"

Measurement::Measurement()
{
    address = "";
}

Measurement::~Measurement()
{
    //dtor
}

bool Measurement::operator <(const Measurement &mes) const {
    if(mes.value == value){
        return address < mes.address;
    }

    return mes.value < value;
}
