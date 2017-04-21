#include "highscorebstnode.h"

HighScoreBSTNode::HighScoreBSTNode(HighScore score, HighScoreBSTNode *left, HighScoreBSTNode *right) {
    this->score = score;
    this->left = left;
    this->right = right;
}

HighScoreBSTNode::~HighScoreBSTNode() {
}
