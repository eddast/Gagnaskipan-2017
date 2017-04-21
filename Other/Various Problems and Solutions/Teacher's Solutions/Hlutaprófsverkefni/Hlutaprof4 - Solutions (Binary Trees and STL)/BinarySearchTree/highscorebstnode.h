#ifndef HIGHSCOREBSTNODE_H
#define HIGHSCOREBSTNODE_H

#include "highscore.h"

class HighScoreBSTNode
{
    public:
        HighScoreBSTNode(HighScore score, HighScoreBSTNode *left, HighScoreBSTNode *right);
        virtual ~HighScoreBSTNode();

        HighScore score;
        HighScoreBSTNode *left;
        HighScoreBSTNode *right;
};

typedef HighScoreBSTNode* NodePtr;

#endif // HIGHSCOREBSTNODE_H
