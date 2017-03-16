#include "drawhangman.h"
#include <iostream>

using namespace std;

// Draws various states of hangman
// Unique figures for when user has 0-6 guesses left
// Otherwise if guesses are over 6, only stand is outputted
void DrawHangman::draw(int lives)
{
    switch (lives) {
        case 0:
            drawlost();
            break;
        case 1:
            drawone();
            break;
        case 2:
            drawtwo();
            break;
        case 3:
            drawthree();
            break;
        case 4:
            drawfour();
            break;
        case 5:
            drawfive();
            break;
        default:
            drawmore();
            break;
    }
}

void DrawHangman::drawlost()
{
    cout << "\t\t\t" << "-------" << endl;
    cout << "\t\t\t" << " |    O" << endl;
    cout << "\t\t\t" << " |   -|-" << endl;
    cout << "\t\t\t" << " |   / \\" << endl;
    cout << "\t\t\t" << "-------" << endl;
}

void DrawHangman::drawone()
{
    cout << "\t\t\t" << "-------" << endl;
    cout << "\t\t\t" << " |    O" << endl;
    cout << "\t\t\t" << " |   -|-" << endl;
    cout << "\t\t\t" << " |   / " << endl;
    cout << "\t\t\t" << "-------" << endl;
}

void DrawHangman::drawtwo()
{
    cout << "\t\t\t" << "-------" << endl;
    cout << "\t\t\t" << " |    O" << endl;
    cout << "\t\t\t" << " |   -|-" << endl;
    cout << "\t\t\t" << " |     " << endl;
    cout << "\t\t\t" << "-------" << endl;
}

void DrawHangman::drawthree()
{
    cout << "\t\t\t" << "-------" << endl;
    cout << "\t\t\t" << " |    O" << endl;
    cout << "\t\t\t" << " |   -|" << endl;
    cout << "\t\t\t" << " |     " << endl;
    cout << "\t\t\t" << "-------" << endl;
}

void DrawHangman::drawfour()
{
    cout << "\t\t\t" << "-------" << endl;
    cout << "\t\t\t" << " |    O" << endl;
    cout << "\t\t\t" << " |    |" << endl;
    cout << "\t\t\t" << " |     " << endl;
    cout << "\t\t\t" << "-------" << endl;
}

void DrawHangman::drawfive()
{
    cout << "\t\t\t" << "-------" << endl;
    cout << "\t\t\t" << " |    O" << endl;
    cout << "\t\t\t" << " |     " << endl;
    cout << "\t\t\t" << " |     " << endl;
    cout << "\t\t\t" << "-------" << endl;
}

void DrawHangman::drawmore()
{
    cout << "\t\t\t" << "-------" << endl;
    cout << "\t\t\t" << " |     " << endl;
    cout << "\t\t\t" << " |     " << endl;
    cout << "\t\t\t" << " |     " << endl;
    cout << "\t\t\t" << "-------" << endl;

}
