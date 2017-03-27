#ifndef STRINGCONTACTMAP_H
#define STRINGCONTACTMAP_H

#include <iostream>
#include <string>
#include <vector>
#include "ContactNode.h"

class KeyException { };

class StringContactMap {

    public:
        // Creates an empty map.
        StringContactMap ();

        ~StringContactMap();

        // Returns the number ef entries in this map.
        int size() const;

        // Returns true if and only if the map contains no entries.
        bool empty() const;

        // Returns a vector containing the contacts in this map, ordered by
        // their keys in increasing order.
        vector<Contact> all_contacts() const;

        // Adds the specified key to the map associated with the specified
        // contact.
        // If there exists an entry in the map with the specified key, it
        // should be replaced with the specified value.
        void add(string key, Contact value);

        // Returns true if and only if there exists an entry in the map with
        // the specified key.
        bool contains(string key) const;

        // Returns the contact associated wih the specified key.
        // Throws KeyException if no such contact exists.
        Contact get(string key) const;

        // Removes the entry with the specified key from the map.
        // If no entry in the map has the specified key, this operation has no
        // effect.
        void remove(string key);

        // Returns a vector containing the contacts in this map, whose key is
        // prefixed by 'prefix'. The contacts are ordered by their
        // keys in increasing order,
		// NOTE: This is for part C of the assignment.
        vector<Contact> prefix_search(string prefix) const;

        friend ostream& operator <<(ostream& out, const StringContactMap& map);

    private:
        NodePtr root;
        NodePtr& find(NodePtr& node, string key) const;
        int size(NodePtr node) const;
        NodePtr& minContact(NodePtr& node);
        void remove(NodePtr& node, string key);
        Contact get(NodePtr node, string key) const;
        bool contains(NodePtr node, string key) const;
        void add(NodePtr& r, string key, Contact value);
        vector<Contact> all_contacts(NodePtr node) const;
        // Deallocates all memory allocated for the specified tree.
        void free_memory(NodePtr node);

        // Optoional helper function
        // Adds the the Contacts in the specified tree, whose key is prefixed
        // by 'prefix', to the vector v. The contacts are ordered by their keys
        // in increasing order.
		// NOTE: This is for part C of the assignment.
        void prefix_search(NodePtr node, string prefix, vector<Contact>& v) const;
};

#endif
