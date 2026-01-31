#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "../../../includes/main.hpp"
#include "../../../includes/const.hpp"
#include "../contact/Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[MAX_CONTACTS];
        int contactsCount;
        int oldestIndex;
    public:
        PhoneBook();
        void    addContact(const Contact& newContact);
        void    setContactsCount(int value);
        int     getContactsCount(void)const;
        void    setOldestIndex(int idx);
        int     getOldestIndex(void) const;
        Contact getContactByIndex(int idx) const;
};



#endif //PHONEBOOK_HPP
