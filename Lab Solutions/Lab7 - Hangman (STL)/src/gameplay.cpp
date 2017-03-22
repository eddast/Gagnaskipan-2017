#include "gameplay.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <algorithm>

using namespace std;

void Gameplay::start_game(){

    // Initializing user input guesses or lives
    try{
        initial_lives = get_initial_lives();
        lives = initial_lives;
    }
    catch(IllegalInputException)
    {
        cout << "\n\t" << "DUDE SRSLY! Illegal input." << endl << endl;
        cout << "\t" << "Quitting HANGMAN..." << endl;
        cout << "\t" << "(AND IT'S ALL YOUR FAULT!)" << endl;
        return;
    }

    // Set secret and consequently encrypted word for game
    set_words();

    // Game loop: loops while game is on
    game_loop();
}

// Game loop, gets user inputs
// Manages game states (won/lost/ongoing)
void Gameplay::game_loop()
{
    while(game_is_on()){
        char input = display_game();
        if(already_inputted(input))
        {
            cout << "\t" << "You already tried this letter, try another" << endl;
            game_loop();
        }
        if(isalpha(input))
        {
            inputs.push_back(input);
            if(check_if_correct(input)){
                cout << "\t" << "Congratulations, decrypted a letter!" << endl;
            }
            else{
                cout << "\t" << "NOPE, life lost!" << endl;
                lives--;
            }
            if(secret_word == encrypted_word){
                won_state();
            }
            if(lives == 0){
                lost_state();
            }
        }
        else{
            cout << "\t" << "Illegal input!" << endl;
        }
    }
}

// Getting lowest high score in high score table
// to determine if user scored a high score
int Gameplay::get_lowest_high_score()
{
    highscore = get_high_score();
    multiset<HighScore>::iterator iter = highscore.end();
    iter--;
    HighScore lh = *iter;
    int lowest_high_score = lh.get_score();

    return lowest_high_score;
}

// Checks if input vector already contains input
// i.e. user has inputted letter before
bool Gameplay::already_inputted(char input)
{
    if(inputs.empty()){
        return false;
    }
    else{
        return (inputs.end() != find(inputs.begin(), inputs.end(), input));
    }
}

// Words set to start game
void Gameplay::set_words()
{
    secret_word = get_random_word();
    for(unsigned int i = 0; i < secret_word.length(); i++){
        encrypted_word.append("-");
    }
}

// Get initial lives input from user
int Gameplay::get_initial_lives()
{
    cout << "\t" << "(*Please note: HANGMAN is case-sensitive)" << endl;
    cout << endl;
    cout << "\t" << "How many guesses? " << endl;
    cout << "\t" << "[six recommended]: ";
    cin >> initial_lives;
    if(initial_lives <= 0)
    {
        throw IllegalInputException();
        return 0;
    }
    else{
        lives = initial_lives;
        cout << endl << endl;

        return initial_lives;
    }
}

// Game displayed and letter inputted
// Figure of hangman drawn
char Gameplay::display_game()
{
    DrawHangman figure;
    char input;
    cout << "\t" << "-------------------------------------------" << endl;
    cout << "\t" << "Word: " << encrypted_word;
    cout << "\tLives remaining: " << lives << endl;
    cout << endl;
    figure.draw(lives);
    cout << "\tGuess a letter: ";
    cin >> input;
    cout << "\t" << "-------------------------------------------" << endl;

    return input;
}

// Gets random word from word bank
string Gameplay::get_random_word(){
    vector<string> words = get_words();
    int random_word = 0;
    srand(time(NULL));
    random_word = rand() % words.size();
    return words[random_word];
}

// Returns a vector of all word bank words
vector<string> Gameplay::get_words(){
    vector <string> words;
    ifstream file ("words.txt");
    string item = "";
    if (file){
        while (getline(file, item)){
            words.push_back(item);
        }
    }

    return words;
}

// Manages lost states
void Gameplay::lost_state(){
    DrawHangman figure;
    Interface interface;
    is_lost = true;
    cout << "\n\t" << "LOSER!! You lost!" << endl;
    cout << "\t" << "HANGMAN HANGED!" << endl;
    cout << "\t" << "Word was: " << secret_word << endl;
    figure.draw(lives);
    char input;
    cout << "\t" << "Return to main menu?: ";
    cin >> input;
    if(input == 'Y'|| input == 'y'){
        interface.start();
    }
    else{
        interface.exit_program();
    }
}

// Manages won states and checks if user scored high score
// Updates high score accordingly
void Gameplay::won_state(){
    Interface interface;
    highscore = get_high_score();
    int lowest_high_score;
    if(highscore.empty()){lowest_high_score = 0; }
    else{lowest_high_score = get_lowest_high_score(); }

    is_won = true;
    gamescore = (20 - (initial_lives - lives)) * (10 - (initial_lives + 1));
    cout << "\n\t" << "Congratulations, YOU WON!" << endl;
    cout << "\t" << "Word was: " << secret_word << endl;
    cout << "\t" << "Score: " << gamescore << endl;
    if(gamescore >= lowest_high_score)
    {
        cout << "\n\t" << "CONGRATULATIONS, A NEW HIGH SCORE!" << endl;
        string name;
        cout << "\tType your nickname" << endl;
        cout << "\t(Only a single word valid): ";
        cin >> name;
        update_high_score(highscore, gamescore, name);
        cout << "\tName and score added to high score board!" << endl;
    }
    char input;
    cout << "\t" << "Return to main menu?: ";
    cin >> input;
    if(input == 'Y'|| input == 'y'){
        interface.start();
    }
    else{interface.exit_program(); }
}

// Adds word to word bank
void Gameplay::add_word(){
    string new_word;
    cout << "\t" << "Input a word: ";
    cin >> new_word;
    if (string::npos != new_word.find_first_of("0123456789"))
    {
        cout << "\t" << "Invalid input" << std::endl;
    }
    else
    {
        fstream filestream;
        filestream.open("words.txt", fstream::app);
        filestream << "\n" << new_word;
        cout << "\t" << "Successfully added to file!" << endl;
        filestream.close();
    }
}

// Returns true if game is neither won or lost
// i.e. returns true if game is still in progress
bool Gameplay::game_is_on(){
    return !(is_won || is_lost);
}

// Encrypted word updated according to input
void Gameplay::update_encrypted_word(char input){
    unsigned int position = secret_word.find(input, 0);
    while(position != string::npos){
        encrypted_word[position] = input;
        position = secret_word.find(input, position + 1);
    }
}

// High score updated and read into file
// Lowest high score erased off score board
void Gameplay::update_high_score(multiset<HighScore> &highscore, int score, string name){
    name = "\t" + name;
    HighScore h(name, score);
    highscore.insert(h);
    multiset<HighScore>::iterator i = highscore.end();
    i--;
    if(highscore.size() > 5)
    {
        highscore.erase(i);
    }
    ofstream fileout("highscores.txt");
    for(multiset<HighScore>::iterator it = highscore.begin(); it != highscore.end(); it++){
        fileout << *it << endl;
    }
}

// Gets high scores from score board as multi-set
// i.e. ordered by score
multiset<HighScore> Gameplay::get_high_score(){
    multiset<HighScore> scores;
    ifstream file("highscores.txt");
    string item = "";
    if (file){
        while (getline(file, item)){
            string s = item.substr(item.find(": ") + 1, item.size());
            int sc = atoi(s.c_str());
            string name = item.substr(0, item.find(","));
            HighScore h(name, sc);
            scores.insert(h);
        }
    }
    return scores;
}

// Prints out words in word bank
void Gameplay::view_word_bank(){
    vector<string> word_bank = get_words();
    for(unsigned int i = 0; i < word_bank.size();i++){
        cout << "\t" << word_bank[i] << endl;
    }
}

// Prints out score board
void Gameplay::view_high_scores(){
    highscore = get_high_score();
    int counter = 1;
    for(multiset<HighScore>::iterator it = highscore.begin(); it != highscore.end(); it++){
        cout << "\t #" << counter << *it << endl;
        counter++;
    }
}

// Check if user deciphered a letter
bool Gameplay::check_if_correct(char input){
    if((secret_word.find(input) != string::npos)){
        update_encrypted_word(input);
        return true;
    }
    else{
        return false;
    }
}
