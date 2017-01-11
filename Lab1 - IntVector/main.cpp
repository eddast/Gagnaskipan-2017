/* Lab I: Vector of Integers
 * Due: 19.01.17
 * Class: Gagnaskipan 2017
 * Solution by: Edda Steinunn/eddasr15
 * Main file
 */

#include <iostream>
#include "IntVector.h"

using namespace std;

//Further "Unit testing" of code that main function appears to lack
void additionalUnitTests();

int main()
{
    IntVector v1, v2(10);

    cout << "First vector:" << endl;
    cout << v1 << endl;
    // Should be empty

    cout << "Second vector:" << endl;
    cout << v2 << endl;
    // Should contain 10 times zero

    for (int i = 0; i < v2.size(); i++)
    {
        v2[i] = i;
    }

    cout << "Second vector:" << endl;
    cout << v2 << endl;
    // Should contain 0 to 9

    for (int i = 0; i < 60; i++)
    {
        v1.push_back(i);
    }

    cout << "After adding to the first vector:" << endl;
    cout << v1 << endl;
    // Should contain 0 to 59

    for(int i = 0; i < 10; i++)
    {
        v1.pop_back();
    }

    cout << "After popping elements from first vector:" << endl;
    cout << v1 << endl;
    //Should contain 10-49

    /*
    IntVector v3(v2); // Calls the copy constructor
    cout << "Third vector:" << endl;
    cout << v3 << endl;

    cout << "Modifying second vector:" << endl;
    v2.insert(3, 1337);
    v2.remove_at(8);
    cout << v2 << endl;

    IntVector v4;
    v4 = v3; // Operator overloading: assignment

    cout << "Fourth vector:" << endl;
    cout << v4 << endl;

    v4.push_back(100);
    cout << "Fourth vector:" << endl;
    cout << v4 << endl;

    cout << "Lets finally try to access an element not in the vector: " << endl;
    try
    {
        cout << v4.at(50);
    }
    catch (IndexOutOfRangeException)
    {
        cout << "Index out of range!" << endl;
    }
    */

    //additionalUnitTests();

    return 0;
}

void additionalUnitTests()
{
    cout << endl << "--- Additional Tests ---" << endl;
    //Testing negative sizes, should yield empty vector
    IntVector testvec1(-1);
    cout << "testvec1, with negative size: " << endl;
    cout << testvec1 << endl;
    //Testing vector with specified value, i.e. value != 0
    IntVector testvec2(2,4);
    cout << "testvec2, with specified value: " << endl;
    cout << testvec2 << endl;
    //Testing IntVector::at function
    cout << "Element at position 0 for testvec2 is: " << testvec2.at(0) << endl;
    //Tests pass OK
}
