#ifndef INTERFACE_H
#define INTERFACE_H
#include "storage.h"
#include <iostream>

using namespace std;


class Interface
{
    public:
        virtual ~Interface(){}
        void start();
        void interface();
        int menu(int input);
        void main_menu();
        void terminate();

    protected:

    private:
        Storage storage;
};

#endif // INTERFACE_H
