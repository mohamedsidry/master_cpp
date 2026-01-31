/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookApp.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 08:50:51 by msidry            #+#    #+#             */
/*   Updated: 2025/10/19 08:50:52 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookApp.hpp"

t_textAlign PhoneBookApp::textAlign = RIGHT;
bool PhoneBookApp::interapted = false;

PhoneBookApp::PhoneBookApp(PhoneBook& phoneBook):
phoneBook(phoneBook)
{}

PhoneBookApp::PhoneBookApp():
phoneBook()
{}

void    PhoneBookApp::startApp(void)
{
    std::string command;

    while(true)
    {
        if (PhoneBookApp::interapted)
        {
            PhoneBookApp::interapted = false;
            break;
        }
        std::cout << "Enter command {SEARCH, ADD, EXIT} : ";
        if(!std::getline(std::cin, command))
        {
            std:: cerr << "\nEOF detected. Exiting ..." << std::endl;
            break ;
        }
        if (command == "ADD")
            addContactHandler();
        else if (command == "SEARCH")
            searchContactHandler();
        else if (command == "EXIT")
            break;
    }
}


void    PhoneBookApp::addContactHandler(void)
{
    Contact contact;
    std::string input;
    int idx;
    idx = 0;
    const std::string titles[] = {"First Name", "Last Name", "Nick Name", "Phone Number", "Darkest Secret"};
    typedef void (Contact::*setter)(const std::string&);
    setter callbacks[] = {&Contact::setFirstName, &Contact::setLastName, &Contact::setNickName, &Contact::setPhoneNumber, &Contact::setDarkestSecret};  
    
    while (idx < 5)
    {
        if(inputHandler(titles[idx], contact, callbacks[idx]))
        {
            PhoneBookApp::interapted = true;
            return;
        }
        idx++;
    }
    if (Validator::validContact(contact))
        phoneBook.addContact(contact);
}

int PhoneBookApp::inputHandler(const std::string& prompt, Contact& contact ,void (Contact::*setter)(const std::string&))
{
    std::string input;
    std::cout << prompt + " : ";
    if (!std::getline(std::cin, input))
    {
        std::cout << "\nAdd contact cancelled, Exiting ..." << std::endl;
        std:: cin.clear();
        return (1);
    }
    (contact.*setter)(input);
    return (0);
}



void    PhoneBookApp::searchContactHandler(void) const
{
    std::string index;
    contactsInfo();

    if (phoneBook.getContactsCount())
    {
        std::cout << "Select Contact index : ";
        if (!std::getline(std::cin, index))
        {
            std::cout << "\nSearch contact cancelled, Exiting ..." << std::endl;
            std:: cin.clear();
            PhoneBookApp::interapted = true;
            return ;
        }
        if (Validator::validIndex(index))
            contactDetails(Formatter::toInt(index));
        else
            std::cerr << "Invalid Index : " + index << std:: endl;
    }

}

void    PhoneBookApp::contactsInfo(void) const
{
    contactsInfoHeader();
    contactsInfoBody();
}



void    PhoneBookApp::contactDetails(int index) const
{
    int max_width;
    int longest;
    Contact target;

    if (index < 0 || index >= phoneBook.getContactsCount())
    {
        std::cerr << "index " << index << " : is out of range !" << std::endl;
        return ;
    }
    target = phoneBook.getContactByIndex(index);
    longest = max_length();
    longest = longest > MAX_LINE ? MAX_LINE : longest;
    max_width = 14;
    std::cout << std::string(max_width + longest + 3, '~') << std::endl;
    std::cout << "|";
    std::cout << Formatter::formatField("FIRST NAME", 14, textAlign);
    std::cout << "|";
    std::cout << Formatter::formatField(target.getFirstName(), longest, textAlign) <<  "|" << std::endl;
    std::cout << std::string(max_width + longest + 3, '~') << std::endl;
    std::cout << "|";
    std::cout << Formatter::formatField("LAST NAME", 14, textAlign);
    std::cout << "|";
    std::cout<< Formatter::formatField(target.getLastName(), longest, textAlign) <<  "|" << std::endl;
    std::cout << std::string(max_width + longest + 3, '~') << std::endl;
    std::cout << "|";
    std::cout << Formatter::formatField("NICK NAME", 14, textAlign);
    std::cout << "|";
    std::cout << Formatter::formatField(target.getNickName(), longest, textAlign) <<  "|" << std::endl;
    std::cout << std::string(max_width + longest + 3, '~') << std::endl;
    std::cout << "|";
    std::cout << Formatter::formatField("PHONE NUMBER", 14, textAlign);
    std::cout << "|";
    std::cout << Formatter::formatField(target.getPhoneNumber(), longest, textAlign) <<  "|" << std::endl;
    std::cout << std::string(max_width + longest + 3, '~') << std::endl;
    std::cout << "|";
    std::cout << Formatter::formatField("DARKEST SECRET", 14, textAlign);
    std::cout << "|";
    std::cout << Formatter::formatField(target.getDarkestSecret(), longest, textAlign) <<  "|" << std::endl;
    std::cout << std::string(max_width + longest + 3, '~') << std::endl;
}


int     PhoneBookApp::max_length(void)const
{
    int idx;
    int count;
    unsigned long max;
    Contact current;

    idx = 0;
    max = 0;
    count = phoneBook.getContactsCount();
    while (idx < count)
    {
        current = phoneBook.getContactByIndex(idx);
        if (current.getFirstName().length() > max)
            max = current.getFirstName().length();
        if (current.getLastName().length() > max)
            max =  current.getLastName().length();
        if (current.getNickName().length() > max)
            max = current.getNickName().length();
        if (current.getPhoneNumber().length() > max)
            max = current.getPhoneNumber().length();
        if (current.getDarkestSecret().length() > max)
            max = current.getDarkestSecret().length();
        idx++;
    }
    return (max);
}




void    PhoneBookApp::contactsInfoHeader(void) const
{
    std::cout << std::string(45, '~') << std::endl;
    std::cout << "|";
    std::cout << Formatter::formatField("INDEX", 10, textAlign);
    std::cout << "|";
    std::cout << Formatter::formatField("FIRST NAME", 10, textAlign);
    std::cout << "|";
    std::cout << Formatter::formatField("LAST NAME", 10, textAlign);
    std::cout << "|";
    std::cout << Formatter::formatField("NICK NAME", 10, textAlign);
    std::cout << "|" << std::endl;
    std::cout << std::string(45, '~') << std::endl;
}


void PhoneBookApp::contactsInfoBody(void) const
{
    int contactsCount;
    int index;
    Contact current;

    index = 0;
    contactsCount = phoneBook.getContactsCount();
    if (contactsCount == 0)
    {
        std::cout << "|";
        std::cout << Formatter::formatField("Empty Contacts List !", 43, CENTER);
        std::cout << "|" << std::endl;
        std::cout << std::string(45, '~') << std::endl;
        return ;
    }
    while (index < contactsCount)
    { 
        std::string strindex = Formatter::toString(index);
        current = phoneBook.getContactByIndex(index);
        std::cout << "|";
        std::cout << Formatter::formatField(strindex, MAX_COL, textAlign);
        std::cout << "|";
        std::cout << Formatter::formatField(current.getFirstName(), MAX_COL, textAlign);
        std::cout << "|";
        std::cout << Formatter::formatField(current.getLastName(), MAX_COL, textAlign);
        std::cout << "|";
        std::cout << Formatter::formatField(current.getNickName(), MAX_COL, textAlign);
        std::cout << "|" << std::endl;
        std::cout << std::string(45, '~') << std::endl;
        index++;
    }
}
