#include "Game.h"

Game::Game()
{
    gid = 0;
    gname = "";
    ghscore = 0;
    gascore = 0;
}

Game::Game(int id, string name, double hscore, double ascore)
{
    gid = id;
    gname = name;
    ghscore = hscore;
    gascore = ascore;
}

Game::~Game()
{
    //dtor
}

ostream& operator <<(ostream& out, const Game& g1)
{
    cout << "["
         << "ID: " << g1.gid
         << ", Game: " << g1.gname
         << ", Home Score: " << g1.ghscore
         << ", Away Score: " << g1.gascore
         << "]";

         return out;
}
