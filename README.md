# Gagnaskipan-2017
Codes I made from lectures and labs from class Gagnaskipan, Reykjavik University (2017).

# Lab descriptions
## Lab 1
### IntVector
You are working as an archaeologist in Pompeii when you discover an entry to what you believe to be an ancient bathhouse. As you walk in you discover what appears to be an ancient C++ class on the wall.
It appears to be a vector class for integers, but parts of it are missing. You decide to reconstruct the missing code.
Vectors can be thought of as arrays that can grow in length while your program is running. In C++, once your program creates an array, it cannot change the length of the array. Vectors serve the same purpose except that they can change length while your program is still running. You can read more about vectors in Chapter 4.1.1 in Shaffer and Chapter 8.3 in Savitch.
In this assignment you will implement the class IntVector which is a vector of integers. The template
You are given the class declaration of the class IntVector in IntVector.h. A partial class implementation is given in IntVector.cpp. A small main-program is given to test the class in main.cpp. Note that the testing is not complete. You should write your own tests to ensure that your implementation is correct!
The file IntVector.cpp contains an implementation of the overloaded assignment operator and the copy constructor for the IntVector class. Note that the << operator has also been overloaded for the class.
The details of functionality of the class are specified in the comments of the class declaration. In addition to that you should note the following.
￼￼￼
* In the default constructor of the class you should create a dynamic array of size INITAL_CAPACITY.
* If you attempt to add an element to the vector and there is no more room, then a dynamic array with twice the capacity of the old dynamic array is created. The values of the old dynamic array are
then copied to the new dynamic array (and the new value subsequently added).
* If the insert function is called with an index that is equal to the size of the vector, the inserted element
is appended to the vector.
* The functions at, set_value_at, insert, remove_at and operator[] all throw an instance of IndexOutOfRangeException
if the specified index is out of range.
* The function pop_back throws an instance of EmptyException if the vector is empty.
* You are free (and encouraged) to use private helper functions in your implementation to make your
code less redundant and more readable.

## Lab 2
### Doubly linked lists
For full marks your solution needs to be accepted by Mooshak. Points may be deducted for
* not implementing the solution according to the specifications (including worst-case time complexity)
* redundant or repeated code.
If your solution is not accepted by Mooshak, it will receive a maximum grade of 7 for that part. In this assignment you have 10 free submissions for each part.
In this part you will implement an abstract data type list, for strings, using a doubly linked list. The data structure should be implemented as the class StringList. The interface and implementation of the StringNode struct, which is used to construct the doubly linked list, is given in StringNode.h. The interface of the class StringList is given in StringList.h. Your task is to implement this interface in StringList.cpp.
￼
Notes about the implementation.
• No private members are specified in StringList.h, you must decide which private member variables and functions you want to use.
• The function clear() should release all the memory that has been allocated for the list.
• You are encouraged to implement a copy constructor and operator= for StringList, but it is not
required. Neither will be tested on Mooshak.
• The operator << should output the elements of the list, separated by a single space.
• Make sure your functions handle empty lists.
• Please comment your code.
Submitting. To submit this problem to Mooshak you must create a zip file containing StringNode.h, StringList.h and StringList.cpp. You can include other files, such as main.cpp, but that is not necessary.
