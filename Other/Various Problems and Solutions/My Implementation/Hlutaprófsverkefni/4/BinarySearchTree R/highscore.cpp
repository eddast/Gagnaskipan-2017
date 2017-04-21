#include <iostream>
#include <time.h>
#include "highscore.h"

HighScore::HighScore() {

    player = "";
    score = 0;
    timestamp = time(NULL);
}

HighScore::HighScore(string pl, int sc) {

    player = pl;
    score = sc;
    timestamp = time(NULL);
}

HighScore::HighScore(string pl, int sc, int ti) {

    player = pl;
    score = sc;
    timestamp = ti;
}

HighScore::~HighScore()
{
    //dtor
}

///This comparison is necessary for storing the class in an ordered set
bool HighScore::operator <(const HighScore hs) const {
    if(score == hs.score) {
        ///Tie breaker is the timestamp
        return timestamp > hs.timestamp;
    }
    ///This is the main comparison, the score itself
    return score < hs.score;
}

bool HighScore::operator >(const HighScore hs) const {
    return (hs < *this);
}
bool HighScore::operator ==(const HighScore hs) const {
    return (!(hs < *this) && !(*this < hs));
}

ostream &operator <<(ostream &outs, const HighScore &hs) {
    outs << hs.player << ": " << hs.score;
    return outs;
}
