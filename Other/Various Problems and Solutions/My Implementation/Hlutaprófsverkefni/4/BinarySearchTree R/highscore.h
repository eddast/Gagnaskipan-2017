#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <string>
#include <set>

using namespace std;

class HighScore
{
    public:
        HighScore();
        HighScore(string pl, int sc);
        HighScore(string pl, int sc, int ti);
        virtual ~HighScore();

        ///Overloading the comparison operator so that it can be used in an ordered data structure (like a binary search tree)
        bool operator <(const HighScore hs) const;

        bool operator >(const HighScore hs) const;
        bool operator ==(const HighScore hs) const;

        ///This one is for when they are all written to the screen
        friend ostream &operator <<(ostream &outs, const HighScore &hs);

    private:
        string player;
        int score;
        int timestamp;
};

#endif // HIGHSCORE_H
