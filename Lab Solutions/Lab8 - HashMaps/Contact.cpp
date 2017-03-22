#include "Contact.h"

using namespace std;

istream& operator>> (istream& in, Contact& contact)
{
    getline(in, contact.name, ';');
    getline(in, contact.phone, ';');
    getline(in, contact.email, ';');
    getline(in, contact.address);
    return in;
}

ostream& operator<< (ostream& out, const Contact& contact)
{
    out << "Name:  " << contact.name << endl;
    out << "Phone: " << contact.phone << endl;
    out << "Email: " << contact.email << endl;
    out << "Addr:  " << contact.address << endl;
    return out;
}

ostream& operator<< (ostream& out, vector<Contact>& contacts)
{
    for(size_t i = 0; i < contacts.size(); i++) {
        out << contacts[i] << endl;
    }
    return out;
}

