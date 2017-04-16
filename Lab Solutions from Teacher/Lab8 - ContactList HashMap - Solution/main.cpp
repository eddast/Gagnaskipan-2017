#include <iostream>
#include "InteractivePhoneBook.h"
#include "Hash.h"

int main()
{
    cout << hash("Lavada Moore") << endl;
    InteractivePhoneBook pb;
    pb.start();

    return 0;
}
