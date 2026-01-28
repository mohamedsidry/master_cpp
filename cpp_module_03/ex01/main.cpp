/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 10:58:23 by msidry            #+#    #+#             */
/*   Updated: 2026/01/27 12:35:38 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <cassert>
int main(void)
{
    {
        // NOTE : goal of this tests is to know the order of constructor / destructor
        std::cout << "TEST 1 : constructor / destructor" << std::endl;
        ClapTrap pl1;
        ScavTrap pl2;
    }
    
    {
        // NOTE : default object values !
        std::cout << "TEST 2 : default init values " << std::endl;
        ClapTrap pl1("PLAYER_1");
        std::cout << "pl1 name : " << pl1.getName() << std::endl;
        std::cout << "pl1 HP   : " << pl1.getHitPoints() << std::endl;
        std::cout << "pl1 EP   : " << pl1.getEnergyPoints() << std::endl;
        std::cout << "pl1 AD   : " << pl1.getAttackDamage() << std::endl;
        ScavTrap pl2("PLAYER_2");
        std::cout << "pl2 name : " << pl2.getName() << std::endl;
        std::cout << "pl2 HP   : " << pl2.getHitPoints() << std::endl;
        std::cout << "pl2 EP   : " << pl2.getEnergyPoints() << std::endl;
        std::cout << "pl2 AD   : " << pl2.getAttackDamage() << std::endl;
    }
    {
        // NOTE : goal of this tests Polymorphism.
        ClapTrap* ptr1 = new ClapTrap("player1");
        ClapTrap* ptr2 = new ScavTrap("player2");
        ptr1->attack(ptr2->getName());
        ptr2->takeDamage(ptr1->getAttackDamage());
        ptr1->beRepaired(~0);
        ptr2->attack(ptr1->getName());
        ptr1->takeDamage(ptr2->getAttackDamage());
        ptr2->beRepaired(3);
        delete ptr1;
        delete ptr2; 
    }
    
    {
        // NOTE : goal is to test if ScavTrap can guard the gate !guard
        ScavTrap *guarder = new ScavTrap("GATEGUARDER");
        guarder->guardGate();
        delete guarder;
    }
    return (0);
}
