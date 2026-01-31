/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:29:45 by msidry            #+#    #+#             */
/*   Updated: 2026/01/31 14:57:36 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Floor.hpp"


/**
 * @brief AMateria Default constructor .
*/
AMateria::AMateria():
type("Unknown")
{
    if (Floor::debugging())
        std::cout << "AMateria default constructor was called !" << std::endl;
}


/**
 * @brief AMateria constructor .
 * @param [in] type Type of materia .
*/
AMateria::AMateria(std::string const & type):
type(type)
{
    if (Floor::debugging())
        std::cout << "AMateria constructor was called !" << std::endl;
}

/**
 * @brief AMateria constructor .
 * @param [in] other obj to copy its type of materia from .
*/
AMateria::AMateria(const AMateria& other):
type(other.type)
{
    if (Floor::debugging())
        std::cout << "AMateria copy constructor was called !" << std::endl;
}

/**
 * @brief operator= copy and asign operator .
 * @param [in] other obj to copy from .
*/
AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
        this->type = other.type;
    if (Floor::debugging())
        std::cout << "AMateria copy assign constructor was called !" << std::endl;
    return *this;
}


AMateria::~AMateria()
{
    if (Floor::debugging())
        std::cout << "AMateria destuctor was called !" << std::endl;
}

/**
 * @brief getType Get type of materia .
 * @return ref to type of Amateria
*/
std::string const & AMateria::getType(void) const
{
    return this->type;
}


/**
 * @brief use used by derived object to interact with target .
*/
void AMateria::use(ICharacter& target)
{
    std::cout << "* uses an unknown materia on "
              << target.getName() << " *" << std::endl;
}
