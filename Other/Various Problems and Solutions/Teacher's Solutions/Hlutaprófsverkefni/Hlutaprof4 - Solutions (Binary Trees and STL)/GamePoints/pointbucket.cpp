#include <iostream>

#include "pointbucket.h"

using namespace std;

PointBucket::PointBucket()
{
    //ctor
}

PointBucket::~PointBucket()
{
    //dtor
}

void PointBucket::addGamePoints(GamePoints gp) {

    ///TODO: Implement

    gpVec.push_back(gp);
    gpSet.insert(gp);
    gpMap.insert(pair<string, GamePoints>(gp.getPlayer(), gp));
}

GamePoints PointBucket::getNthHighestPlayer(int n) {

    ///TODO: Implement
    ///Return the GamePoints for the Nth highest scoring player.  1 is highest.

    int i = 1;
    for(set<GamePoints>::iterator it = gpSet.begin(); it != gpSet.end(); it++) {
        if(i == n) {
            return *it;
        }
        i++;
    }
    return GamePoints("", 0, 0);
}

void PointBucket::printHighScoreTableOrderedByScores() {

    ///TODO: Implement
    ///Print every score that has been entered, highest score first, ordered by total score

    cout << "ORDERED BY TOTAL SCORE" << endl;
    for(set<GamePoints>::iterator it = gpSet.begin(); it != gpSet.end(); it++) {
        cout << *it << endl;
    }
}

void PointBucket::printHighScoreTableOrderedByPlayer() {

    ///TODO: Implement
    ///Print every score that has been entered, alphabetically be player name

    cout << "APLHABETICAL BY PLAYER" << endl;
    for(map<string, GamePoints>::iterator it = gpMap.begin(); it != gpMap.end(); it++) {
        cout << it->second << endl;
    }
}

void PointBucket::printHighScoreTableOrderedByTimeOfEntry() {

    ///TODO: Implement
    ///Print every score that has been entered, in the order they were entered

    cout << "FIFO!!!" << endl;
    for(vector<GamePoints>::iterator it = gpVec.begin(); it != gpVec.end(); it++) {
        cout << *it << endl;
    }
}
