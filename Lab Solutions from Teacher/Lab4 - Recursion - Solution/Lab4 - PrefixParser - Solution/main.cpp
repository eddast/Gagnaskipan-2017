//
//  main.cpp
//  prefix_parser
//
//  Created by Skuli Þór Árnason on 23/05/16.
//  Copyright © 2016 Skuli Þór Árnason. All rights reserved.
//

#include <fstream>
#include "prefixparser.h"

using namespace std;

int main(int argc, const char * argv[]) {

    ifstream fin;
    fin.open("test.txt");

    string inp;
    while (fin >> inp) {
        if (inp == "new") {
            cout << "New test" << endl;
        }else if (inp == "parse") {
            cout << "Calling parser()" << endl;
            try {
                int result = parseExpression(fin);
                cout << "Parsed expression: " << result << endl;
            }
            catch(DivideByZeroException) {
                cout << "Caught DivideByZeroException" << endl;
            }
        }else {
            cout << "INVALID INPUT: " << inp << endl;
        }
    }

    fin.close();

    return 0;
}
