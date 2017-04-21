#ifndef GAMEPOINTS_H
#define GAMEPOINTS_H

#include <string>

using namespace std;

class GamePoints
{
    public:
        GamePoints(string player, double foo, double bar);
        virtual ~GamePoints();

        string getPlayer() const;
        double getTotal() const;

        friend ostream &operator <<(ostream &out, const GamePoints &gp);

        bool operator <(const GamePoints gp) const;

    protected:

    private:
        string player;
        double fooFactor;
        double barBase;
};

#endif // GAMEPOINTS_H
