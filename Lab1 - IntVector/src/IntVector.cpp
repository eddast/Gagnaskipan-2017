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
    // Code is therefore repeated from IntVector()
    if (size < 0)
    {
        capacity = INITIAL_CAPACITY;
        array = new int[capacity];
        count = 0;
    }
    // If size is above 0, a new dynamic array is created with user determined
    // size, with size-times copies of value as its' elements
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
    //TODO
}

// Public member functions

void IntVector::push_back(int elem)
{
    // Checks if count has reached capacity limit
    // Expands capacity if needed, then adds element to vector
    if (count == capacity)
    {
        // Capacity doubled
        capacity = capacity * 2;
        // Current elements stored in a temporary array
        int *tempArr = new int[capacity];
        for (int i = 0; i < count; i++)
            tempArr[i] = array[i];
        // Array deleted, then redefined
        delete[] array;
        array = new int[capacity];
        // Elements copied from tempArr back to array whose capacity doubled
        array = tempArr;
        // Now enough capacity, adding specified element
        array[count] = elem;
        count++;
    }
    // Else if count is within capacity, the element specified is added
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
    // Right shifts index element and all elements above by one
    // Then sets index to elem
    if (index <= count)
    {
        array[index] = elem;
        //Count (vector size) increases by one
        count++;
    }
    // Throws exception if index is out of range
    else
        throw new IndexOutOfRangeException;
}

int IntVector::at(int index) const
{
    //Checks if index is within range,
    //returns element at position index
    if (index <= count)
    {
        int element;
        element = array[index];
        return element;
    }
    //Throws exception if index is out of range
    else
        throw new IndexOutOfRangeException;

    return 0;
}

// Sets the value at position 'index' to 'elem'.
// If index is out of range, the function throws
// IndexOutOfRangeException.
void IntVector::set_value_at(int index, int elem)
{
    //TODO
}

int IntVector::size() const
{
    // Count determines how many elements have been added to vector
    // so all we do is return the count value as size
    return count;
}

bool IntVector::empty() const
{
    //If count is 0 vector is empty and true is returned, else false
    if(count == 0)
        return true;
    else
        return false;
}

void IntVector::remove_at(int index)
{
    if (index <= count)
    {
        // Left shift index element and elements above by one
        // causing index element to be "deleted"
        for (; index < (count-1) ; index++)
            array[index] = array[index+1];
        // Lower count because array size now reduced by one
        count--;
    }
    // Throws exception if index is out of range
    else
        throw new IndexOutOfRangeException;
}

int IntVector::pop_back()
{
    // Throws exception if vector is empty
    if (empty())
        throw new EmptyException;
    // Else stores last element in a variable, then sets it to zero in array
    // and reduces vectors size by one. Last element then returned
    else
    {
        int lastElem = array[count-1];
        count--;
        array[count] = 0;

        return lastElem;
    }
}

// Removes all the elements from the list
void IntVector::clear()
{
    //TODO
}

//Overloaded operators

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
    //TODO
    return array[index];
}

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
