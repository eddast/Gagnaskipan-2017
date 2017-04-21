#include <iostream>
#include <fstream>

#include "highscorebst.h"

using namespace std;

HighScoreBST::HighScoreBST() {
    root = NULL;
}

HighScoreBST::HighScoreBST(int code) {
    if(code == BUILD_HARDCODED_TREE) {
        root = new HighScoreBSTNode(HighScore("player03",97,23412),new HighScoreBSTNode(HighScore("player04",17,4),new HighScoreBSTNode(HighScore("player11",15,2423),NULL,NULL),new HighScoreBSTNode(HighScore("player07",67,23),new HighScoreBSTNode(HighScore("player09",21,232),NULL,new HighScoreBSTNode(HighScore("player16",58,234),NULL,NULL)),NULL)),new HighScoreBSTNode(HighScore("player01",111,2343),new HighScoreBSTNode(HighScore("player02",100,241123),new HighScoreBSTNode(HighScore("player08",98,24),NULL,NULL),new HighScoreBSTNode(HighScore("player05",108,23434),new HighScoreBSTNode(HighScore("player06",100,12),NULL,NULL),new HighScoreBSTNode(HighScore("player13",109,2434),NULL,NULL))),new HighScoreBSTNode(HighScore("player10",117,253),new HighScoreBSTNode(HighScore("player14",112,2344),NULL,NULL),new HighScoreBSTNode(HighScore("player12",178,487),new HighScoreBSTNode(HighScore("player15",167,273),NULL,NULL),NULL))));
    }
    else {
        root = NULL;
    }
}

HighScoreBST::~HighScoreBST()
{
    while(root != NULL) {
        removeNode(root);
    }
}

void HighScoreBST::addScore(HighScore score) {

    root = insertRecursive(score, root);
}

void HighScoreBST::remove(HighScore score) {

    removeRecursive(score, root);
}

HighScoreBSTNode* HighScoreBST::insertRecursive(HighScore &score, HighScoreBSTNode *node) {
    if(node == NULL) {
        return new HighScoreBSTNode(score, NULL, NULL);
    }
    if(score < node->score) {
        node->left = insertRecursive(score, node->left);
        return node;
    }
    else {
        node->right = insertRecursive(score, node->right);
        return node;
    }
}

void HighScoreBST::removeRecursive(HighScore &score, HighScoreBSTNode* &node) {

    if(node == NULL) {
        ///The score was not found at all!
        return;
    }
    if(score < node->score) {
        ///Score is to the left
        removeRecursive(score, node->left);
    }
    else if(node->score < score) {
        ///Score is to the right
        removeRecursive(score, node->right);
    }
    else {
        ///This is the node, remove it
        removeNode(node);
    }
}

void HighScoreBST::removeNode(HighScoreBSTNode* &node) {

    ///Node with no children, delete it
    if(node->left == NULL && node->right == NULL) {
        delete node;
        node = NULL;
    }
    ///Left child only, bypass
    else if(node->right == NULL) {
        HighScoreBSTNode *tmp = node;
        node = node->left;
        delete tmp;
    }
    ///Right child only, bypass
    else if(node->left == NULL) {
        HighScoreBSTNode *tmp = node;
        node = node->right;
        delete tmp;
    }
    ///Two children, do content switch with the leftmost node in the right subtree
    else {
        node->score = removeAndReturnScoreFromLeftMost(node->right);
    }
}

HighScore HighScoreBST::removeAndReturnScoreFromLeftMost(HighScoreBSTNode* &node) {

    ///This function is implemented but you may change it if you wish
    ///It finds the leftmost node under the node that is sent in,
    ///saves its score, removes the node and the returns the score
    if(node->left == NULL) {
        HighScore score = node->score;
        removeNode(node);
        return score;
    }
    return removeAndReturnScoreFromLeftMost(node->left);
}

void HighScoreBST::printHighScoresHighestFirst() {
    cout << endl << "HIGH SCORES" << endl << endl;

    printRecursiveHighestFirst(root);
}

void HighScoreBST::printRecursiveHighestFirst(HighScoreBSTNode *node) {
    if(node != NULL) {
        printRecursiveHighestFirst(node->right);
        cout << node->score << endl;
        printRecursiveHighestFirst(node->left);
    }
}
