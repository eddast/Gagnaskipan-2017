#include "boxsorter.h"
#include <queue>

using namespace std;

void BoxSorter::addBox(Box box) {
    // FIFObox is considered a "queue"
    // pushes at back, then prints front to back
    fifobox.push_back(box);

    // LIFObox is considered a "stack"
    // pushes at front, then prints front to back
    lifobox.push_front(box);

    // Orderedbox is a set, so boxes are ordered
    // within the set automatically before printing
    orderedbox.insert(box);
}

void BoxSorter::printBoxesOrdered() {
    multiset<Box>::iterator it = orderedbox.begin();
    for(; it != orderedbox.end(); it++)
    {
        cout << *it << endl;
    }
}

void BoxSorter::printBoxesFIFO() {
    deque<Box>::iterator it = fifobox.begin();
    for(; it != fifobox.end(); it++)
    {
        cout << *it << endl;
    }
}

void BoxSorter::printBoxesLIFO() {
    deque<Box>::iterator it = lifobox.begin();
    for(; it != lifobox.end(); it++)
    {
        cout << *it << endl;
    }
}
