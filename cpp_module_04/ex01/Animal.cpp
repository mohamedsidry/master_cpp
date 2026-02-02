/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:42:15 by msidry            #+#    #+#             */
/*   Updated: 2026/02/02 11:32:12 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

/**
 * @brief Animal Default constructor .
*/
Animal::Animal():
type("Unknown")
{
    std::cout << "Animal default constructor was called !" << std::endl;
}


/**
 * @brief Animal Copy constructor .
 * @param [in] other obj to copy from .
*/
Animal::Animal(const Animal& other):
type(other.type)
{
    std::cout << "Animal copy constructor was called !" << std::endl;
}

/**
 * @brief operator= Copy Assign constructor .
 * @param [in] other obj to copy from .
 * @return new updated object .
*/
Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "Animal copy assign constructor was called !" << std::endl;
    return (*this);
}

/**
 * @brief Animal Constructor with type as param .
 * @param [in] type Type of Animal .
*/
Animal::Animal(const std::string& type):
type(type)
{
    std::cout << "Animal onstructor was called !"  << std::endl;
}

/**
 * @brief ~Animal Destructor .
*/
Animal::~Animal()
{
    std::cout << "Animal destructor was called !" << std::endl;
}


/**
 * @brief makeSound display a message to user.
*/
void Animal::makeSound(void) const
{
    std::cout << "Oops * "
            << this->type
            << " * did make sound !"
            << std::endl;
}



/**
 * @brief getType get type of animal .
*/
std::string const& Animal::getType(void) const {return this->type;}
