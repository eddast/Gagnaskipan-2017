#include "StringContactMap.h"
#include "Hash.h"
#include <algorithm>

using namespace std;

StringContactMap::StringContactMap(int initial_capacity)
{
    // Capacity set to initial capacity and map created
    // Count is zero since map contains no elements
    // Initialize all "buckets" with NULL initially
    capacity = initial_capacity;
    map = new ListPtr[capacity];
    for(int i = 0; i < capacity; i++)
    {
        map[i] = NULL;
    }
    count = 0;
}

StringContactMap::~StringContactMap()
{
    // Calls for a function to delete map
    delete_map();
}

void StringContactMap::load_check()
{
    // Checks if rebuild is necessary and
    // calls it if appropriate
    if((count / capacity) > MAX_LOAD){
        rebuild();
    }
}

void StringContactMap::rebuild()
{
    // Vector created containing all values of map
    vector<StringContactPair> tmp_vec = all_contacts();

    // Current hash map and all elements in it deleted
    delete_map();

    // Map redefined, now with double capacity
    // elements initiated as NULL lists
    capacity = capacity * 2;
    map = new ListPtr[capacity];
    for(int i = 0; i < capacity; i++)
    {
        map[i] = NULL;
    }

    // Elements passed back into map after deleting and resizing it
    for(unsigned int i = 0; i < tmp_vec.size(); i++){
        add(tmp_vec[i].key, tmp_vec[i].value);
    }
}

int StringContactMap::size() const
{
    // count variable manages hash map size
    return count;
}

bool StringContactMap::empty() const
{
    // If map is empty count is 0, meaning return statement will
    // yield false if empty, true otherwise
    return count == 0;
}

vector<StringContactPair> StringContactMap::all_contacts() const
{
    // Creating contact pair vector
    vector<StringContactPair> contact_vec;
    for (int i = 0; i < capacity; i++)
    {
        // Pushing list elements to vector
        // repeatedly for each list in map
        if(map[i] != NULL)
        {
            map[i]->add_to_vector(contact_vec);
        }
    }
    // Sort vector alphabetically, then return
    sort(contact_vec.begin(), contact_vec.end());
    return contact_vec;
}

void StringContactMap::add(string key, Contact value)
{
    // Checks if rebuild is necessary and
    // calls it if appropriate
    load_check();

    // Finds desired index for key
    int index = hash_key(key);

    // If list does not exist at index new list is
    // constructed with an increased count (size)
    if(map[index] == NULL)
    {
        map[index] = new ContactList();
    }

    // In any case, node is added by key and value in list at index
    // Value changed if entry is present (ContactList::add does that for us)
    if(map[index]->add(key, value))
    {
        count++;
    }
}

void StringContactMap::remove(string key)
{
    // Finds index of map where key should be
    // Action only taken if key is in list at index
    int hased_key = hash_key(key);
    if(map[hased_key] != NULL)
    {
        if (map[hased_key]->contains(key))
        {
            // List removes node with key internally
            // If list at index is emptied, count is lowered
            map[hased_key]->remove(key);
            count--;
        }
    }
}

bool StringContactMap::contains(string key)
{
    // Finds index of map where key should be
    int hased_key = hash_key(key);

    // If list at index is NULL, entry does not exist
    // else check is made if list contains key
    if(map[hased_key] == NULL)
    {
        return false;
    }
    else
    {
        return map[hased_key]->contains(key);
    }
}

Contact StringContactMap::get(string key)
{
    // Returns contact value if key is in hash map
    if(contains(key))
    {
        int hased_key = hash_key(key);
        ListPtr clist = map[hased_key];
        return clist->get(key);
    }
    // Otherwise throws an exception
    else
    {
        throw KeyException();
    }
}

vector<Contact> StringContactMap::prefix_search(string prefix) const
{
    // Vector to store values with prefix
    vector<StringContactPair> contacts;

    // Pushing to vector values from every list that matches prefix
    for(int i = 0; i < capacity; i++)
    {
        if(map[i] != NULL)
        {
            map[i]->get_contacts_by_key_prefix(prefix, contacts);
        }
    }

    // Sort by key in increasing order
    sort(contacts.begin(), contacts.end());

    // After using the <StringContactPair> vector for sorting, values are placed
    // in vector<contact> type of vector for Contact manager to remain unchanged
    // then we return the contact vector
    vector<Contact> contact_vec;
    for(unsigned int i = 0; i < contacts.size(); i++)
    {
        contact_vec.push_back(contacts[i].value);
    }

    return contact_vec;
}

int StringContactMap::hash_key(string key)
{
    // uses modulo to get correct value from
    // general hash function to correspond this map
    return hash_value(key) % capacity;
}

void StringContactMap::delete_map()
{
    // Deletes all non-NULL ContactLists in map
    // Then deletes map itself
    for (int i = 0; i < capacity; i++)
    {
        if(map[i] != NULL){
            delete map[i];
        }
    }
    delete [] map;
}

ostream& operator <<(ostream& out, const StringContactMap& map)
{
    // Outputs hash map contacts
    vector<StringContactPair> contacts = map.all_contacts();

    for(size_t i = 0; i < contacts.size(); i++) {
        out << contacts[i].value << endl;
    }
    return out;
}
