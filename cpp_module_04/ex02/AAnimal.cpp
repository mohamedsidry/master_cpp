/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:42:15 by msidry            #+#    #+#             */
/*   Updated: 2026/02/02 19:05:47 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

/**
 * @brief AAnimal Default constructor .
*/
AAnimal::AAnimal():
type("Unknown")
{
    std::cout << "AAnimal default constructor was called !" << std::endl;
}


/**
 * @brief AAnimal Copy constructor .
 * @param [in] other obj to copy from .
*/
AAnimal::AAnimal(const AAnimal& other):
type(other.type)
{
    std::cout << "AAnimal copy constructor was called !" << std::endl;
}

/**
 * @brief operator= Copy Assign constructor .
 * @param [in] other obj to copy from .
 * @return new updated object .
*/
AAnimal& AAnimal::operator=(const AAnimal& other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "AAnimal copy assign constructor was called !" << std::endl;
    return (*this);
}

/**
 * @brief AAnimal Constructor with type as param .
 * @param [in] type Type of AAnimal .
*/
AAnimal::AAnimal(const std::string& type):
type(type)
{
    std::cout << "AAnimal onstructor was called !"  << std::endl;
}

/**
 * @brief ~AAnimal Destructor .
*/
AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor was called !" << std::endl;
}


/**
 * @brief makeSound display a message to user.
*/
void AAnimal::makeSound(void) const
{
    std::cout << "Oops * "
            << this->type
            << " * did make sound !"
            << std::endl;
}



/**
 * @brief getType get type of AAnimal .
*/
std::string const& AAnimal::getType(void) const {return this->type;}
