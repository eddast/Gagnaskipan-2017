#include <iostream>

using namespace std;
int fibonacci_recursive(int n);

int fibonacci(int n) {
   return fibonacci_recursive(n);
}

int fibonacci_recursive(int n)
{
    if(n <= 2)
    {
        return 1;
    }
    return fibonacci_recursive(n-2) + fibonacci_recursive(n-1);
}

int main(int argc, char **argv) {

    for(int i = 1; i <= 50; i++) {
        cout << "fibonacci sequence element #" << i << ": " << fibonacci(i) << endl;
    }
}
