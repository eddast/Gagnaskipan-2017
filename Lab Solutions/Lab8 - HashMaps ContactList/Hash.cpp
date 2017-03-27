#include "Hash.h"

// Hashes the key into an integer
unsigned int hash_value(string s)
{
    int sum = 0;

    // sum up ASCII codes of key's characters
    for (unsigned int i = 0; i < s.size(); i++)
    {
        char ch = s.at(i);
        sum = sum + ch;
    }

    // Returns sum that corresponds to hashed integer
    // Function only hashes, does not yield correct value for map
    return sum;
}
