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
    /*while(root != NULL) {
        removeNode(root);
    }*/
    //free_memory(root);
}

void HighScoreBST::free_memory(NodePtr node)
{
    if(node == NULL)
    {
        return;
    }
    free_memory(node->left);
    free_memory(node->right);

    delete node;
}

void HighScoreBST::addScore(HighScore score) {
    NodePtr &node = find(score, root);
    if(node == NULL)
    {
        node = new HighScoreBSTNode(score, NULL, NULL);
    }

}

void HighScoreBST::remove(HighScore score) {
    NodePtr &node = find(score, root);
    if(node != NULL)
    {
        removeNode(node);
    }
}

NodePtr &HighScoreBST::find(HighScore &score, NodePtr &node) {

    if(node == NULL) {
        return node;
    }
    if(node->score == score)
    {
        return node;
    }
    else
    {
        if(score < node->score) {
            return find(score, node->left);
        }
        else{
            return find(score, node->right);
        }

    }
}

void HighScoreBST::removeNode(NodePtr &node) {
    if(node->left == NULL)
    {
        NodePtr tmp = node;
        node = node->right;
        delete tmp;
    }
    else if(node->right == NULL)
    {
        NodePtr tmp = node;
        node = node->left;
        delete tmp;
    }
    else if(node->left != NULL && node->right != NULL)
    {
        NodePtr &tmp = get_leftmost(node->right);
        NodePtr to_delete = tmp;
        node->score = tmp->score;
        tmp = tmp->right;
        removeNode(to_delete);
    }
}

NodePtr &HighScoreBST::get_leftmost(NodePtr &node) {

    if(node->left == NULL)
    {
        return node;
    }
    else
    {
        return get_leftmost(node->left);
    }
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
