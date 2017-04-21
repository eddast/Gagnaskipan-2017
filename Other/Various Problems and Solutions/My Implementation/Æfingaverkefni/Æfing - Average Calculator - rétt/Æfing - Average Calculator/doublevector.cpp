#include <cmath>
#include "doublevector.h"

using namespace std;

// Constructors

DoubleVector::DoubleVector() {

    // Initialize the array at INITIAL_CAPACITY
    capacity = INITIAL_CAPACITY;
    array = new double[capacity];
    count = 0;
}

DoubleVector::DoubleVector(int size, double value) {

    if(size < 0) {
        size = 0;
    }

    count = size;

    // Start at INITIAL_CAPACITY
    capacity = INITIAL_CAPACITY;
    // While we still need more space, we double the capacity
    // but there is no need to actually allocate the memory
    // until we've decided on the size
    while(capacity < size) {
        capacity *= 2;
    }
    array = new double[capacity];

    // Put the initial value in the array "count" times
    for(int i = 0; i < count; i++) {
        array[i] = value;
    }
}

DoubleVector::DoubleVector(const DoubleVector& vec) : capacity(vec.capacity), count(vec.count) {
    array = new double[capacity];

    for(int i = 0; i < count; i++) {
        array[i] = vec.array[i];
    }
}


DoubleVector::~DoubleVector() {

    // Remember to free all the memory
    delete[] array;
}

//Private member functions

void DoubleVector::increaseArrayCapacity() {

    // This is the capacity we are going for
    capacity *= 2;

    // allocate memory for the increased size array
    double *tmpArray = new double[capacity];

    // Move each element from the old array to the new one
    for(int i = 0; i < count; i++) {
        tmpArray[i] = array[i];
    }

    // Free the memory that was originally allocated
    // but had become too small
    delete[] array;

    // Have our actual array pointer point to the newly allocated memory
    array = tmpArray;

}

// Public member functions

void DoubleVector::push_back(double elem) {

    // If we're already at full capacity we've filled the array, and so need a bigger array.
    if(count >= capacity) {
        increaseArrayCapacity();
    }

    // Set the element after our last element to elem and grow the used size by one
    array[count] = elem;
    count++;
}

void DoubleVector::insert(int index, double elem) {

    // It is OK to insert if index == count, since we are then adding behind the list
    // anything higher than that, or lower than 0 is obviously out of bounds though
    if(index < 0 || index > count) {
        throw IndexOutOfRangeException();
    }

    // If we're already at full capacity we've filled the array, and so need a bigger array.
    if(count >= capacity) {
        increaseArrayCapacity();
    }

    // Here we have to start at the top element
    // and move down to the place where we want to insert.
    // Each iteration we move the element we're at (array[i])
    // up one place (into array[i+1).
    // The last iteration moves from array[index],
    // leaving that place vacant, so we can
    // put the new element there.
    for(int i = count - 1; i >= index; i--) {
        array[i + 1] = array[i];
    }
    array[index] = elem;

    // Grow vector by one
    count++;
}

double DoubleVector::at(int index) const {

    // Here index == count is NOT OK
    // because we cannot find a data element there.
    // Obviously anything higher than that
    // or lower than 0 is not good.
    if(index < 0 || index >= count) {
        throw IndexOutOfRangeException();
    }

    // Simply return the value at the location
    return array[index];
}

void DoubleVector::set_value_at(int index, double elem) {

    // Here index == count is NOT OK
    // because we cannot find a data
    // element to change at that location.
    // Obviously anything higher than that
    // or lower than 0 is not good.
    if(index < 0 || index >= count) {
        throw IndexOutOfRangeException();
    }

    // Simply set the element at the location to the new value
    array[index] = elem;
}

int DoubleVector::size() const {

    return count;
}

bool DoubleVector::empty() const {

    // (count == 0) is a boolean expression.
    // We return the result of that expression.
    return count == 0;
}

void DoubleVector::remove_at(int index) {

    // Here index == count is NOT OK
    // because we cannot find a data
    // element to remove at that location.
    // Obviously anything higher than that
    // or lower than 0 is not good.
    if(index < 0 || index >= count) {
        throw IndexOutOfRangeException();
    }

    // Here we have to start at the location where
    // we remove at and, each iteration, move the element
    // above it (array[i+1] into its place.
    // We have to stop before we actually get to the
    // last element, as we move the last element into
    // the next to last element: array[count-2] = array[count-1]
    for(int i = index; i < count - 1; i++) {
        array[i] = array[i + 1];
    }

    //shrink the vector by one.
    count--;
}

double DoubleVector::pop_back() {

    if(empty()) {
        throw EmptyException();
    }

    //Shrink the vector by one
    count--;

    // return the last element
    // which then stops being part of the list
    // as the last element is array[count-1]
    return array[count];
}

void DoubleVector::clear() {

    // All we need to do to clear the list is to
    // update our data so that it claims there
    // are no elements.  No need for any actual
    // removing or deleting.
    count = 0;
}

// Overloaded operators

void DoubleVector::operator=(const DoubleVector& vec) {
    if(capacity < vec.capacity) {
        delete [] array;
        array = new double[vec.capacity];
    }

    capacity = vec.capacity;
    count = vec.count;

    for(int i = 0; i != count; i++) {
        array[i] = vec.array[i];
    }
}

double& DoubleVector::operator[] (int index) {

    // Here index == count is NOT OK
    // because we cannot find a data element
    // at that location.
    // Obviously anything higher than that
    // or lower than 0 is not good.
    if(index < 0 || index >= count) {
        throw IndexOutOfRangeException();
    }

    return array[index];
}

ostream& operator<< (ostream& out, const DoubleVector& rhs) {
    for(int i = 0; i < rhs.size(); i++) {
		if(i > 0) {
			out << " ";
		}
        out << rhs.at(i);
    }
    return out;
}
