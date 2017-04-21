#ifndef BOXSORTER_H
#define BOXSORTER_H

#include <iostream>

using namespace std;

#include "box.h"

class BoxSorter
{
    public:
        BoxSorter();
        virtual ~BoxSorter();

        void addBox(Box box);

        void printBoxesOrdered();

        void printBoxesFIFO();

    private:
};

#endif // BOXSORTER_H
