/* T-201-GSKI - Gagnaskipan
 * Lecture 1, Week 4
 * ADTs with templates
 * 30.01.17
 */

#include <iostream>
#include "Game.h"
#include "Match.h"
#include "Pair.h"

using namespace std;

// Now takes multiple types of variables
template <class T1, class T2>
void printVars(T1 x, T2 y)
{
    cout << "Variable one: " << x << endl;
    cout << "Variable two: " << y << endl;
    cout << endl;
}


int main()
{
    cout << "---- Templates ----" << endl;
    cout << endl;
    // Int
    printVars<int, int>(1,2);
    // Double
    printVars<double, double>(1.1,2.2);
    // Char
    printVars<char, char>('a','b');
    // String
    printVars<string, string>("Edda","Steinunn");
    // Multiple types
    printVars<char, int>('A',6);
    printVars<string, double>("String",6.1);
    // ADT and types
    Game game1(3, "Game of games", 1.1, 2.2);
    printVars<Game, double>(game1, 6.1);
    // Two ADTs
    Game game2(3, "Games of game", 3.3, 4.4);
    printVars<Game, Game>(game1, game2);
    // Two different ADTs
    Match match1(3, "Match of matches", 1.1, 2.2);
    printVars<Game, Match>(game1, match1);
    // ADTs that use T template class
    Pair<int, int> intPair;
    intPair.v1 = 1;
    intPair.v2 = 2;
    cout << intPair << endl;
    // ADTs with templates that take in ADTs
    Pair <Game, Game> gamePair;
    gamePair.v1 = game1;
    gamePair.v2 = game2;
    cout << gamePair << endl;
    // ADTs with templates that take in multiple ADTs
    Pair <Game, Match> varPair;
    varPair.v1 = game1;
    varPair.v2 = match1;
    cout << varPair << endl;


    return 0;
}
