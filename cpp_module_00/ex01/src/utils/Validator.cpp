#include "Validator.hpp"


bool Validator::validContact(const Contact& contact)
{
    if (!validTextField(contact.getFirstName()))
    {
        std::cout << "Invalid First Name : " + contact.getFirstName() << std::endl;
        return (false);
    }
    else if (!validTextField(contact.getLastName()))
    {
        std::cout << "Invalid Last Name  : "  + contact.getFirstName()  << std::endl;
        return (false);
    }   
    else if (!validTextField(contact.getNickName()))
    {
        std::cout << "Invalid Nick Name : "  + contact.getFirstName()  << std::endl;
        return (false);
    }
    else if (!validNumberField(contact.getPhoneNumber()))
    {
        std::cout << "Invalid Number : "  + contact.getPhoneNumber()  << std::endl;
        return (false);
    }
    else if (!validTextField(contact.getDarkestSecret()))
    {
        std::cout << "Invalid Secret : "  + contact.getFirstName()  << std::endl;
        return (false);
    }
    return (true);
}

bool Validator::validTextField(const std::string& input)
{
    int idx;

    idx = 0;
    if (input.length() == 0)
        return (false);
    while (isspace(input[idx]))
        idx++;
    if (!input[idx])
        return (false);
    return (true);
}

bool Validator::validNumberField(const std::string& input)
{
    int idx;

    idx = 0;
    if (input.length() == 0)
        return (false);
    if (input[idx] == '+')
        idx++;
    if (!input[idx] || !isdigit(input[idx]))
        return (false);
    while (isdigit(input[idx]))
        idx++;
    if (input[idx])
        return (false);
    return (true);
}

bool Validator::validIndex(const std::string& input)
{
    if (input.length() == 0)
        return (false);
    if (!isdigit(input[0]))
        return (false);
    return (Validator::validNumberField(input));
}
