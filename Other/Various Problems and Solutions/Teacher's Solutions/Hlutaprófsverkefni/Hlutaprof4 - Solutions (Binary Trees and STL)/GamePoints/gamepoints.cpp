#include <ostream>

#include "gamepoints.h"

GamePoints::GamePoints(string player, double foo, double bar)
{
    this->player = player;
    fooFactor = foo;
    barBase = bar;
}

GamePoints::~GamePoints()
{
    //dtor
}

string GamePoints::getPlayer() const {
    return player;
}

double GamePoints::getTotal() const {
    return fooFactor * barBase;
}

ostream &operator <<(ostream &out, const GamePoints &gp) {

    out << "Player: " << gp.player << " - Score: " << gp.getTotal();
    return out;
}


bool GamePoints::operator <(const GamePoints gp) const {

    return (getTotal() > gp.getTotal());
}
