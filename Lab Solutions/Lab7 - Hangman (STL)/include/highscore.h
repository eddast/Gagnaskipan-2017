#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <string>
#include <iostream>

using namespace std;


class HighScore
{
    public:
        HighScore(string name, int score): name(name), score(score){}
        virtual ~HighScore(){}
        int get_score(){return score; }
        friend bool operator<(const HighScore& h1, const HighScore& h2){return !(h1.score < h2.score); }
        friend ostream& operator <<(ostream& out, const HighScore& h){
            out << h.name << ", score: " << h.score;
            return out;
        }

    private:
        string name;
        int score;
};

#endif // HIGHSCORE_H
