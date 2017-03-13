#include "ContactManager.h"

void ContactManager::add(Contact contact) {
	if(name_exists(contact.name)){ throw DuplicateNameException(); }
    if(phone_exists(contact.phone)){ throw DuplicatePhoneException(); }
    name_map.add(contact.name, contact);
	phone_map.add(contact.phone, contact);
}

void ContactManager::remove(string name) {
	if(name_map.contains(name)){
        string phonenr = (name_map.isFound(name)->value).phone;
        name_map.remove(name);
        phone_map.remove(phonenr);
    }
}

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

bool ContactManager::name_exists(string name) {
    return name_map.isFound(name);
}

bool ContactManager::phone_exists(string phone) {
	return phone_map.isFound(phone);
}

Contact ContactManager::get_contact_by_name(string name) {
	return (name_map.isFound(name))->value;
}

Contact ContactManager::get_contact_by_phone(string phone) {
	return (phone_map.isFound(phone))->value;
}

vector<Contact> ContactManager::get_contacts_by_name_prefix(string name_prefix) {
    vector<Contact> vec = name_map.prefix_search(name_prefix);

	return vec;
}

vector<Contact> ContactManager::get_contacts_by_phone_prefix(string phone_prefix) {
    vector<Contact> vec = phone_map.prefix_search(phone_prefix);

	return vec;
}

ostream& operator<< (ostream& out, ContactManager& manager) {
	out << manager.name_map << endl << endl;
	out << manager.phone_map;
	return out;
}
