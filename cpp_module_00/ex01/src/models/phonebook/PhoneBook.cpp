#include "PhoneBook.hpp"
#include "../../utils/Formatter.hpp"

PhoneBook::PhoneBook() :
contactsCount(0),
oldestIndex(0)
{}


/*METHODES*/

void    PhoneBook::addContact(const Contact& newContact)
{
    int idx;

    idx = getContactsCount();
    if (idx < MAX_CONTACTS)
    {
        contacts[idx] = newContact;
        setContactsCount(idx + 1);
    }else
    {
        idx = getOldestIndex() % MAX_CONTACTS;
        contacts[idx] = newContact;
        setOldestIndex(idx + 1);
    }
}


/* GETTERS */
int     PhoneBook::getContactsCount(void)const {return contactsCount;}
int     PhoneBook::getOldestIndex(void)const {return oldestIndex;}
Contact PhoneBook::getContactByIndex(int idx) const {return contacts[idx];}
/* SETTERS */
void    PhoneBook::setContactsCount(int value){contactsCount = value;}
void    PhoneBook::setOldestIndex(int value){oldestIndex = value;}
