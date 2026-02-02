/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:12:02 by msidry            #+#    #+#             */
/*   Updated: 2026/02/02 18:40:12 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>



/**
 * @brief Dog Default constructor .
*/
Dog::Dog():
Animal("dog"),
brain(new Brain("i have no idea"))
{        
    std::cout << "Dog default constructor was called !" << std::endl;
}


/**
 * @brief Dog Copy constructor .
 * @param [in] other Obj to copy from .
*/
Dog::Dog(const Dog& other):
Animal(other),
brain(new Brain(*other.brain))
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
    {
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    std::cout << "Dog copy assign constructor was called !" << std::endl;
    return (*this);
}

/**
 * @brief Dog Decstructor . 
*/
Dog::~Dog()
{
    delete this->brain;
   std::cout << "Dog destructor was called !" << std::endl; 
}


/**
 * @brief makeSound Display dog sound to std output  .
*/
void Dog::makeSound(void) const
{
    std:: cout << "Huff Huff Huff" << std::endl;
}


/**
 * @brief showXIdeas display x ideas of dog .
 * @param [in] x number of ideas to display .
*/
void Dog::showXIdeas(unsigned int x) const
{
    if (x > 100)
        return;
    std::cout << "Dog ideas : ";
    for (unsigned int i = 0; i < x; i++)
        std::cout << "'" << this->brain->getIdeaByIndex(i) << "' , ";
    std::cout << std::endl;
}


/**
 * @brief getBrain get dog brain reff .
 * @return ref to cat brain .
*/
Brain& Dog::getBrain(void) const
{
    return *this->brain;
}
