/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:59:44 by msidry            #+#    #+#             */
/*   Updated: 2026/01/31 14:58:04 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cure.hpp"

/**
 * @brief Cure Default constructor .
*/
Cure::Cure():
AMateria("cure")
{
    if (Floor::debugging())
        std::cout << "Cure default constructor was called !" << std::endl; 
}

/**
 * @brief Cure Copy constructor .
 * @param [in] other Obj to copy from it .
*/
Cure::Cure(const Cure& other):
AMateria(other)
{
    if (Floor::debugging())
        std::cout << "Cure Copy constructor was called !" << std::endl;
}


/**
 * @brief operator= Copy assig operator .
 * @param [in] other Object to copy from .
 * @return just return same object .
*/
Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    if (Floor::debugging())
        std::cout << "Cure Copy assign constructor was called !" << std::endl;
    return *this;
}


/**
 * @brief Cure Destructor .
*/
Cure::~Cure()
{
    if (Floor::debugging())
        std::cout << "Cure Destructor was called !" << std::endl;
}

/**
 * @brief clone Clones the Cure object .
 * @return new allocated object .
*/
AMateria* Cure::clone(void) const
{
    return new Cure(*this);
}


/**
 * @brief use displays a healing message on target.
 * @param [in] target Ref to the character to be healed .
*/
void Cure::use(ICharacter& target)
{
    std::cout << "* heals " 
              << target.getName()
              << " ’s wounds *" << std::endl;
}
