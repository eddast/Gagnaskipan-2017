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
    ///Útfærði þetta
    boxes.push_back(box);
    orderedBoxes.insert(box);
}

void BoxSorter::printBoxesOrdered() {
    ///Útfærði þetta
    for(set<Box>::iterator it = orderedBoxes.begin(); it != orderedBoxes.end(); it++) {
        cout << *it << endl;
    }
}

void BoxSorter::printBoxesFIFO() {
    ///Útfærði þetta
    for(vector<Box>::iterator it = boxes.begin(); it != boxes.end(); it++) {
        cout << *it << endl;
    }
}
