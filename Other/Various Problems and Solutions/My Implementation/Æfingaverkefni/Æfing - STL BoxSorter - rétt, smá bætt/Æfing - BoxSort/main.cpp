#include <iostream>

#include "boxsorter.h"

using namespace std;

int main() {

    BoxSorter sorter;
    sorter.addBox(Box(0, 3, 4, 3));
    sorter.addBox(Box(1, 2, 6, 5));
    sorter.addBox(Box(2, 3, 3, 3));
    sorter.addBox(Box(3, 2, 6, 2));
    sorter.addBox(Box(4, 1, 2, 2));
    sorter.addBox(Box(5, 1, 1, 3));
    sorter.addBox(Box(6, 3, 4, 3));
    sorter.addBox(Box(7, 2, 1, 4));
    sorter.addBox(Box(8, 2, 2, 3));
    sorter.addBox(Box(9, 2, 5, 5));

    cout << endl << "LIST (FIFO):" << endl;
    sorter.printBoxesFIFO();

    cout << endl << "BACKWARDS LIST (LIFO):" << endl;
    sorter.printBoxesLIFO();

    cout << endl << "ORDERED LIST (BY SIZE):" << endl;
    sorter.printBoxesOrdered();

    return 0;
}
