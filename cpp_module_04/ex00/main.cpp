/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:22:26 by msidry            #+#    #+#             */
/*   Updated: 2026/02/02 11:58:09 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"



int main(void)
{
    {
        // NOTE : goal of this tests is to know the order of constructor / destructor
        std::cout << "\033[1;33mTEST 1 : constructor / destructor .\033[0m" << std::endl;
        Animal an;
        Dog java;
        Cat lona;
    }
    {
        // NOTE : attributes !
        std::cout << "\033[1;33mTEST 2 : attributes .\033[0m" << std::endl;
        Animal an;
        Dog java;
        Cat lona;
        std::cout << "Animal type is : " << an.getType() << std::endl;
        std::cout << "Dog type is : " << java.getType() << std::endl;
        std::cout << "Cat type is : " << lona.getType() << std::endl;
    }
    {
        // NOTE : bhvrs !
        std::cout << "\033[1;33mTEST 3 : methods .\033[0m" << std::endl;
        WrongAnimal *kitty = new WrongCat();
        kitty->makeSound();
        delete kitty;
        
    }
    {
        // NOTE : bhvrs !
        std::cout << "\033[1;33mTEST 4 : methods .\033[0m" << std::endl;
        Dog speed;
        Cat lona;
        std::cout << "I am a *" << speed.getType() << "* i sound like ";  
        speed.makeSound();
        std::cout << "I am a *" << lona.getType() << "* i sound like ";  
        lona.makeSound();
    }
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
        delete meta;
        delete i;
        delete j;
    }

    return (0);
}

