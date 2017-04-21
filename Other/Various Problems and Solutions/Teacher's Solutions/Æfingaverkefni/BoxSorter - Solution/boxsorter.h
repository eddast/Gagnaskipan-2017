#ifndef BOXSORTER_H
#define BOXSORTER_H

#include <iostream>

///Bætti þessum við
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
        ///Bætti þessum báðum við
        vector<Box> boxes;
        set<Box> orderedBoxes;
};

#endif // BOXSORTER_H
