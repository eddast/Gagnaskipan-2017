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

bool operator <(const GamePoints gp1, const GamePoints gp2)
{
    if(gp1.getTotal() == gp2.getTotal())
    {
        if(gp1.getPlayer() < gp2.getPlayer())
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    else if(gp1.getTotal() < gp2.getTotal())
    {
        return true;
    }
    else
    {
        return false;
    }
}
