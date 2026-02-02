/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:22:26 by msidry            #+#    #+#             */
/*   Updated: 2026/02/02 18:52:42 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"



// void ll(void)
// {
//     system("leaks a.out");
// }
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
        Dog speed;
        Cat lona;
        std::cout << "I am a *" << speed.getType() << "* i sound like ";  
        speed.makeSound();
        std::cout << "I am a *" << lona.getType() << "* i sound like ";  
        lona.makeSound();
    }
    {
        // NOTE : copy !
        std::cout << "\033[1;33mTEST 4 : deep and shadow copy .\033[0m" << std::endl;
        Cat cat1;
        Cat cat2(cat1);
        cat1.showXIdeas(5);
        cat2.showXIdeas(5);
        cat1.getBrain().setIdeaByIndex("i need to eat chicken", 0);
        cat2.getBrain().setIdeaByIndex("i need to eat fish", 0);
        Cat cat3 = cat2;
        cat3.getBrain().setIdeaByIndex("i want to eat candy", 1);
        cat1.showXIdeas(5);
        cat2.showXIdeas(5);
        cat3.showXIdeas(5);
    }
    {
        // NOTE : copy !
        std::cout << "\033[1;33mTEST 4 : destructor  .\033[0m" << std::endl;
        Animal *animals[] = {
            new Dog(), new Cat(), new Dog(), new Cat(), new Dog(),
            new Cat(), new Cat(), new Dog(), new Dog(), new Cat(),
            };
        for (int i = 0; i < 10; i++)
        {
            std::cout << "I am a " << animals[i]->getType() << " I sound like " ;
            animals[i]->makeSound();
        }
        for (int i = 0; i < 10; i++)
            delete animals[i];
    }
    //atexit(ll);
    return (0);
}

