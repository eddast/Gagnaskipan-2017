#ifndef GAME_H
#define GAME_H

#include <string>

using namespace std;

class Game
{
    public:
        Game();
        Game(int id, string name, double v1, double v2);
        virtual ~Game();

        // Values nodes keep
        int id;
        string name;
        double v1;
        double v2;

        friend ostream& operator <<(ostream& out, const Game& game);

    protected:

    private:
};

#endif // GAME_H
