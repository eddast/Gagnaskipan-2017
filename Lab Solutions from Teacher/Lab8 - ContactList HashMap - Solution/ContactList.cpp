#include "ContactList.h"

using namespace std;

ContactList::ContactList()
{
    head = NULL;
}

ContactList::~ContactList()
{
    remove_all();
}

bool ContactList::add(string key, Contact value)
{
    if(head == NULL){ //IF the list is empty
        NodePtr new_node = new ContactNode(key, value);
        head = new_node; //Add the first node to empty list
        return true; //a new node was added
    }
    NodePtr temp = head;
    while(temp->link != NULL){ //Go to last item in list
        if(temp->data.key == key){ //unless we find the key we are adding
            temp->data.value = value; //then we just update the value
            return false; //a new node wan not added
        }
        temp = temp->link; //check next one
    }
    if(temp->data.key == key){ //also check if the "tail" contains the key we are looking for
        temp->data.value = value; // then update value
        return false; //a new node wan not added
    }
    NodePtr new_node = new ContactNode(key, value);
    temp->link = new_node; //Add new node to the end of the list
    return true; //a new node was added
}

bool ContactList::remove(string key)
{
    NodePtr temp = head;
    if(head == NULL){ //The list is empty
        return false;
    }
    if(temp->data.key == key){ //If we find the key in the first node (most common actually)
        head = head->link; //update the head of the list (becomes NULL, if it was the only node)
        delete temp; //delete the old head
        return true;
    }
    while(temp->link != NULL){ //until we are at the last item in the list
        if(temp->link->data.key == key){ //check if the next item has the key we're looking for
            NodePtr to_del = temp->link;
            temp->link = to_del->link; //bypass the node to be deleted
            delete to_del;
            return true;
        }
        temp = temp->link;
    }
    return false; //We went through the entire list and didn't find the key
}

bool ContactList::contains(string key)
{
    for(NodePtr iter = head; iter != NULL; iter = iter->link){ //run through the list
        if(iter->data.key == key){ //if we find the key
            return true; //return true
        }
    }
    return false; //if we went through whole list and it wasn't found return false
}

Contact ContactList::get(string key)
{
    for(NodePtr iter = head; iter != NULL; iter = iter->link){ //run through the list
        if(iter->data.key == key){ //if we find the key
            return iter->data.value;  //return the value
        }
    }
    throw KeyException(); //if we went through whole list and it wasn't found throw
}

void ContactList::remove_all()
{
    remove_all(head); //call the recursive version
}

void ContactList::remove_all(NodePtr node)
{
    if(node == NULL){ //base case: reached end of list
        return;  //we're done
    }
    remove_all(node->link); //call recursively again
    delete node; //delete on the way back out of the recursion
}

void ContactList::add_to_vector(vector<StringContactPair>& contacts)
{
    for(NodePtr iter = head; iter != NULL; iter = iter->link){ //walk through the whole list
        contacts.push_back(iter->data); //put each contact pair on the referenced vector
    }
}

void ContactList::get_contacts_by_key_prefix(string prefix, vector<StringContactPair>& contacts)
{
    for(NodePtr iter = head; iter != NULL; iter = iter->link){ //walk through the whole list
        if(iter->data.key.find(prefix) == 0){ //if this key fit's the prefix
            contacts.push_back(iter->data); //put the contact pair on the referenced vector
        }
    }
}

vector<StringContactPair> ContactList::to_vector()
{
    vector<StringContactPair> contacts;  //make new vector
    add_to_vector(contacts);  // use helper function to fill vector
    return contacts;
}

ostream& operator <<(ostream& outs, const ContactList& lis)
{
    for(NodePtr iter = lis.head; iter != NULL; iter = iter->link){
        outs << iter->data.value << endl;
    }
    return outs;
}
