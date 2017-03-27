#include "ContactList.h"
#include <iostream>
using namespace std;

// Constructor and destructor
ContactList::ContactList(){head = NULL; }
ContactList::~ContactList(){remove_all(); }

bool ContactList::add(string key, Contact value)
{
    NodePtr tmp = head;

    // If node with key is in list value is updated
    if(contains(key))
    {
        // If temp is head we don't want to iterate
        // just change value of temp
        if(tmp->data.key == key)
        {
            tmp->data.value = value;
        }
        // Otherwise we iterate through list
        // setting value at correct node
        else
        {
            while(tmp != NULL)
            {
                if(tmp->data.key == key)
                {
                    tmp->data.value = value;
                }
                tmp = tmp->link;
            }
        }
        // False returned since nothing was added,
        // Only value changes
        return false;
    }
    // If key is not in list, a new node with key
    // and value is added to it
    else
    {
        // Edge case, if list is empty
        // head becomes the new node
        if(tmp == NULL)
        {
            head = new ContactNode(key, value, NULL);
        }
        else
        {
            // Otherwise we iterate through list to get to
            // list end, and there we add the new node
            while(tmp->link != NULL){tmp = tmp->link; }
            tmp->link = new ContactNode(key, value, NULL);
        }
        // True returned since a node was added
        return true;
    }
}

bool ContactList::remove(string key)
{
    // Action taken only if list is not empty
    if(head != NULL)
    {
        NodePtr tmp = head;
        // If head node contains key, head moves to next node,
        // and node is then deleted
        if(tmp->data.key == key)
        {
            head = tmp->link;
            delete tmp;
            return true;
        }
        // if not, we look for the node to remove,
        // fix previous node's link pointer and then delete it
        else
        {
            while(tmp->link != NULL)
            {
                if(tmp->link->data.key == key)
                {
                    NodePtr prev = tmp;
                    NodePtr toremove = tmp->link;
                    prev->link = toremove->link;
                    delete toremove;
                    return true;
                }
                tmp = tmp->link;
            }
        }
    }
    // If program gets to this point, nothing was removed
    // due to nothing being found in list matching key,
    // so we return false
    return false;
}

// Bool check if list contains node with certain key
bool ContactList::contains(string key)
{
    // Check not needed for an empty list
    // so we only proceed with a non-empty list
    if(head != NULL)
    {
        NodePtr node = head;
        // Returns true if node is found
        // in list, otherwise proceeds to return false
        do
        {
            if(node->data.key == key){return true; }
            node = node->link;
        }while(node != NULL);
    }
    return false;
}

Contact ContactList::get(string key)
{
    // Check not needed for an empty list
    // so we only proceed with a non-empty list
    if(head != NULL)
    {
        NodePtr tmp = head;
        // Edge case: if head contains key no need to
        // iterate through list
        if(tmp->data.key == key)
        {
            return tmp->data.value;
        }
        // Otherwise we iterate through list, return corresponding node's
        // value if it's found, if not program proceeds to throw an exception
        else
        {
            while(tmp != NULL)
            {
                if(tmp->data.key == key)
                {
                    return tmp->data.value;
                }
                tmp = tmp->link;
            }
        }
    }
    throw KeyException();
}

void ContactList::remove_all()
{
    // Clears nodes in list by
    // iterating through list
    NodePtr tmp = head;
    while (tmp != NULL)
    {
        tmp = tmp->link;
        delete head;
        head = tmp;
    }
    // preventing dangling pointers
    head = NULL;
}

void ContactList::add_to_vector(vector<StringContactPair>& contacts)
{
    NodePtr node = head;
    // Iterates through list, pushing every node's
    // data into the contacts vector
    while(node != NULL)
    {
        contacts.push_back(node->data);
        node = node->link;
    }
}

void ContactList::get_contacts_by_key_prefix(string prefix, vector<StringContactPair>& contacts)
{
    // Calls for a recursive helper function
    prefix_search(head, prefix, contacts);
}

void ContactList::prefix_search(NodePtr node, string prefix, vector<StringContactPair>& contacts) {
    if(node->link != NULL)
    {
        // Searches for prefix recursively
        // Pushes values that match into a vector
        prefix_search(node->link, prefix, contacts);
        if(!(node->data.key.find(prefix)))
        {
            contacts.push_back(node->data);
        }
    }
}

vector<StringContactPair> ContactList::to_vector()
{
    // returns vector of contacts
    vector<StringContactPair> contacts;
    add_to_vector(contacts);
    return contacts;
}

bool ContactList::empty()
{
    return head == NULL;
}

ostream& operator <<(ostream& outs, const ContactList& lis)
{
    // Prints list by iterating through it
    NodePtr tmp = lis.head;
    while(tmp != NULL) {
        outs << tmp->data.value << endl;
        tmp = tmp->link;
    }
    return outs;
}
