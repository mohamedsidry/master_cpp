/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:59:03 by msidry            #+#    #+#             */
/*   Updated: 2026/02/02 18:36:45 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include "Brain.hpp"

/**
 * @brief Cat Default constructor .
*/
Cat::Cat():
Animal("cat"),
brain(new Brain("i have no idea"))
{
    std::cout << "Cat default constructor was called !  " << std::endl;
}


/**
 * @brief Cat copy constructor .
 * @param [in] other Obj to copy from .
*/
Cat::Cat(const Cat& other):
Animal(other),
brain(new Brain(*other.brain))
{
    std::cout << "Cat copy constructor was called !  " << std::endl;
}


/**
 * @brief operator= Copy assign operator .
 * @param [in] other Obj to copy from .
 * @return Updated obj.
*/
Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete this->brain;
        this->brain = other.brain;
    }
    std::cout << "Cat copy assign constructor was called !" << std::endl;
    return (*this);
}


/**
 * @brief Cat Decstructor . 
*/
Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destructor was called !" << std::endl;
}



/**
 * @brief makeSound Display Cat sound to std output  .
*/
void Cat::makeSound(void) const
{
    std::cout << "Meow Meow Meow " << std::endl;
}


/**
 * @brief showXIdeas display x ideas of dog .
 * @param [in] x number of ideas to display .
*/
void Cat::showXIdeas(unsigned int x) const
{
    if (x > 100)
        return;
    std::cout << "Cat ideas : ";
    for (unsigned int i = 0; i < x; i++)
        std::cout << "'" << this->brain->getIdeaByIndex(i) << "' , ";
    std::cout << std::endl;
}

/**
 * @brief getBrain get cats brain reff .
 * @return ref to cat brain .
*/
Brain& Cat::getBrain(void) const
{
    return *this->brain;
}
