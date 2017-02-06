/*  Week 5 Lecture 1
 *  Recursion
 *  06.02.17
 */

 class SomeException{};

#include <iostream>
using namespace std;

// Calculates N! = 1 * 2 * ... * N recursively
int factorial(int n)
{
    if(n < 0)
        throw SomeException();

    else if (n < 2)
        return 1;

    return n * factorial(n-1);
}

// Returns element in slot "number" from Fibonacci sequence
// Assuming sequence begins with 1 not 0 (1, 1, 2, 3, 5, 8, 13, 21, 34...)
// Depending solely on this is too slow for larger numbers though
int fibonacci(int n)
{
    if(n < 3){
        if(n < 1)
            throw SomeException();
        return 1;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    try
    {
        cout << "Factorials: "
             << endl
             << "Factorial of " << 1 << " is " << factorial(1) << endl
             << "Factorial of " << 2 << " is " << factorial(2) << endl
             << "Factorial of " << 3 << " is " << factorial(3) << endl
             << "Factorial of " << 4 << " is " << factorial(4) << endl
             << endl;
    }
    catch (SomeException)
    {
        cout << "Negative values illegal!" << endl;
    }
    try
    {
        cout << "Fibonacci numbers: " << endl
             << "Number " << 1 << " in Fibonacci sequence is    " << fibonacci(1) << endl
             << "Number " << 2 << " in Fibonacci sequence is    " << fibonacci(2) << endl
             << "Number " << 3 << " in Fibonacci sequence is    " << fibonacci(3) << endl
             << "Number " << 4 << " in Fibonacci sequence is    " << fibonacci(4) << endl
             << "Number " << 5 << " in Fibonacci sequence is    " << fibonacci(5) << endl;
    }
    catch (SomeException)
    {
        cout << "Negative values are illegal!" << endl;
    }


    return 0;
}
