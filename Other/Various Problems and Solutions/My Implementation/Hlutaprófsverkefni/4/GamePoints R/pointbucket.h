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
        vector<GamePoints> gp_vec;
        multiset<GamePoints> gp_set;
        map<string, GamePoints> gp_map;

};

#endif // POINTBUCKET_H
