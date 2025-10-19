/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 08:50:59 by msidry            #+#    #+#             */
/*   Updated: 2025/10/19 08:51:00 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructor implementation

Contact::Contact():
firstName(""),
lastName(""),
nickName(""),
phoneNumber(""),
darkestSecret(""){}


Contact::Contact(
    const std::string& firstName,
    const std::string& lastName,
    const std::string& nickName,
    const std::string& phoneNumber,
    const std::string& darkestSecret):
    firstName(firstName),
    lastName(lastName),
    nickName(nickName),
    phoneNumber(phoneNumber),
    darkestSecret(darkestSecret){}



// GETTERS 
std::string Contact::getFirstName(void) const {return firstName;}
std::string Contact::getLastName(void) const {return lastName;}
std::string Contact::getNickName(void) const {return nickName;}
std::string Contact::getPhoneNumber(void) const {return phoneNumber;}
std::string Contact::getDarkestSecret(void)const {return darkestSecret;}

// SETTERS
void Contact::setFirstName(const std::string& value){firstName = value;}
void Contact::setLastName(const std::string& value){lastName = value;}
void Contact::setNickName(const std::string& value){nickName = value;}
void Contact::setPhoneNumber(const std::string& value){phoneNumber = value;}
void Contact::setDarkestSecret(const std::string& value){darkestSecret = value;}




