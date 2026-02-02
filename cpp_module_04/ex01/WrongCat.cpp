
#include "WrongCat.hpp"
#include <iostream>



/**
 * @brief WrongCat Default constructor .
*/
WrongCat::WrongCat():
WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor was called !  " << std::endl;
}


/**
 * @brief WrongCat copy constructor .
*/
WrongCat::WrongCat(const WrongCat& other):
WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor was called !  " << std::endl;
}


WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
        WrongAnimal::operator=(other);
    std::cout << "WrongCat copy assign constructor was called !" << std::endl;
    return (*this);
}



WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor was called !" << std::endl;
}




void WrongCat::makeSound(void) const
{
    std::cout << "gerr gerr gerr " << std::endl;
}

