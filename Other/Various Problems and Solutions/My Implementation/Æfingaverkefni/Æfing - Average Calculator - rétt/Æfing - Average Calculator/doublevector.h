#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <iostream>

using namespace std;

const int INITIAL_CAPACITY = 50;

class IndexOutOfRangeException {};
class EmptyException {};

class DoubleVector
{
	private:
		// A pointer to an array that stores the vector's values.
		double* array;
		// Contains the size of array (i.e. the maximum number of elements
		// that the vector can store using this array).
		int  capacity;
		// The number of array positions currently holding values.
		int  count;

		void increaseArrayCapacity();

	public:
		// Initializes an empty vector.
		DoubleVector();
		// Initializes a vector with 'size' copies of the element 'value'.
		// If 'size' is less than 0, the initalized vector is empty.
		DoubleVector(int size, double value = 0.0);
		// A copy constructor.
		DoubleVector(const DoubleVector& vec);
		// A destructor.
		~DoubleVector();

		// Returns the element at position 'index'.
		// If index is out of range, the function throws
		// IndexOutOfRangeException.
		double  at(int index) const;
		// Sets the value at position 'index' to 'elem'.
		// If index is out of range, the function throws
		// IndexOutOfRangeException.
		void set_value_at(int index, double elem);

		// Returns the size of the array.
		int  size() const;
		// Returns true if and only if the array contains no elements.
		bool empty() const;

		// Appends elem to the vector.
		void push_back(double elem);
		// Removes the last element of the vector and returns it.
		// If the vector is empty, the function throws
		// EmptyException.
		double  pop_back();
		// Inserts 'elem' into the list at position 'index'. All elements to the
		// right of index are shifted one position to the right.
		// If index is out of range, the function throws
		// IndexOutOfRangeException.
		void insert(int index, double elem);
		// Removes the element at position 'index'. All elements to the
		// right of index are shifted one position to the left.
		// If index is out of range, the function throws
		// IndexOutOfRangeException.
		void remove_at(int index);
		// Removes all the elements from the list
		void clear();

		// Overloaded = operator.
		void operator=(const DoubleVector& vec);
		// Returns a reference to the element at position 'index'.
		// If index is out of range, the function throws
		// IndexOutOfRangeException.
		double& operator[] (int index);
};

ostream& operator<< (ostream& out, const DoubleVector& rhs);

#endif
