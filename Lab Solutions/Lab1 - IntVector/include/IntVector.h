/* Lab I: Vector of Integers
 * Due: 19.01.2017
 * Class: Gagnaskipan 2017
 * Solution by: Edda Steinunn/eddasr15
 * IntVector.h file
 * (unchanged apart from rearrangements and comments)
 */

#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <iostream>

using namespace std;

const int INITIAL_CAPACITY = 50;

class IndexOutOfRangeException {};
class EmptyException {};

class IntVector
{
    public:
		// Constructors and destructor
		IntVector();
		IntVector(int size, int value = 0);
		IntVector(const IntVector& vec);
		~IntVector();

        // Checking values from vector
		int  at(int index) const;
		void set_value_at(int index, int elem);
		int  size() const;
		bool empty() const;

		// Vector featured actions
		void push_back(int elem);
		int  pop_back();
		void insert(int index, int elem);
		void remove_at(int index);
		void clear();

		// Overloaded operators
		void operator=(const IntVector& vec);
		int& operator[] (int destructorindex);

	private:
		// Class' private variables
		// Array (vector), array's capacity and array's count of it's elements
		int* array;
		int  capacity;
		int  count;
};

//Overloaded << operator
ostream& operator<< (ostream& out, const IntVector& rhs);

#endif
