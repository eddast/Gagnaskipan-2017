#include "StringContactMap.h"

using namespace std;

StringContactMap::StringContactMap () {
	root = NULL;
}

StringContactMap::~StringContactMap() {
	free_memory(root);
}

int StringContactMap::size() const {
    // TODO: Implement
	return 0;
}

bool StringContactMap::empty() const {
	return root == NULL;
}

vector<Contact> StringContactMap::all_contacts() const {
    // TODO: Implement (inorder traversal could come in handy here).
    return vector<Contact>();
}

void StringContactMap::add(string key, Contact value) {
    // TODO: Implement
}

void StringContactMap::remove(string key) {
    // TODO: Implement
}

bool StringContactMap::contains(string key) const {
    // TODO: Implement
	return false;
}

Contact StringContactMap::get(string key) const {
    // TODO: Implement
	return Contact();
}

vector<Contact> StringContactMap::prefix_search(string prefix) const {
    // TODO: Implement
    // NOTE: This is for part C of the assignment.
	return vector<Contact>();
}

void StringContactMap::free_memory(NodePtr node) {
    // TODO: Implement
}

void StringContactMap::prefix_search(NodePtr node, string prefix, vector<Contact>& v) const {
    // Optional helper function.
    // NOTE: This is for part C of the assignment.
}

ostream& operator <<(ostream& out, const StringContactMap& map) {
	vector<Contact> contacts = map.all_contacts();

	for(size_t i = 0; i < contacts.size(); i++) {
		out << contacts[i] << endl;
	}
	return out;
}

