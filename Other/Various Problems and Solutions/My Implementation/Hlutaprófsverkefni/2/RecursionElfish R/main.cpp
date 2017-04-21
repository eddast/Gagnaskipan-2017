#include <iostream>
#include <string.h>

using namespace std;

///////IMPLEMENT THESE FUNCTIONS///////////////////
//You can add helper functions as you see fit.


/// Function declarations so that function's order won't matter
bool contains(const char* word, char char1, char char2 = ' ');
bool elfish_recursive(const char* word, int index);
bool elfish(const char* strWord);
bool Xish(const char* strX, const char* strWord);
bool Xish_recursive(const char* word, const char* compare_word, int index);



bool elfish(const char* strWord) {

    // Only makes a call to a recursive function
    return elfish_recursive(strWord, 0);
}

bool elfish_recursive(const char* word, int index)
{
    // Strings of uppercase and lowercase characters
    // That are needed for word to be elfish
    string upper_case = "ELF";
    string lower_case = "elf";

    // Base case: if index is 3 and function hasn't returned false
    // word is elfish and function returns true
    if(index == 3){return true; }

    if(contains(word, upper_case[index], lower_case[index])){
        // Recursively checks if word contains each letter
        return elfish_recursive(word, index+1);
    }
    else
    {
        // If any character is not present in word
        // function returns false
        return false;
    }
}

bool Xish(const char* strX, const char* strWord) {

    // Returns a recursive call to
    return Xish_recursive(strX, strWord, 0);
}

bool Xish_recursive(const char* word, const char* compare_word, int index)
{
    // Base case: if iteration equals word length
    // and function has not returned false, word is Xish
    // and function returns true
    int word_length = strlen(word);
    if(index == word_length){return true; }

    if(contains(compare_word, word[index])){
        // Recursively checks if word contains each letter
        return Xish_recursive(word, compare_word, index+1);
    }
    else
    {
        // If any character is not present in word
        // function returns false
        return false;
    }
}

// Char2 has a default value as an illegal character.
// (illegal character set as ' ' (space), as that is the
// only character that can never be present in a word)
// If function is called with only one character, function only
// takes one character into account
bool contains(const char* word, char char1, char char2)
{
    int word_length = strlen(word);

    // Iterates through word, checking if it contains
    // either uppercase or lowercase character
    for(int i = 0; i < word_length; i++)
    {
        // if two characters are taken into account
        // both are checked for in word
        if(char2 != ' ')
        {
            if(word[i] == char1 || word[i] == char2)
            {
                return true;
            }
        }
        // if not, only the one specified character is checked
        else
        {
            if(word[i] == char1)
            {
                return true;
            }
        }
    }
    // Returns false if character is not found
    return false;
}


////////////////////////////////DO NOT CHANGE ANYTHING BELOW THIS LINE////////////////////////////////////////////


void checkXish(string X, string word) {

    if(Xish(X.c_str(), word.c_str())) {
        cout << word << " is " << X << "-ish" << endl;
    }
    else {
        cout << word << " is NOT " << X << "-ish" << endl;
    }
}

void checkElfish(string word) {

    if(elfish(word.c_str())) {
        cout << word << " is elfish" << endl;
    }
    else {
        cout << word << " is NOT elfish" << endl;
    }
}

int main() {

    cout << endl << "+++++ --- ELFISH TEST --- +++++" << endl << endl;

    cout << "Your output:     ";
    checkElfish("elf");
    cout << "Expected output: elf is elfish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("Elf");
    cout << "Expected output: Elf is elfish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("eLf");
    cout << "Expected output: eLf is elfish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("elF");
    cout << "Expected output: elF is elfish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("ELF");
    cout << "Expected output: ELF is elfish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("ElF");
    cout << "Expected output: ElF is elfish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("EF");
    cout << "Expected output: EF is NOT elfish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("ElFeLf");
    cout << "Expected output: ElFeLf is elfish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("Cake");
    cout << "Expected output: Cake is NOT elfish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("Election");
    cout << "Expected output: Election is NOT elfish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("Frauline");
    cout << "Expected output: Frauline is elfish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("Leaf");
    cout << "Expected output: Leaf is elfish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("Forest");
    cout << "Expected output: Forest is NOT elfish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("Gagnaskipan");
    cout << "Expected output: Gagnaskipan is NOT elfish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("Element");
    cout << "Expected output: Element is NOT elfish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("Feline");
    cout << "Expected output: Feline is elfish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("Laugh");
    cout << "Expected output: Laugh is NOT elfish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("Foliage");
    cout << "Expected output: Foliage is elfish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkElfish("Follow");
    cout << "Expected output: Follow is NOT elfish" << endl;
    cout << endl;




    cout << endl << "+++++ --- X-ISH TEST --- +++++" << endl << endl;

    cout << "Your output:     ";
    checkXish("Fo", "Follow");
    cout << "Expected output: Follow is Fo-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkXish("Fw", "Follow");
    cout << "Expected output: Follow is Fw-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkXish("lo", "Follow");
    cout << "Expected output: Follow is lo-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkXish("Fr", "Follow");
    cout << "Expected output: Follow is NOT Fr-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkXish("wolloFp", "Follow");
    cout << "Expected output: Follow is NOT wolloFp-ish" << endl;
    cout << endl;

    cout << "Your output:     ";
    checkXish("wolloF", "Follow");
    cout << "Expected output: Follow is wolloF-ish" << endl;
    cout << endl;



}
