#include <iostream>
#include "prefixparser.h"
#include <string>
#include <stdlib.h>

using namespace std;

// Functions declared that identify if input is number or operator
// Function that applies operator to two integer values
bool isoperator(string str);
bool isnumber(string str);
int applyOperator (string op, int x, int y);

int parseExpression(istream& ins)
{
    // Input placed into string str
    string input_value;
    ins >> input_value;

    // If input is not a token but a digit, convert input to an integer
    // by first converting it to char then using atoi to convert char to int
    if(isnumber(input_value))
    {
        int integer = atoi(input_value.c_str());
        return integer;
    }

    // If input is operator, parsed expression is called recursively until two single numeric integer values are returned,
    // one for x and one for y. This works since first input is always an operator and last input is always an integer.
    if (isoperator(input_value))
    {
        int num1 = parseExpression(ins);
        int num2 = parseExpression(ins);
        return applyOperator(input_value, num1, num2);
    }

    return 0;
}
    // Checks if input is number
    bool isnumber(string str)
    {
        for (unsigned int i = 0; i < str.size(); i++)
        {
            // Returns true if str is digit, else false
            return isdigit(str[i]);
        }
        return false;
    }

    // Returns true if string is an legal operator
    bool isoperator(string str)
    {
        return str == "+" || str == "-" || str == "/" || str == "*";
    }

    // Uses correct operator to calculate x and y outcome
    int applyOperator (string op, int x, int y)
    {
        if (op == "+"){return x + y; }
        if (op == "-"){return x - y; }
        if (op == "*"){return x * y; }
        // If denominator is 0, math does not add up and an exception is returned
        if (op == "/"){if (y == 0){throw DivideByZeroException(); } return x / y; }

        return 0;
    }
