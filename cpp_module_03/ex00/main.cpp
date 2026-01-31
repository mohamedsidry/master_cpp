/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 10:58:23 by msidry            #+#    #+#             */
/*   Updated: 2026/01/31 22:35:33 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

int main(void)
{
    {
        // NOTE : goal of this tests is to know the order of constructor / destructor
        std::cout << "\033[1;33mTEST 1 : constructor / destructor .\033[0m" << std::endl;
        ClapTrap pl1;
    }
    
    {
        // NOTE : default object values !
        std::cout << "\033[1;33mTEST 2 : default init values .\033[0m" << std::endl;
        ClapTrap pl1("PLAYER_1");
        std::cout << "pl1 name : " << pl1.getName() << std::endl;
        std::cout << "pl1 HP   : " << pl1.getHitPoints() << std::endl;
        std::cout << "pl1 EP   : " << pl1.getEnergyPoints() << std::endl;
        std::cout << "pl1 AD   : " << pl1.getAttackDamage() << std::endl;
    }
    {
        // NOTE : goal of this tests Polymorphism.
        std::cout << "\033[1;33mTEST 3 : BHVRS testing .\033[0m" << std::endl;
        ClapTrap* pl1 = new ClapTrap("player1");
        ClapTrap* pl2 = new ClapTrap("player2");
        pl1->attack(pl2->getName());
        pl2->takeDamage(pl1->getAttackDamage());
        pl1->beRepaired(10);
        pl2->attack(pl1->getName());
        pl1->takeDamage(pl2->getAttackDamage());
        pl2->beRepaired(3);
        pl1->takeDamage(pl2->getAttackDamage());
        std::cout << "player1 name : " << pl1->getName() << std::endl;
        std::cout << "pl1 HP   : " << pl1->getHitPoints() << std::endl;
        std::cout << "pl1 EP   : " << pl1->getEnergyPoints() << std::endl;
        std::cout << "pl1 AD   : " << pl1->getAttackDamage() << std::endl;
        std::cout << "player2 name : " << pl2->getName() << std::endl;
        std::cout << "pl2 HP   : " << pl2->getHitPoints() << std::endl;
        std::cout << "pl2 EP   : " << pl2->getEnergyPoints() << std::endl;
        std::cout << "pl2 AD   : " << pl2->getAttackDamage() << std::endl;
        delete pl1;
        delete pl2; 
    }
    return (0);
}
