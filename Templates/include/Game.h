#ifndef GAME_H
#define GAME_H
#include <iostream>

using namespace std;

class Game
{
    public:
        Game();
        Game(int id, string name, double hscore, double ascore);
        virtual ~Game();

        int gid;
        string gname;
        double ghscore;
        double gascore;

        friend ostream& operator <<(ostream& out, const Game& g1);

    private:
};

#endif // GAME_H
