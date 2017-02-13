/* Lecture 1 - Week 6: Recursion/linked list
 * Based on V3 solution
 * Added functions to solution:
 *     addOneThroughout(addOneRecursive),
 *     swapNodes (swapNodesRecursive) DOESN'T WORK THOUGH
 */

#include <iostream>
#include "RecList.h"

using namespace std;

int main()
{
    LinkedList<int> list;

    // Push back odd numbers
    list.push_back(1);
    list.push_back(3);
    list.push_back(5);
    list.push_back(7);

    cout << "First four odd numbers: " << list << endl;
    // Now we add 1 to every integer node data of list's nodes
    list.addOneTroughout();
    cout << "First four even numbers: " << list << endl;
    list.swapNodes(2,3);
    cout << "SWAPPED NODES 1 AND 2: " << list << endl;
}
