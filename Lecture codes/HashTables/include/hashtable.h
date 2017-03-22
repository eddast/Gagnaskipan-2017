#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <list>
#include <functional>

#define keypair pair<string, T>
#define bucket_iterator typename list<keypair>::iterator

using namespace std;
class ElementNotFoundException{};

template <class T>
class HashTable
{
    public:
        HashTable()
        {
            size = 0;
            arrayLength = 1024;
            array = new list<keypair>[arrayLength];
        }
        virtual ~HashTable(){}
        void insert(string key, T data)
        {
            int index = h(key) % arrayLength;
            array[index].push_back(keypair(key,data));
        }

        T find(string key)
        {
            int index = h(key) % arrayLength;
            for(bucket_iterator it = array[index].begin(); it != array[index].end(); it++)
            {
                if(it->first == key){
                    return it->second;
                }
            }
            throw ElementNotFoundException();
            return -1;
        }

    private:

        int size;
        int arrayLength;
        list<keypair> *array;
        hash<string> h;
        /*int hash(string str)
        {
            int sum = 0;
            for (unsigned int k = 0; k < str.length(); k++)
                sum = sum + int(str[k]);

            return sum;
        }*/
};

#endif // HASHTABLE_H
