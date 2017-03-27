#include "StringContactMap.h"

using namespace std;

StringContactMap::StringContactMap () {
	root = NULL;
}

StringContactMap::~StringContactMap() {
	free_memory(root);
}
/*Please note each function that is called recursively
 does so through helper functions that handle the pointers
 not allowing the user to interfere with them in any way.
 
 Also note that this code was in some part based on
 code found on the courses github page.*/
int StringContactMap::size() const {
	return size(root);
}
/*A size funtion that recursively counts the size of the tree.
 It first counts the number of nodes in the left subtree and 
 returns only when a node is NULL or it has counted both 
 subtrees of said node. When finished with the left subtree
 the right subtree is counted and when finished the root of the
 tree is counted as well and the function returns the size of the 
 tree.*/
int StringContactMap::size(NodePtr node) const{
    if(node == NULL){
        return 0;
    }
    return 1 + size(node->left) + size(node->right);
}

bool StringContactMap::empty() const {
	return root == NULL;
}

vector<Contact> StringContactMap::all_contacts() const {
    
    return all_contacts(root);
}
/*This function is a recursive function that returns a vector with
 all of the Contact values in inorder. First if a node is NULL the function
 returns an empty vector. If the node is not empty the function 
 goes to the lower left hans side of the tree where the lowest valued string. 
 When that value is found it is pushed into the vector and the right hand side
 of that node is called recursively and pushed into a new vector. After that 
 the right vector is concatenated with the left vector and that vector is returned.
 If any node has no children the function returns two empty vectors and the value
 of the leaf is pushed into the vector.*/
vector<Contact> StringContactMap::all_contacts(NodePtr node) const{
    if (node == NULL) {
        return vector<Contact>();
    }
    vector<Contact> left = all_contacts(node->left);
    left.push_back(node->value);
    vector<Contact> right = all_contacts(node->right);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

void StringContactMap::add(string key, Contact value) {

    add(root, key, value);
}
/*This function calls the find function and if the find function returns a
 NULL pointer a new node is created and that pointer given that node. 
 If a normal node is returned from find the value of said node is overwritten.*/
void StringContactMap::add(NodePtr& r, string key, Contact value){

    NodePtr& new_node = find(r, key);
    if (new_node == NULL) {
        new_node = new ContactNode(key, value);
    }else{
        new_node->value = value;
    }
}

void StringContactMap::remove(string key) {
    remove(root, key);
}
/*
 If the node to be deleted is not found then the function finds a 
 NULL node and returns without deleting anything, else the function
 finds the correct node to delete. 
 The deletion can happen in three ways, if the node has only a right child
 then the node pointer points to the right child of the node to be
 deleted and vice versa. If the tree has two children minContact is called
 which returns a pointer to a node in the right subtree with the smallest value.
 The node to be deleted is overwritten with the values from the small node and 
 the small node deleted instead.*/
void StringContactMap::remove(NodePtr& node, string key){
    if(node == NULL) {
        return;
    } else if(key < node->key) {
        remove(node->left, key);
    } else if(key > node->key) {
        remove(node->right, key);
    } else {
        NodePtr to_del = node;
        if(node->left == NULL) {
            node = node->right;
        } else if (node->right == NULL) {
            node = node->left;
        } else {
            
            NodePtr& contact = minContact(node->right);

            to_del = contact;
            
            node->key = contact->key;
            node->value = contact->value;
            contact = contact->right;
        }
        delete to_del;
    }
}

/*This function finds the smallest value in the right subtree
 and returns a pointer to it.*/
NodePtr& StringContactMap::minContact(NodePtr& node){
    if (node == NULL) {
        return node;
    }
    if (node->left == NULL) {
        return node;
    }
    return minContact(node->left);
    
}

bool StringContactMap::contains(string key) const {
    return contains(root, key);
}
/*Function calls the find function which in turn returns the node(if any)
 that corrisponds with requested key and returns a bool value based on if
 value was found or not.*/
bool StringContactMap::contains(NodePtr node, string key) const{
    return find(node, key) != NULL;
}
//Helper function used by add, get and contains to easily access a node with requested key.
NodePtr& StringContactMap::find(NodePtr& node, string key) const{
    if (node == NULL) {
        return node;
    }else if(key < node->key){
        return find(node->left, key);
    }else if(key > node->key){
        return find(node->right, key);
    }else{
        return node;
    }
}
Contact StringContactMap::get(string key) const {
	return get(root, key);
}
/*Function returns the Contact value that corrisponds to the key parameter.
 If the value is not found and the function encounters a NULL node the 
 function throws a KeyException. */
Contact StringContactMap::get(NodePtr node, string key) const{
    NodePtr new_node = find(node, key);
    if (new_node == NULL) {
        throw KeyException();
    }else{
        return new_node->value;
    }
}

vector<Contact> StringContactMap::prefix_search(string prefix) const {
    vector<Contact> contact;
    prefix_search(root, prefix, contact);
	return contact;
}
/*This function removes each node from the heap recursively and
 first going down the left subtree and then the right. After a 
 node is deleted the pointer to that node is NULLED.*/
void StringContactMap::free_memory(NodePtr node) {
    
    if (node != NULL) {
        free_memory(node->left);
        free_memory(node->right);
        delete node;
    }
    root = NULL;
    
}
/*If the values of the first char of the prefix match that of the node->key
 a check if they are the same is initiated. If they are not the same the function "goes left"
 and then right. If however the values match then the value is pushed into a vector.*/
void StringContactMap::prefix_search(NodePtr node, string prefix, vector<Contact>& v) const {
    if (node == NULL) {
        return;
    }else if(prefix[0] == node->key[0]){
        bool check = true;
        for (unsigned int i = 0; i < prefix.length(); i++) {
            if (prefix[i] != node->key[i]) {
                check = false;
                break;
            }
        }if (node->left != NULL) {
            prefix_search(node->left, prefix, v);
        }
        if (check) {
            v.push_back(node->value);
        }
        if(node->right != NULL){
            prefix_search(node->right, prefix, v);
        }
    }else if (prefix[0] < node->key[0]){
        prefix_search(node->left, prefix, v);
    }else if (prefix[0] > node->key[0]){
        prefix_search(node->right, prefix, v);
    }
}

ostream& operator <<(ostream& out, const StringContactMap& map) {
	vector<Contact> contacts = map.all_contacts();

	for(size_t i = 0; i < contacts.size(); i++) {
		out << contacts[i] << endl;
	}
	return out;
}

