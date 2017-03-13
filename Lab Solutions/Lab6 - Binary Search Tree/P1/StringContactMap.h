#ifndef STRINGCONTACTMAP_H
#define STRINGCONTACTMAP_H

#include <iostream>
#include <string>
#include <vector>
#include "ContactNode.h"

class KeyException { };

class StringContactMap {

    public:
        StringContactMap ();
        ~StringContactMap();

        int size() const;
        bool empty() const;
        vector<Contact> all_contacts() const;
        void add(string key, Contact value);
        bool contains(string key);
        Contact get(string key);

        // Removes the entry with the specified key from the map.
        // If no entry in the map has the specified key, this operation has no
        // effect.
        void remove(string key);

        // Returns a vector containing the contacts in this map, whose key is
        // prefixed by 'prefix'. The contacts are ordered by their
        // keys in increasing order,
		// NOTE: This is for part 3 of the assignment.
        vector<Contact> prefix_search(string prefix) const;
        bool isleaf(ContactNode* node);
        friend ostream& operator <<(ostream& out, const StringContactMap& map);
    private:
        int tree_size;
        NodePtr root;
        // Deallocates all memory allocated for the specified tree.
        void free_memory(NodePtr node);
        NodePtr &getLeftmost(NodePtr &node);
        void removeNode(NodePtr &node);
        // Helper function that pushes to vector in inorder
        void inorder_to_vector(NodePtr node, vector<Contact>& contacts) const;
        // Helper function: finds node with certain key
        NodePtr &find(NodePtr& node, string key) const;

        // Optoional helper function
        // Adds the the Contacts in the specified tree, whose key is prefixed
        // by 'prefix', to the vector v. The contacts are ordered by their keys
        // in increasing order.
		// NOTE: This is for part C of the assignment.
        void prefix_search(NodePtr node, string prefix, vector<Contact>& v) const;
};

#endif
