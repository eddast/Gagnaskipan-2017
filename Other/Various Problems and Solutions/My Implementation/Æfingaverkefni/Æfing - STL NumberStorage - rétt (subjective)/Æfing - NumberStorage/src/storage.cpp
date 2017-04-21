#include "storage.h"

int Storage::input_number()
{
    cout << "\t ------------------------------------" << endl;
    int num;
    cout << "\t\t" << "Enter number: ";
    cin >> num;
    number_storage.insert(num);
    cout << "\t\t" << "Number stored!" << endl;
    cout << "\t ------------------------------------" << endl;
    return check_choice();
}

int Storage::check_numbers()
{
    cout << "\t ------------------------------------" << endl;
    cout << "\t\t" << "Numbers in storage: " << endl;
    cout << "\t\t";
    for(multiset<int>::iterator it = number_storage.begin(); it != number_storage.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n\t ------------------------------------" << endl;
    return check_choice();
}

int Storage::check_choice()
{
    char choice;
    cout << "\t\t" << "Continue? (y/n): ";
    cin >> choice;
    cout << endl;
    if(choice == 'y' || choice == 'Y')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
