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

        ///You must implement this function
        void addScore(HighScore score);

        ///This function is implemented but you may change it if you wish
        void remove(HighScore score);
        void printHighScoresHighestFirst();

    private:
        ///Can also use
        ///NodePtr root;
        HighScoreBSTNode *root;

        void free_memory(NodePtr node);

        ///This function is implemented but you may change it if you wish
        NodePtr &find(HighScore &score, NodePtr &node);

        ///You must implement this function
        void removeNode(NodePtr &node);

        ///This function is implemented but you may change it if you wish
        NodePtr &get_leftmost(NodePtr &node);

        void printRecursiveHighestFirst(HighScoreBSTNode *node);
};

#endif // HIGHSCORETABLE_H
