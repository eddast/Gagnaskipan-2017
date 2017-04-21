#include "interface.h"
#include <cstdlib>

void Interface::start()
{
    main_menu();
    terminate();
}

void Interface::interface()
{
    cout << "\t ------------------------------------" << endl << endl;
    cout << "\t\t" << "NUMBER STORER 3000" << endl << endl;
    cout << "\t ------------------------------------" << endl;
    cout << "\t\t" << "Select operation:" << endl;
    cout << "\t\t" << "1. Input a number to store" << endl;
    cout << "\t\t" << "2. Check inputted numbers" << endl;
    cout << "\t\t" << "3. Quit" << endl;
    cout << "\t ------------------------------------" << endl;
    cout << endl;
}

void Interface::main_menu()
{
    int quit = 0;
    int input;
    while(quit == 0)
    {
        interface();
        cout << "\t\t" << "Enter your choice: ";
        cin >> input;
        quit = menu(input);
    }
}

int Interface::menu(int input)
{
    switch(input){
    case 1:
        return storage.input_number();
        break;
    case 2:
        return storage.check_numbers();
        break;
    case 3:
        return 1;
        break;
    default:
        cout << "\t\t" << "Invalid operation" << endl;
        cout << "\t\t" << "Redirecting to main menu" << endl;
        return 0;
    }
}

void Interface::terminate()
{
    cout << "\t\t" << "Bye!" << endl;
    exit(1);
}
