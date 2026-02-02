/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:12:02 by msidry            #+#    #+#             */
/*   Updated: 2026/02/02 11:24:50 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>



/**
 * @brief Dog Default constructor .
*/
Dog::Dog():
Animal("dog")
{
    std::cout << "Dog default constructor was called !" << std::endl;
}


/**
 * @brief Dog Copy constructor .
 * @param [in] other Obj to copy from .
*/
Dog::Dog(const Dog& other):
Animal(other)
{
    std::cout << "Dog copy constructor was called !" << std::endl;
}


/**
 * @brief operator= Assign operator .
 * @param [in] other Obj to copy from .
 * @return Updated obj.
*/
Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        Animal::operator=(other);

    std::cout << "Dog copy assign constructor was called !" << std::endl;
    return (*this);
}

/**
 * @brief Dog Decstructor . 
*/
Dog::~Dog()
{
   std::cout << "Dog destructor was called !" << std::endl; 
}


/**
 * @brief makeSound Display dog sound to std output  .
*/
void Dog::makeSound(void) const
{
    std:: cout << "Huff Huff Huff" << std::endl;
}

