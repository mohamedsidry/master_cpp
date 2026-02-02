/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:59:03 by msidry            #+#    #+#             */
/*   Updated: 2026/02/02 11:24:10 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>


/**
 * @brief Cat Default constructor .
*/
Cat::Cat():
Animal("cat")
{
    std::cout << "Cat default constructor was called !  " << std::endl;
}


/**
 * @brief Cat copy constructor .
*/
Cat::Cat(const Cat& other):
Animal(other)
{
    std::cout << "Cat copy constructor was called !  " << std::endl;
}


Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << "Cat copy assign constructor was called !" << std::endl;
    return (*this);
}



Cat::~Cat()
{
    std::cout << "Cat destructor was called !" << std::endl;
}




void Cat::makeSound(void) const
{
    std::cout << "Meow Meow Meow " << std::endl;
}

