#include "ContactManager.h"

// Adds contact if name or phone are not duplicates
// Otherwise an exception is thrown
void ContactManager::add(Contact contact) {
	if(name_exists(contact.name)){ throw DuplicateNameException(); }
    if(phone_exists(contact.phone)){ throw DuplicatePhoneException(); }
    name_map.add(contact.name, contact);
	phone_map.add(contact.phone, contact);
}

// Removes contact from both phone_map and name_map by name
// No action if name is not found in list
void ContactManager::remove(string name) {
	if(name_map.contains(name)){
        string phonenr = (name_map.isFound(name)->value).phone;
        name_map.remove(name);
        phone_map.remove(phonenr);
    }
}

// Phone number updated by name in both phone_map and name_map
// Key changed in phone_map, so needs to be removed from the map, then added again
// with other values unchanged
// if name not found an exception is thrown
void ContactManager::update_phone(string name, string new_number) {
    if(name_exists(name)){
        Contact cvalue = name_map.isFound(name)->value;
        string old_number = cvalue.phone;
        cvalue.phone = new_number;
        name_map.add(name, cvalue);
        phone_map.remove(old_number);
        phone_map.add(new_number, cvalue);
    }
    else{
        throw ContactMissingException();
    }
}

// Email updated in both maps, no key change needed
// Exception thrown if name matches no contact
void ContactManager::update_email(string name, string new_email) {
    if(name_exists(name)){
        Contact cvalue = name_map.isFound(name)->value;
        cvalue.email = new_email;
        string phone_number = cvalue.phone;
        name_map.add(name, cvalue);
        phone_map.add(phone_number, cvalue);
    }
    else{
        throw ContactMissingException();
    }
}

// Returns true if name exists in map
bool ContactManager::name_exists(string name) {
    return name_map.isFound(name);
}

// Returns true if phone number exists in map
bool ContactManager::phone_exists(string phone) {
	return phone_map.isFound(phone);
}

// Gets contact by name and returns it's contact value
Contact ContactManager::get_contact_by_name(string name) {
	return (name_map.isFound(name))->value;
}

// Gets contact by phone and returns it's contact value
Contact ContactManager::get_contact_by_phone(string phone) {
	return (phone_map.isFound(phone))->value;
}

// returns vector of contacts that corresponds to given prefix of a name
// vector obtained via a prefix search function in contact map
vector<Contact> ContactManager::get_contacts_by_name_prefix(string name_prefix) {
    vector<Contact> vec = name_map.prefix_search(name_prefix);

	return vec;
}

// returns vector of contacts that corresponds to given prefix of a number
// vector obtained via prefix search function in contact map
vector<Contact> ContactManager::get_contacts_by_phone_prefix(string phone_prefix) {
    vector<Contact> vec = phone_map.prefix_search(phone_prefix);

	return vec;
}

ostream& operator<< (ostream& out, ContactManager& manager) {
	out << manager.name_map << endl << endl;
	out << manager.phone_map;
	return out;
}
