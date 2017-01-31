#include "Game.h"
#include <string>
#include <ostream>

using namespace std;

Game::Game()
{
    this->id = 0;
    this->name = "";
    this->v1 = 0.0;
    this->v2 = 0.0;
}

Game::Game(int id, string name, double v1, double v2)
{
    this->id = id;
    this->name = name;
    this->v1 = v1;
    this->v2 = v2;
}

Game::~Game()
{
    //dtor
}

ostream& operator <<(ostream& out, const Game& game){

    out << "[Name: " << game.name << ", ScoreA: " << game.v1 << ", ScoreB: " << game.v2 << "]" << endl;
    return out;
}
