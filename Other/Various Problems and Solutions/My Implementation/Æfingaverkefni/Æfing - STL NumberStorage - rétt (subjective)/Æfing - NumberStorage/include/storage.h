#ifndef STORAGE_H
#define STORAGE_H
#include <iostream>
#include <set>

using namespace std;


class Storage
{
    public:
        virtual ~Storage(){}
        int input_number();
        int check_numbers();
        int check_choice();

    protected:

    private:
        multiset<int> number_storage;
};

#endif // STORAGE_H
