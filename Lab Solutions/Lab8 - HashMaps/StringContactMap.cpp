#include "StringContactMap.h"
#include "Hash.h"
#include <algorithm>

using namespace std;

StringContactMap::StringContactMap(int initial_capacity)
{
    // Capacity set to initial capacity and map created
    // Count is zero since map contains no elements
    capacity = initial_capacity;
    map = new ListPtr[capacity];
    count = 0;
}

StringContactMap::~StringContactMap()
{
    // map deleted, cout set to 0 in case
    // because map now of course contains nothing
    delete map;
    count = 0;
}

void StringContactMap::load_check()
{

}

void StringContactMap::rebuild()
{

}

int StringContactMap::size() const
{
    // Count counts size of hash-map
    return count;
}

bool StringContactMap::empty() const
{
    // If map is empty, count is 0
    return count == 0;
}

vector<Contact> StringContactMap::all_contacts() const
{
    // This function should return a vector, containing all the contacts in
    // this map, orderd by their keys in increasing order.  If vec is a vector
    // of StringContactPairs, then vec can be sorted using the sort function
    // (provided by algorithm header) as follows
    // sort(vec.begin(), vec.end())
    return vector<Contact>();
}

void StringContactMap::add(string key, Contact value)
{

}

void StringContactMap::remove(string key)
{

}

bool StringContactMap::contains(string key) const
{
    return false;
}

Contact StringContactMap::get(string key) const
{
    return Contact();
}

vector<Contact> StringContactMap::prefix_search(string prefix) const
{
    // You can use the same method as in all_contacts() here to sort the
    // StringContactPairs.
    return vector<Contact>();
}

int StringContactMap::hash_key(string key)
{
    // uses modulo to get correct value from
    // general hash function to correspond this map
    return hash(key) % count;
}

ostream& operator <<(ostream& out, const StringContactMap& map)
{
    // Outputs hash map
    vector<Contact> contacts = map.all_contacts();

    for(size_t i = 0; i < contacts.size(); i++) {
        out << contacts[i] << endl;
    }
    return out;
}

