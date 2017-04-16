#include "StringContactMap.h"
#include "Hash.h"

#include <algorithm>

using namespace std;

StringContactMap::StringContactMap(int initial_capacity)
{
    map = new ListPtr[initial_capacity]; //The map is an array of lists (buckets), of size initial capacity
    count = 0;      //map is empty
    capacity = initial_capacity;    //current capacity/number of buckets is initial_capacity
    for (int i = 0; i < capacity; i++){
        map[i] = NULL; //Put a value (NULL) in each list pointer, otherwise we can't tell which ones have been used
    }
}

StringContactMap::~StringContactMap()
{
    clear();
}

void StringContactMap::clear(){
    for (int i = 0; i < capacity; i++){
        if (map[i] != NULL){
            delete map[i]; //delete each bucket
        }
    }
    delete[] map; //delete the map array itself
}

void StringContactMap::load_check()  //check if the HashMap has reached its maximum count/capacity ratio
{
    if(count / static_cast<double>(capacity) > MAX_LOAD){
        rebuild(); //if at max load, allocate more memory for it
    }
}

void StringContactMap::rebuild()  //reallocate memory for the hash map
{
    vector<StringContactPair> contacts;  //put all the current contacts into a vector, in order to reinsert them later
    for (int i = 0; i < capacity; i++){
        if(map[i] != NULL){
            map[i]->add_to_vector(contacts); //add contacts from each bucket
        }
    }
    count = 0;
    clear(); //empty and delete all memory
    capacity *= 2; //resize the capacity
    map = new ListPtr[capacity];  //build new map as it was initially built
    for(int i = 0; i < capacity; i++){
        map[i] = NULL;
    }

    for (unsigned int i = 0; i < contacts.size(); i++){ //add all the contacts into the map again from the vector
        add(contacts[i].key, contacts[i].value);
    }
}

int StringContactMap::size() const
{
    return count;
}

bool StringContactMap::empty() const
{
    return count == 0;
}

vector<Contact> StringContactMap::all_contacts() const
{
    vector<StringContactPair> contactPairs;

    //start by filling a vector with all the contact pairs from all the buckets
    for (int i = 0; i < capacity; i++){
        if(map[i] != NULL){
            map[i]->add_to_vector(contactPairs);
        }
    }
    sort(contactPairs.begin(), contactPairs.end()); //sort the vector on the keys to have consistent output

    vector<Contact> contacts; //make a new vector of only contacts

    for (unsigned int i = 0; i < contactPairs.size(); i++) {
        contacts.push_back(contactPairs[i].value); //add the contact from each pair in to the contact vector
    }
    return contacts;
}

void StringContactMap::add(string key, Contact value)
{
    load_check(); //does the map need to be rebuilt?
    int index = hash_key(key); //get an index by hashing the key (hash % capacity in helper function hash_key)
    if(map[index] == NULL){ //if there is no bucket at the indexed location
        map[index] = new ContactList(); //allocate memory for the bucket (no need to waste memory on empty buckets)
    }
    if(map[index]->add(key, value)){ //if adding the contact pair added a node (otherwise a node was updated but nothing added)
        count++;
    }
}

void StringContactMap::remove(string key)
{
    int index = hash_key(key); //get an index by hashing the key (hash % capacity in helper function hash_key)
    if(map[index] != NULL){ //if there is a bucket at the indexed location
        if(map[index]->remove(key)){ //if there was actually a node removed (otherwise this key wasn't in the map)
            count--;
        }
    }
}

bool StringContactMap::contains(string key) const
{
    int index = hash_key(key); //get an index by hashing the key (hash % capacity in helper function hash_key)
    if(map[index] == NULL){ //if there is no bucket at the indexed location there is also no item with this key
        return false;
    }
    return map[index]->contains(key); //simply return the value from the contains function of the list/bucket
}

Contact StringContactMap::get(string key) const
{
    int index = hash_key(key); //get an index by hashing the key (hash % capacity in helper function hash_key)
    if(map[index] == NULL){ //if there is no bucket here, there is also no item with this key in the map
        throw KeyException();
    }
    return map[index]->get(key); //return from the buckets' get function (it will throw KeyException if it isn't found
}

vector<Contact> StringContactMap::prefix_search(string prefix) const
{
    vector<StringContactPair> contactPairs;

    //start by filling a vector with all the contact pairs that fit the prefix from all the buckets
    for(int i = 0; i < capacity; i++){
        if(map[i] != NULL){
            map[i]->get_contacts_by_key_prefix(prefix, contactPairs);
        }
    }
    sort(contactPairs.begin(), contactPairs.end()); //sort the vector on the keys to have consistent output

    vector<Contact> contacts; //make a new vector of only contacts

    for(unsigned int i = 0; i < contactPairs.size(); i++){
        contacts.push_back(contactPairs[i].value); //add the contact from each pair in to the contact vector
    }
    return contacts;
}

ostream& operator <<(ostream& out, const StringContactMap& map)
{
    vector<Contact> contacts = map.all_contacts();

    for(size_t i = 0; i < contacts.size(); i++) {
        out << contacts[i] << endl;
    }
    return out;
}

int StringContactMap::hash_key(string key) const
{
    return ::hash(key) % capacity; //call the hash function and then fit the returned integer within the current capacity/number of buckets
}
