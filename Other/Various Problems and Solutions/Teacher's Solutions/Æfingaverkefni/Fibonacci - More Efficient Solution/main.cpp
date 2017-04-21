#include <iostream>

using namespace std;

long long int fibonacci(long long int i, long long int fibNmin1, long long int fibNmin2) {

    if(i == 3) {
        return fibNmin1 + fibNmin2;
    }

    return fibonacci(i-1, fibNmin1 + fibNmin2, fibNmin1);
}

long long int fibonacci(long long int n) {

    if(n < 3) {
        return 1;
    }

    return fibonacci(n, 1, 1);
}


int main(int argc, char **argv) {

    for(int i = 1; i <= 32; i++) {
        cout << "fibonacci sequence element #" << i << ": " << fibonacci(i) << endl;
    }
}
