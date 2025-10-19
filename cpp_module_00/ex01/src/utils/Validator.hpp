#ifndef _VALIDATOR_HPP

#include "../../includes/main.hpp"
#include "../models/contact/Contact.hpp"

class Validator
{
    public:
        static bool validTextField(const std::string& input);
        static bool validNumberField(const std:: string& input);
        static bool validIndex(const std::string& input);
        static bool validContact(const Contact& contact);
};

#define _VALIDATOR_HPP
#endif // _VALIDATOR_HPP
