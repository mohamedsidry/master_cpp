/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:59:03 by msidry            #+#    #+#             */
/*   Updated: 2026/02/02 16:14:06 by msidry           ###   ########.fr       */
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
brain(new Brain("i need to eat some fish"))
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
 * @brief makeSound Display Cat indeas to std output  .
*/
void Cat::showIdeas(void) const
{
    for (unsigned int i = 0; i < 100; i++)
        std::cout << "index" << i << this->brain->getIdeaByIndex(i) << std::endl;
}
