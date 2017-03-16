#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <string>
#include <vector>
#include <set>
#include "interface.h"
#include "highscore.h"
#include "drawhangman.h"

using namespace std;

class IllegalInputException{};

class Gameplay
{
    public:
        // Initializes game state and score
        Gameplay(): is_won(false), is_lost(false), gamescore(0) {}

        // Useless destructor
        virtual ~Gameplay(){}

        // Loops while game is neither won or lost
        void start_game();

        // Add and view words in word bank
        void add_word();
        void view_word_bank();

        // Functions that get high scores into set and view it
        void view_high_scores();

    private:
        // Game variables with scores, bool checks and words
        multiset<HighScore> highscore;
        vector<char> inputs;
        string secret_word;
        string encrypted_word;
        bool is_won;
        bool is_lost;
        int lives;
        int initial_lives;
        int gamescore;

        // Function that update secret and encrypted words
        void update_encrypted_word(char input);
        void update_high_score(multiset<HighScore> &highscore, int score, string name);

        // Gets multi-set of high scores
        multiset<HighScore> get_high_score();

        // Bool check functions for game loop
        bool game_is_on();
        bool already_inputted(char input);
        bool check_if_correct(char input);

        // Function that work with our word bank file
        string get_random_word();
        vector<string> get_words();
        void encrypt_secret_word();

        // Getter and setter functions for helping the game loop
        int get_lowest_high_score();
        int get_initial_lives();
        void set_words();
        void game_loop();
        char display_game();
        void lost_state();
        void won_state();
};

#endif // GAMEPLAY_H
