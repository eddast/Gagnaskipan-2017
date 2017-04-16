#include "Hash.h"

unsigned int hash(string s)
{
    unsigned long h = 5381;
    char c;
    for(unsigned int i = 0; i < s.size(); i++){
        c = s[i];
        h = (h << 5) + h + c;
    }
    return h;
}
