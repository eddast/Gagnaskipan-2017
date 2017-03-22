#include "ContactList.h"

using namespace std;

ContactList::ContactList()
{
}

ContactList::~ContactList()
{
}

bool ContactList::add(string key, Contact value)
{
    return true;
}

bool ContactList::remove(string key)
{
    return true;
}

bool ContactList::contains(string key)
{
    return true;
}

Contact ContactList::get(string key)
{
    return Contact();
}

void ContactList::remove_all()
{
}

void ContactList::add_to_vector(vector<StringContactPair>& contacts)
{
}

void ContactList::get_contacts_by_key_prefix(string prefix, vector<StringContactPair>& contacts)
{
}

vector<StringContactPair> ContactList::to_vector()
{
    return vector<StringContactPair>();
}

ostream& operator <<(ostream& outs, const ContactList& lis)
{
    return outs;
}
