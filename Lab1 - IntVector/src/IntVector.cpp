/* Lab I: Vector of Integers
 * Due: 19.01.17
 * Class: Gagnaskipan 2017
 * Solution by: Edda Steinunn/eddasr15
 * IntVector.cpp file
 */

#include <cmath>
#include "IntVector.h"

using namespace std;

IntVector::IntVector()
{
    // Empty dynamic array of initial capacity created
    // Has no elements by default so count is set to 0
    capacity = INITIAL_CAPACITY;
    array = new int[capacity];
    count = 0;
}

IntVector::IntVector(int size, int value)
{
    // If size is negative an empty vector is initialized
    // Calling constructor from another constructor does not work
    // so code is repeated from IntVector()
    if (size < 0)
    {
        capacity = INITIAL_CAPACITY;
        array = new int[capacity];
        count = 0;
    }
    // If size is 0 or positive, a new dynamic array is created with user determined
    //size as capacity, with size copies of value as its' elements
    else
    {
        capacity = INITIAL_CAPACITY;
        array = new int[capacity];
        count = size;
        for (int i = 0; i < size; i++)
            array[i] = value;
    }
}

IntVector::IntVector(const IntVector& vec)
    : capacity(vec.capacity), count(vec.count)
{
    array = new int[capacity];

    for(int i = 0; i < count; i++) {
        array[i] = vec.array[i];
    }
}

// A destructor
IntVector::~IntVector()
{

}

// Public member functions

void IntVector::push_back(int elem)
{
    // Checks if count has reached capacity limit
    // Expands capacity if needed, then adds element to vector
    if (count == capacity)
    {
        //Capacity doubled
        capacity = capacity * 2;
        //Current elements stored in a temporary array
        int *tempArr = new int[capacity];
        for (int i = 0; i < count; i++)
            tempArr[i] = array[i];
        //Array deleted, then redefined
        delete[] array;
        array = new int[capacity];
        // Elements copied from tempArr back to array whose capacity doubled
        for (int i = 0; i < count; i++)
            array[i] = tempArr[i];
        array[count] = elem;
        count++;
    }
    // If count is still within capacity, element specified is added to
    // IntVector instance and one is added count (the vector size)
    else
    {
        array[count] = elem;
        count++;
    }
}

// Inserts 'elem' into the list at position 'index'. All elements to the
// right of index are shifted one position to the right.
// If index is out of range, the function throws
// IndexOutOfRangeException.
void IntVector::insert(int index, int elem)
{

}
// Returns the element at position 'index'.
// If index is out of range, the function throws
// IndexOutOfRangeException.
int IntVector::at(int index) const
{
    if (index <= count)
    {
        int element;
        element = array[index];
        return element;
    }
    else
        throw new IndexOutOfRangeException;

    return 0;
}

// Sets the value at position 'index' to 'elem'.
// If index is out of range, the function throws
// IndexOutOfRangeException.
void IntVector::set_value_at(int index, int elem)
{

}

int IntVector::size() const
{
    // Count determines how many elements have been added to vector
    // so all we do is return the count value as size
    return count;
}

// Returns true if and only if the array contains no elements.
bool IntVector::empty() const
{
    if(count == 0)
        return true;
    else
        return false;
}

// Removes the element at position 'index'. All elements to the
// right of index are shifted one position to the left.
// If index is out of range, the function throws
// IndexOutOfRangeException.
void IntVector::remove_at(int index)
{

}

// Removes the last element of the vector and returns it.
// If the vector is empty, the function throws
// EmptyException.
int IntVector::pop_back()
{

    return 0;
}

// Removes all the elements from the list
void IntVector::clear()
{

}

//Overloaded operators

// Overloaded = operator.
void IntVector::operator=(const IntVector& vec)
{
    if(capacity < vec.capacity) {
        delete [] array;
        array = new int[vec.capacity];
    }

    capacity = vec.capacity;
    count = vec.count;

    for(int i = 0; i != count; i++) {
        array[i] = vec.array[i];
    }
}

// Returns a reference to the element at position 'index'.
// If index is out of range, the function throws
// IndexOutOfRangeException.
int& IntVector::operator[] (int index)
{

    return array[index];
}

//Overloaded << operator
ostream& operator<< (ostream& out, const IntVector& rhs)
{
    for(int i = 0; i < rhs.size(); i++) {
		if(i > 0) {
			out << " ";
		}
        out << rhs.at(i);
    }
    return out;
}
