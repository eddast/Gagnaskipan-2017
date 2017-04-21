#ifndef BOXSORTER_H
#define BOXSORTER_H

#include <iostream>
#include <deque>
#include <set>
#include <stack>

using namespace std;

#include "box.h"

class BoxSorter
{
    public:
        // Useless destructor
        virtual ~BoxSorter(){}

        // Add box to all structures
        void addBox(Box box);

        // Print functions to print boxes either
        // ordered by size or in FIFO/LIFO order
        void printBoxesOrdered();
        void printBoxesFIFO();
        void printBoxesLIFO();

    private:

        // Keeps boxes in FIFO-structure
        // considered a queue
        deque<Box> fifobox;

        // Keeps boxes in LIFO-structure
        // considered a stack
        deque<Box> lifobox;

        // Keeps boxes ordered by size
        // Needs to be a multi-set in case of
        // equal entries which are legal
        multiset<Box> orderedbox;
};

#endif // BOXSORTER_H
