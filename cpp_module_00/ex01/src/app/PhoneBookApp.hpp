/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookApp.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 08:50:54 by msidry            #+#    #+#             */
/*   Updated: 2025/10/19 08:50:55 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOKAPP_HPP
# define PHONEBOOKAPP_HPP
# include "../../includes/main.hpp"
# include "../models/contact/Contact.hpp"
# include "../models/phonebook/PhoneBook.hpp"
# include "../utils/Formatter.hpp"
# include "../utils/Validator.hpp"


class PhoneBookApp
{
    private:
    PhoneBook           phoneBook;
    int     max_length(void)const;
    static  t_textAlign textAlign;
    static bool         interapted;
    
    public:
    PhoneBookApp();
    PhoneBookApp(PhoneBook& phoneBook);
    void    addContactHandler(void);
    void    searchContactHandler(void) const;
    void    startApp(void);
    void    contactsInfo(void) const;
    void    contactsInfoHeader(void) const;
    void    contactsInfoBody(void) const;
    void    contactDetails(int idx) const;
    int     inputHandler(const std::string& prompt, Contact& contact ,void (Contact::*setter)(const std::string&));

};

#endif // PHONEBOOKAPP_HPP
