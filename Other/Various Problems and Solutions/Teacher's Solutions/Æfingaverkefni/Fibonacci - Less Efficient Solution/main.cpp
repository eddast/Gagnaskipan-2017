#include <iostream>

using namespace std;

int fibonacci(int n) {
    if(n == 0 || n == 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char **argv) {

    for(int i = 1; i <= 32; i++) {
        cout << "fibonacci sequence element #" << i << ": " << fibonacci(i) << endl;
    }
}
