#ifndef HIGHSCORETABLE_H
#define HIGHSCORETABLE_H

#include <set>

#include "highscorebstnode.h"

#define BUILD_HARDCODED_TREE 1

using namespace std;

class HighScoreBST
{
    public:
        HighScoreBST();
        HighScoreBST(int code);
        virtual ~HighScoreBST();

        void addScore(HighScore score);

        void remove(HighScore score);
        void printHighScoresHighestFirst();

    private:
        ///Can also use
        ///NodePtr root;
        HighScoreBSTNode *root;

        HighScoreBSTNode* insertRecursive(HighScore &score, HighScoreBSTNode *node);

        void removeRecursive(HighScore &score, HighScoreBSTNode* &node);

        void removeNode(HighScoreBSTNode* &node);

        HighScore removeAndReturnScoreFromLeftMost(HighScoreBSTNode* &node);

        void printRecursiveHighestFirst(HighScoreBSTNode *node);
};

#endif // HIGHSCORETABLE_H
