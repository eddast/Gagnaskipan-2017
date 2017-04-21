#ifndef BOXSORTER_H
#define BOXSORTER_H

#include <iostream>

///B�tti �essum vi�
#include <vector>
#include <set>

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
        ///B�tti �essum b��um vi�
        vector<Box> boxes;
        set<Box> orderedBoxes;
};

#endif // BOXSORTER_H
