#include <iostream>
#include "highscore.h"
#include "highscorebst.h"

using namespace std;

void testInsertOnly() {

    cout << endl << "INSERT TEST" << endl;

    HighScoreBST highScoreTable;

    highScoreTable.addScore(HighScore("player03", 97, 23412));
    highScoreTable.addScore(HighScore("player01", 111, 2343));
    highScoreTable.addScore(HighScore("player02", 100, 241123));
    highScoreTable.addScore(HighScore("player04", 17, 4));
    highScoreTable.addScore(HighScore("player05", 108, 23434));
    highScoreTable.addScore(HighScore("player06", 100, 12));
    highScoreTable.addScore(HighScore("player07", 67, 23));
    highScoreTable.addScore(HighScore("player08", 98, 24));

    highScoreTable.printHighScoresHighestFirst();

    highScoreTable.addScore(HighScore("player09", 21, 232));
    highScoreTable.addScore(HighScore("player10", 117, 253));
    highScoreTable.addScore(HighScore("player11", 15, 2423));
    highScoreTable.addScore(HighScore("player12", 178, 487));
    highScoreTable.addScore(HighScore("player13", 109, 2434));
    highScoreTable.addScore(HighScore("player14", 112, 2344));
    highScoreTable.addScore(HighScore("player15", 167, 273));
    highScoreTable.addScore(HighScore("player16", 58, 234));

    highScoreTable.printHighScoresHighestFirst();
}

void testRemoveOnly() {

    cout << endl << "REMOVE TEST" << endl;

    HighScoreBST highScoreTable(BUILD_HARDCODED_TREE);

    highScoreTable.printHighScoresHighestFirst();

    cout << endl << "remove player15" << endl;

    highScoreTable.remove(HighScore("player15", 167, 273));

    highScoreTable.printHighScoresHighestFirst();

    cout << endl << "remove player09" << endl;

    highScoreTable.remove(HighScore("player09", 21, 232));

    highScoreTable.printHighScoresHighestFirst();

    cout << endl << "remove player16" << endl;

    highScoreTable.remove(HighScore("player16", 58, 234));

    highScoreTable.printHighScoresHighestFirst();

    cout << endl << "remove player12" << endl;

    highScoreTable.remove(HighScore("player12", 178, 487));

    highScoreTable.printHighScoresHighestFirst();

    cout << endl << "remove player07" << endl;

    highScoreTable.remove(HighScore("player07", 67, 23));

    highScoreTable.printHighScoresHighestFirst();

    cout << endl << "remove player03" << endl;

    highScoreTable.remove(HighScore("player03", 97, 23412));

    highScoreTable.printHighScoresHighestFirst();

    cout << endl << "remove player06" << endl;

    highScoreTable.remove(HighScore("player06", 100, 12));

    highScoreTable.printHighScoresHighestFirst();

    cout << endl << "remove player08" << endl;

    highScoreTable.remove(HighScore("player08", 98, 24));

    highScoreTable.printHighScoresHighestFirst();
}

void testInsertAndRemove() {

    cout << endl << "INSERT AND REMOVE TEST" << endl;

    HighScoreBST highScoreTable;

    highScoreTable.addScore(HighScore("player03", 97, 23412));
    highScoreTable.addScore(HighScore("player01", 111, 2343));
    highScoreTable.addScore(HighScore("player02", 100, 241123));
    highScoreTable.addScore(HighScore("player04", 17, 4));
    highScoreTable.addScore(HighScore("player05", 108, 23434));
    highScoreTable.addScore(HighScore("player06", 100, 12));
    highScoreTable.addScore(HighScore("player07", 67, 23));
    highScoreTable.addScore(HighScore("player08", 98, 24));

    highScoreTable.printHighScoresHighestFirst();

    cout << endl << "remove player07" << endl;

    highScoreTable.remove(HighScore("player07", 67, 23));

    highScoreTable.printHighScoresHighestFirst();

    cout << endl << "remove player06" << endl;

    highScoreTable.remove(HighScore("player06", 100, 12));

    highScoreTable.printHighScoresHighestFirst();

    cout << endl << "remove player08" << endl;

    highScoreTable.remove(HighScore("player08", 98, 24));

    highScoreTable.printHighScoresHighestFirst();

    highScoreTable.addScore(HighScore("player09", 21, 232));
    highScoreTable.addScore(HighScore("player10", 117, 253));
    highScoreTable.addScore(HighScore("player11", 15, 2423));
    highScoreTable.addScore(HighScore("player12", 178, 487));
    highScoreTable.addScore(HighScore("player13", 109, 2434));
    highScoreTable.addScore(HighScore("player14", 112, 2344));
    highScoreTable.addScore(HighScore("player15", 167, 273));
    highScoreTable.addScore(HighScore("player16", 58, 234));

    highScoreTable.printHighScoresHighestFirst();

    cout << endl << "remove player15" << endl;

    highScoreTable.remove(HighScore("player15", 167, 273));

    highScoreTable.printHighScoresHighestFirst();

    cout << endl << "remove player09" << endl;

    highScoreTable.remove(HighScore("player09", 21, 232));

    highScoreTable.printHighScoresHighestFirst();

    cout << endl << "remove player16" << endl;

    highScoreTable.remove(HighScore("player16", 58, 234));

    highScoreTable.printHighScoresHighestFirst();

    cout << endl << "remove player12" << endl;

    highScoreTable.remove(HighScore("player12", 178, 487));

    highScoreTable.printHighScoresHighestFirst();

    cout << endl << "remove player07" << endl;

    highScoreTable.remove(HighScore("player07", 67, 23));

    highScoreTable.printHighScoresHighestFirst();

    cout << endl << "remove player06" << endl;

    highScoreTable.remove(HighScore("player06", 100, 12));

    highScoreTable.printHighScoresHighestFirst();

    cout << endl << "remove player08" << endl;

    highScoreTable.remove(HighScore("player08", 98, 24));

    highScoreTable.printHighScoresHighestFirst();

    cout << endl << "remove player03" << endl;

    highScoreTable.remove(HighScore("player03", 97, 23412));

    highScoreTable.printHighScoresHighestFirst();

}

int main() {

    testInsertOnly();
    testRemoveOnly();
    testInsertAndRemove();

    return 0;
}
