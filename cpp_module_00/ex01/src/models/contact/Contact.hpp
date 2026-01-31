/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 08:51:02 by msidry            #+#    #+#             */
/*   Updated: 2025/10/19 08:51:03 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "../../../includes/main.hpp"

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
        Contact();
        Contact(
            const std::string& firstName,
            const std::string& lastName,
            const std::string& nickName,
            const std::string& phoneNumber,
            const std::string& darkestSecret);
        
        /*GETTERS*/
        std::string getFirstName(void) const;
        std::string getLastName(void) const;
        std::string getNickName(void) const;
        std::string getPhoneNumber(void) const;
        std::string getDarkestSecret(void) const;

        /*SETTERS*/
        void setFirstName(const std::string& value);
        void setLastName(const std::string& value);
        void setNickName(const std::string& value);
        void setPhoneNumber(const std::string& value);
        void setDarkestSecret(const std::string& value);
};



#endif // CONTACT_HPP
