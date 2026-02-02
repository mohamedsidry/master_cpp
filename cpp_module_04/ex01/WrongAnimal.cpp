/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:43:04 by msidry            #+#    #+#             */
/*   Updated: 2026/02/02 11:43:37 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>


/**
 * @brief WrongAnimal Default constructor .
*/
WrongAnimal::WrongAnimal():
type("Unknown")
{
    std::cout << "WrongAnimal default constructor was called !" << std::endl;
}


/**
 * @brief WrongAnimal Copy constructor .
 * @param [in] other obj to copy from .
*/
WrongAnimal::WrongAnimal(const WrongAnimal& other):
type(other.type)
{
    std::cout << "WrongAnimal copy constructor was called !" << std::endl;
}

/**
 * @brief operator= Copy Assign constructor .
 * @param [in] other obj to copy from .
 * @return new updated object .
*/
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "WrongAnimal copy assign constructor was called !" << std::endl;
    return (*this);
}

/**
 * @brief WrongAnimal Constructor with type as param .
 * @param [in] type Type of WrongAnimal .
*/
WrongAnimal::WrongAnimal(const std::string& type):
type(type)
{
    std::cout << "WrongAnimal onstructor was called !"  << std::endl;
}

/**
 * @brief ~WrongAnimal Destructor .
*/
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor was called !" << std::endl;
}


/**
 * @brief makeSound display a message to user.
*/
void WrongAnimal::makeSound(void) const
{
    std::cout << "Oops * "
            << this->type
            << " * did make sound !"
            << std::endl;
}



/**
 * @brief getType get type of WrongAnimal .
*/
std::string const& WrongAnimal::getType(void) const {return this->type;}
