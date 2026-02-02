/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:30:29 by msidry            #+#    #+#             */
/*   Updated: 2026/01/31 15:00:51 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"


/**
 * @brief Ice Default constructor .
*/
Ice::Ice():
AMateria("ice")
{
    if (Floor::debugging())
        std::cout << "Ice default constructor was called !" << std::endl; 
}

/**
 * @brief Ice Copy constructor .
 * @param [in] other Obj to copy from it .
*/
Ice::Ice(const Ice& other):
AMateria(other)
{
    if (Floor::debugging())
        std::cout << "Ice Copy constructor was called !" << std::endl;
}


/**
 * @brief operator= Copy assig operator .
 * @param [in] other Object to copy from .
 * @return just return same object .
*/
Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    if (Floor::debugging())
        std::cout << "Ice Copy assign constructor was called !" << std::endl;
    return *this;
}


/**
 * @brief Ice Destructor .
*/
Ice::~Ice()
{
    if (Floor::debugging())
        std::cout << "Ice Destructor was called !" << std::endl;
}

/**
 * @brief clone Clones the Ice object .
 * @return new allocated object .
*/
AMateria* Ice::clone(void) const
{
    return new Ice(*this);
}


/**
 * @brief use display message that target was shot by ice bolt .
 * @param [in] target Ref to the character that was shooted .
*/

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at "
              << target.getName()
              << " *" << std::endl;
}
