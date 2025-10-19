/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 08:51:40 by msidry            #+#    #+#             */
/*   Updated: 2025/10/19 08:51:41 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "test.hpp"
# include "../includes/main.hpp"
# include "../src/app/PhoneBookApp.hpp"

int main(void)
{
    
    PhoneBook phonebook;
    phonebook.addContact(Contact("user1", "lastname1", "nickname1", "+2126226262", "This is my secret 1312111111111111111111111111111111111"));
    phonebook.addContact(Contact("user2", "lastname2", "nickname2", "+2126226262", "This is my secret 13122222222222222222222222222222222"));
    phonebook.addContact(Contact("user3", "lastname3", "nickname3", "+2126226262", "This is my secret 131233333333333"));
    phonebook.addContact(Contact("user4", "lastname4", "nickname4", "+2126226262", "This is my secret 13124444"));
    phonebook.addContact(Contact("user5", "lastname5", "nickname5", "+2126226262", "This is my secret 13125"));
    phonebook.addContact(Contact("user6", "lastname6", "nickname6", "+2126226262", "This is my secret 13126666"));
    phonebook.addContact(Contact("user7", "lastname7", "nickname7", "+2126226262", "This is my secret 131277777777777"));
    phonebook.addContact(Contact("user8", "lastname8", "nickname8", "+2126226262", "This is my secret 13128888888888888888888888888888888"));
    phonebook.addContact(Contact("user9", "lastname9", "nickname9", "+2126226262", "This is my secret 1312999999999999999999999999999999999"));
    phonebook.addContact(Contact("user10", "lastname10", "nickname10", "+2126226262", "This is my secret 13120000000000000000000000000000000000000"));
    PhoneBookApp app(phonebook);
    app.startApp();
    
    return (0);
}
