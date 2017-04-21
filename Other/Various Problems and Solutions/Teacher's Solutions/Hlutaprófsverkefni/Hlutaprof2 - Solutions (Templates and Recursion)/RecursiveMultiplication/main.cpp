#include <iostream>

using namespace std;

class MismatchException{};

int multiply(int a, int b) {
    if(a == 1) {
        return b;
    }
    return b + multiply(a-1, b);
}

void checkMultiply(int a, int b) {

    int result1 = multiply(a, b);
    int result2 = a * b;

    cout << "Your output:     " << a << " * " << b << " = " << result1 << endl;
    cout << "Expected output: " << a << " * " << b << " = " << result2 << endl;
    cout << endl;

    if(result1 != result2) {
        throw MismatchException();
    }

}

int main() {

    try {checkMultiply(4, 5);} catch(MismatchException e) { cout << "THERE WAS A MISMATCH!!" << endl << endl; }

    try {checkMultiply(34, 5);} catch(MismatchException e) { cout << "THERE WAS A MISMATCH!!" << endl << endl; }
    try {checkMultiply(4, 234);} catch(MismatchException e) { cout << "THERE WAS A MISMATCH!!" << endl << endl; }
    try {checkMultiply(23, 3);} catch(MismatchException e) { cout << "THERE WAS A MISMATCH!!" << endl << endl; }
    try {checkMultiply(54, 12);} catch(MismatchException e) { cout << "THERE WAS A MISMATCH!!" << endl << endl; }
    try {checkMultiply(9, 78);} catch(MismatchException e) { cout << "THERE WAS A MISMATCH!!" << endl << endl; }
    try {checkMultiply(56, 32);} catch(MismatchException e) { cout << "THERE WAS A MISMATCH!!" << endl << endl; }
    try {checkMultiply(2, 4234);} catch(MismatchException e) { cout << "THERE WAS A MISMATCH!!" << endl << endl; }

    try {
        for(int i = 4; i < 23; i += 3) {
            for(int j = 1; j < 31; j += 4) {
                checkMultiply(i, j);
                checkMultiply(j, i);
            }
        }
    }
    catch(MismatchException e) {
        cout << "THERE WAS A MISMATCH!!" << endl << endl;
    }

}
