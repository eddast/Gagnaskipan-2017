#include <iostream>
#include <string.h>

using namespace std;

///////IMPLEMENT THESE FUNCTIONS///////////////////
//You can add helper functions as you see fit.

bool elfish(const char* strWordPart, bool foundE, bool foundL, bool foundF) {

    //cout << strWordPart << endl;

    if(foundE && foundL && foundF) {
        return true;
    }
    else if(*strWordPart == '\0') {
        return false;
    }
    else {
        if(*strWordPart == 'e' || *strWordPart == 'E') {
            //cout << "---- first letter is E" << endl;
            return elfish(strWordPart+1, true, foundL, foundF);
        }
        else if(*strWordPart == 'l' || *strWordPart == 'L') {
            //cout << "---- first letter is L" << endl;
            return elfish(strWordPart+1, foundE, true, foundF);
        }
        else if(*strWordPart == 'f' || *strWordPart == 'F') {
            //cout << "---- first letter is F" << endl;
            return elfish(strWordPart+1, foundE, foundL, true);
        }
        else {
                return elfish(strWordPart+1, foundE, foundL, foundF);
        }
    }
}

bool elfish(const char* strWord) {
    return elfish(strWord, false, false, false);

}

bool Xish(const char* strX, const char* strWordPart, bool *Xfound, int lengthOfX) {

    bool allFound = true;
    for(int i = 0; i < lengthOfX; i++) {
        if(!Xfound[i]) {
            allFound = false;
            break;
        }
    }

    if(allFound) {
        return true;
    }
    else if(*strWordPart == '\0') {
        return false;
    }
    else {

        for(int i = 0; i < lengthOfX; i++) {
            if(*strWordPart == strX[i]) {
                Xfound[i] = true;
            }
        }
        return Xish(strX, strWordPart+1, Xfound, lengthOfX);
    }
}

bool Xish(const char* strX, const char* strWord) {

    int lengthOfX = strlen(strX);
    //cout << "This is the length of strX, if you need it: " << lengthOfX << endl;

    bool *Xfound = new bool[lengthOfX];

    bool retval = Xish(strX, strWord, Xfound, lengthOfX);

    delete[] Xfound;

    return retval;
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
