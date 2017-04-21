#include "boxsorter.h"

using namespace std;

BoxSorter::BoxSorter()
{
    //ctor
}

BoxSorter::~BoxSorter()
{
    //dtor
}

void BoxSorter::addBox(Box box) {
    ///�tf�r�i �etta
    boxes.push_back(box);
    orderedBoxes.insert(box);
}

void BoxSorter::printBoxesOrdered() {
    ///�tf�r�i �etta
    for(set<Box>::iterator it = orderedBoxes.begin(); it != orderedBoxes.end(); it++) {
        cout << *it << endl;
    }
}

void BoxSorter::printBoxesFIFO() {
    ///�tf�r�i �etta
    for(vector<Box>::iterator it = boxes.begin(); it != boxes.end(); it++) {
        cout << *it << endl;
    }
}
