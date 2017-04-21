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
    pair<string, GamePoints> gp_pair(gp.getPlayer(), gp);
    gp_map.insert(gp_pair);
    gp_vec.push_back(gp);
    gp_set.insert(gp);
}

GamePoints PointBucket::getNthHighestPlayer(int n) {
    multiset<GamePoints>::iterator it = gp_set.begin();
    int set_size = gp_set.size();
    for(int i = 0; i < set_size - n; i++)
    {
        it++;
    }
    return *it;

}

void PointBucket::printHighScoreTableOrderedByScores() {
    cout << "ORDERED BY TOTAL SCORE" << endl;
    for(multiset<GamePoints>::iterator it = gp_set.begin(); it != gp_set.end(); it++)
    {
        cout << *it << endl;
    }
}

void PointBucket::printHighScoreTableOrderedByPlayer() {
    cout << "APLHABETICAL BY PLAYER" << endl;
    for(multimap<string, GamePoints>::iterator it = gp_map.begin(); it != gp_map.end(); it++)
    {
        pair<string, GamePoints> p = *it;
        cout << p.second << endl;
    }
}

void PointBucket::printHighScoreTableOrderedByTimeOfEntry() {
    cout << "FIFO!!!" << endl;
    for(vector<GamePoints>::iterator it = gp_vec.begin(); it != gp_vec.end(); it++)
    {
        cout << *it << endl;
    }

}
