#include "StringContactMap.h"

using namespace std;

// tree_size and root initialized as NULL and 0
StringContactMap::StringContactMap () {
	root = NULL;
	tree_size = 0;
}

// Free memory called to delete nodes in tree
// tree_size shrinks to 0
StringContactMap::~StringContactMap() {
	free_memory(root);
	tree_size = 0;
}

// Size returns tree_size variable
int StringContactMap::size() const {
	return tree_size;
}

// If root is empty tree should subsequently be empty
bool StringContactMap::empty() const {
	return root == NULL;
}

// returns vector of contacts
vector<Contact> StringContactMap::all_contacts() const {
    vector<Contact> contacts;
    if(!empty()){
        inorder_to_vector(root, contacts);
    }

    return contacts;
}

// Pushes to contact vector in an inorder way
void StringContactMap::inorder_to_vector(NodePtr node, vector<Contact>& contacts) const
{
    if(node != NULL)
    {
       inorder_to_vector(node->left, contacts);
       contacts.push_back(node->value);
       inorder_to_vector(node->right, contacts);
    }
}

// Adds to tree, calls find function to obtain position
// Then inputs if key does not exist in tree
void StringContactMap::add(string key, Contact value) {
    NodePtr &cNode = find(root, key);
    if (cNode != NULL){
        cNode->value = value;
    }
    else
    {
        cNode = new ContactNode(key, value, NULL, NULL);
        tree_size++;
    }
}

// Calls node remove if key is found in tree
void StringContactMap::remove(string key) {

    NodePtr &node = find(root, key);
    if(node != NULL){
        removeNode(node);
    }
}

// Removes node from binary tree recursively
// Reorganizes tree if needed
void StringContactMap::removeNode(NodePtr &node)
{
    // If node has no right node, node becomes
    // right node, and original node is deleted
    if(node->left == NULL){
        NodePtr temp = node;
        node = node->right;
        delete temp;
        tree_size--;
    }
    // If node has no right node, node
    // becomes left node, and tree is deleted
    else if (node->right == NULL){
        NodePtr temp = node;
        node = node->left;
        delete temp;
        tree_size--;
    }
    // If tree node has two children, tree needs to be
    // reorganized accordingly
    else if(node->left != NULL && node->right != NULL)
    {
        NodePtr &temp = getLeftmost(node->right);
        NodePtr toDelete = temp;
        node->key = temp->key;
        node->value = temp->value;
        temp = temp->right;
        removeNode(toDelete);
    }
}

// Returns true if tree contains node with key
bool StringContactMap::contains(string key){

    return find(root, key) != NULL;
}

// Returns contact value if contact exists
Contact StringContactMap::get(string key) {
	NodePtr &node = find(root, key);
	if(node != NULL)
    {
        return node->value;
    }
	else
    {
        throw KeyException();
        return Contact();
	}
}

vector<Contact> StringContactMap::prefix_search(string prefix) const {
    // TODO: Implement
    // NOTE: This is for part C of the assignment.
	return vector<Contact>();
}

// Deletes entire tree recursively
void StringContactMap::free_memory(NodePtr node) {
    if (node == NULL){ return; }
    free_memory(node->left);
    free_memory(node->right);
    delete node;
}

void StringContactMap::prefix_search(NodePtr node, string prefix, vector<Contact>& v) const {
    // Optional helper function.
    // NOTE: This is for part C of the assignment.
}

// Finds a node in position that fits key
// Returns an existing node if key exists in tree
// Otherwise returns a NULL node at a position that is correct for key
NodePtr &StringContactMap::find(NodePtr &node, string key) const{
    if(node == NULL){
        return node;
    }
    if(node->key == key){
        return node;
    }
    else{
        if(key < node->key){
            return find(node->left, key);
        }
        else{
            return find(node->right, key);
        }
    }
}

// Helper function that returns leftmost node in tree
NodePtr &StringContactMap::getLeftmost(NodePtr &node)
{
    if(node->left == NULL){
        return node;
    }
    else
    {
        return getLeftmost(node->left);
    }
}

// Helper function that returns root node in tree
NodePtr StringContactMap::getRoot()
{
    return root;
}

// Returns node if found publicly
NodePtr &StringContactMap::isFound(string key)
{
    return find(root, key);
}

ostream& operator <<(ostream& out, const StringContactMap& map) {
	vector<Contact> contacts = map.all_contacts();

	for(size_t i = 0; i < contacts.size(); i++) {
		out << contacts[i] << endl;
	}
	return out;
}
