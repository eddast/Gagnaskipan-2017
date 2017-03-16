#include "interface.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

// Main menu loop
void Interface::start()
{
    Gameplay game;
    main_menu();
    char start;
    cin >> start;

    // S starts game
    if(start == 's' || start == 'S'){
        game_header();
        game.start_game();
    }
    // A adds to word bank
    if(start == 'a' || start == 'A'){
        WB_add_header();
        game.add_word();
        menu_or_quit();
    }
    // V views word bank
    if(start == 'v' || start == 'V'){
        WB_header();
        game.view_word_bank();
        menu_or_quit();
    }
    // H views high scores
    if(start == 'h' || start == 'H'){
        high_score_header();
        game.view_high_scores();
        menu_or_quit();
    }
    // I views instructions
    if(start == 'i' || start == 'I'){
        instructions();
    }
    // Other input terminate program
    else{exit_program(); }
}

// User determines weather to return to main menu
// or terminate program
void Interface::menu_or_quit()
{
        char input;
        cout << endl << "\t" << "Back to menu? (y/Y): ";
        cin >> input;
        if(input == 'y' || input == 'Y')
        {
            Interface i;
            i.start();
        }
        else{
            exit_program();
        }
}

// Word bank header
void Interface::WB_header(){
    cout << "\t" << "-------------------------------------------" << endl;
    cout << endl << "\t\t    " << "HANGMAN WORD BANK" << endl;
    cout << "\t" << "-------------------------------------------" << endl;
}

// Adding to word bank header
void Interface::WB_add_header()
{
    cout << "\t" << "-------------------------------------------" << endl;
    cout << endl << "\t\t  " << "ADDING TO WORD BANK" << endl;
    cout << "\t" << "-------------------------------------------" << endl;
}

// Game header
void Interface::game_header()
{
    cout << "\t" << "-------------------------------------------" << endl;
    cout << endl << "\t\t\t" << "HANGMAN" << endl;
    cout << "\t\t\t" << "new game" << endl << endl;
    cout << "\t" << "-------------------------------------------" << endl;
}

// High scores header
void Interface::high_score_header(){
    cout << "\t" << "-------------------------------------------";
    cout << endl << "\t\t" << "HIGH SCORES [TOP FIVE]" << endl;
    cout << "\t\t" << "------------------" << endl;
}

// Main menu dialogue
void Interface::main_menu()
{
    cout << "\t" << "-------------------------------------------" << endl;
    cout << endl << "\t\t\t" << "HANGMAN" << endl;
    cout << "\t\t\t" << "main menu" << endl << endl;
    cout << "\t" << "-------------------------------------------" << endl;
    cout << "\t" << "* Press 'S' to start game" << endl;
    cout << "\t" << "* Press 'A' to add word to wordbank" << endl;
    cout << "\t" << "* Press 'V' to view wordbank" << endl;
    cout << "\t" << "* Press 'I' for instructions" << endl;
    cout << "\t" << "* Press 'H' to view high scores" << endl;
    cout << "\t" << "* Press any other key to quit" << endl;
    cout << "\tInput: ";
}

// Instructions dialogue
void Interface::instructions()
{
    cout << "\t" << "-------------------------------------------" << endl;
    cout << endl << "\t\t\t" << "INSTRUCTIONS" << endl;
    cout << "\t" << "-------------------------------------------" << endl;
    cout << "\t" << "Press 'R' for game rules," << endl;
    cout << "\t" << "Press 'A' to learn about HANGMAN," << endl;
    cout << "\t" << "Press any key for main menu: ";
    char input;
    cin >> input;
    if(input == 'r' || input == 'R')
    {
        cout << "\t" << "-------------------------------------------" << endl;
        cout << endl;
        cout << "\t" << "GAME RULES: \n" << endl;
        cout << "\t" << "* Pick number of guesses" << endl;
        cout << "\t" << "* Computer picks a word for you to decipher" << endl;
        cout << "\t" << "* Word is randomly generated from word bank" << endl;
        cout << "\t" << "* You guess the word, one letter at a time" << endl;
        cout << "\t" << "* Game is won when word is deciphered" << endl;
        cout << "\t" << "* Game is lost when guesses run out" << endl;
        cout << "\t" << "* More guesses mean lower score" << endl;
        cout << "\t" << "* More failed guesses also means lower score" << endl;
        cout << "\t" << "* Lost game yields no score" << endl;
        cout << "\t" << "-------------------------------------------" << endl;
        cout << endl;
        menu_or_quit();
    }
    if(input == 'a' || input == 'A')
    {
        cout << "\t" << "-------------------------------------------" << endl;
        cout << endl;
        cout << "\t" << "ABOUT HANGMAN: \n" << endl << endl;
        cout << "\t" << "The Word Bank:" << endl;
        cout << "\t" << "* Word in game is randomly generated from word bank" << endl;
        cout << "\t" << "* Word bank can be viewed in main menu" << endl;
        cout << "\t" << "* Word can be added to word bank in main menu" << endl;
        cout << endl;
        cout << "\t" << "User Score:" << endl;
        cout << "\t" << "Score is generated from: " << endl;
        cout << "\t" << "   * User set guesses: more guesses lower score " << endl;
        cout << "\t" << "   * Failed guesses: more failed guesses lower score " << endl;
        cout << "\t" << "   * Lost game yields no score" << endl;
        cout << endl;
        cout << "\t" << "Authors: " << endl;
        cout << "\t" << "   * Edda Steinunn " << endl;
        cout << "\t" << "   * Bergvin Orn" << endl;
        cout << endl;
        cout << "\t" << "Made for: Class Gagnaskipan 2017-1" << endl;
        menu_or_quit();
    }
}

// Terminates program
void Interface::exit_program(){
    cout << "\n \t" << "Okay, bye :-(" << endl << endl;
    exit(1);
}
