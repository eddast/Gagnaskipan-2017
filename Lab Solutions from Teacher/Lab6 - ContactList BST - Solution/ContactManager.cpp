#include "ContactManager.h"

void ContactManager::add(Contact contact) {
    if(name_exists(contact.name)){
        throw DuplicateNameException();
    }else if (phone_map.contains(contact.phone)) {
        throw DuplicatePhoneException();
    }else{
        name_map.add(contact.name, contact);
        phone_map.add(contact.phone, contact);
    }
}

void ContactManager::remove(string name) {
    if (name_map.contains(name)) {
        Contact con = get_contact_by_name(name);
        phone_map.remove(con.phone);
        name_map.remove(name);
    }
}

void ContactManager::update_phone(string name, string new_number) {

        Contact contact = get_contact_by_name(name);
        //name_map.remove(name);
        phone_map.remove(contact.phone);
        contact.phone = new_number;
        //remove(name);
        name_map.add(contact.name, contact);
        phone_map.add(contact.phone, contact);
    
}

void ContactManager::update_email(string name, string new_email) {

        Contact contact = get_contact_by_name(name);
        contact.email = new_email;
        name_map.add(contact.name, contact);
        phone_map.add(contact.phone, contact);
    
}

bool ContactManager::name_exists(string name) {
	return name_map.contains(name);
}

bool ContactManager::phone_exists(string phone) {
	return phone_map.contains(phone);
}

Contact ContactManager::get_contact_by_name(string name) {
    if (!name_map.contains(name)) {
        throw ContactMissingException();
    }
    return name_map.get(name);
}

Contact ContactManager::get_contact_by_phone(string phone) {
    if (!phone_map.contains(phone)) {
        throw ContactMissingException();
    }
	return phone_map.get(phone);
}

vector<Contact> ContactManager::get_contacts_by_name_prefix(string name_prefix) {
   
	return name_map.prefix_search(name_prefix);
}

vector<Contact> ContactManager::get_contacts_by_phone_prefix(string phone_prefix) {
    
	return phone_map.prefix_search(phone_prefix);
}

ostream& operator<< (ostream& out, ContactManager& manager) {
	out << manager.name_map << endl << endl;
	out << manager.phone_map;
	return out;
}
