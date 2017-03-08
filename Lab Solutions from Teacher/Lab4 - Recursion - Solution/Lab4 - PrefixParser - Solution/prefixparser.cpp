#include <iostream>
#include <string>
#include <stdlib.h>
#include "prefixparser.h"

using namespace std;

int parseExpression(istream& ins){

    string temp;

    ins >> temp;
    while (temp == " ") {
        ins >> temp;
    }

    if(temp == "+"){
        int x = parseExpression(ins);
        int y = parseExpression(ins);
        return x + y;
    }else if(temp == "-"){
        int x = parseExpression(ins);
        int y = parseExpression(ins);
        return x - y;
    }else if(temp == "*"){
        int x = parseExpression(ins);
        int y = parseExpression(ins);
        return x * y;
    }else if(temp == "/"){
        int x = parseExpression(ins);
        int y = parseExpression(ins);
        if(y == 0) {
            throw DivideByZeroException();
        }
        return x / y;
    }
    else {
        return atoi(temp.c_str());
    }

    return 0;

}
