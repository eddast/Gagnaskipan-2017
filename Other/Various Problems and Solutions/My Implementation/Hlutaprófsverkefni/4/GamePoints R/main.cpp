#include <iostream>

#include "gamepoints.h"
#include "pointbucket.h"

using namespace std;

int main() {

    PointBucket pb;
    pb.addGamePoints(GamePoints("carson", 0.2, 30));
    pb.addGamePoints(GamePoints("stefan", 0.3, 30));
    pb.addGamePoints(GamePoints("osmond", 0.3, 20));
    pb.addGamePoints(GamePoints("crista", 0.4, 10));
    pb.addGamePoints(GamePoints("anabel", 0.7, 6));

    cout << endl;
    pb.printHighScoreTableOrderedByScores();

    cout << endl;
    pb.printHighScoreTableOrderedByPlayer();

    cout << endl;
    pb.printHighScoreTableOrderedByTimeOfEntry();

    cout << endl;

    cout << "Second highest player: " << pb.getNthHighestPlayer(2) << endl;
    cout << "Fifth highest player:  " << pb.getNthHighestPlayer(5) << endl;
    cout << "Top scorer:            " << pb.getNthHighestPlayer(1) << endl;


    return 0;
}
