#ifndef POINTBUCKET_H
#define POINTBUCKET_H

#include <vector>
#include <map>
#include <set>

#include "gamepoints.h"

using namespace std;

class PointBucket
{
    public:
        PointBucket();
        virtual ~PointBucket();

        void addGamePoints(GamePoints gp);

        GamePoints getNthHighestPlayer(int n);

        void printHighScoreTableOrderedByScores();
        void printHighScoreTableOrderedByPlayer();
        void printHighScoreTableOrderedByTimeOfEntry();

    protected:

    private:

        vector<GamePoints> gpVec;
        multiset<GamePoints> gpSet;
        map<string, GamePoints> gpMap;

};

#endif // POINTBUCKET_H
