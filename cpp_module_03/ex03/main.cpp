/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 10:58:23 by msidry            #+#    #+#             */
/*   Updated: 2026/01/31 23:18:06 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <cassert>
int main(void)
{
    {
        // NOTE : goal of this tests is to know the order of constructor / destructor
        std::cout << "\033[1;33mTEST 1 : constructor / destructor .\033[0m" << std::endl;
        DiamondTrap pl4;
    }
    {
        // NOTE : default object values !
        std::cout << "\033[1;33mTEST 2 : default init values .\033[0m" << std::endl;
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
        FragTrap pl3("PLAYER_3");
        std::cout << "pl3 name : " << pl3.getName() << std::endl;
        std::cout << "pl3 HP   : " << pl3.getHitPoints() << std::endl;
        std::cout << "pl3 EP   : " << pl3.getEnergyPoints() << std::endl;
        std::cout << "pl3 AD   : " << pl3.getAttackDamage() << std::endl;
        DiamondTrap pl4("PLAYER_4");
        std::cout << "pl3 name : " << pl4.getMyName() << std::endl;
        std::cout << "pl3 HP   : " << pl4.getHitPoints() << std::endl;
        std::cout << "pl3 EP   : " << pl4.getEnergyPoints() << std::endl;
        std::cout << "pl3 AD   : " << pl4.getAttackDamage() << std::endl;
    }
    {
        // NOTE : goal of this tests Polymorphism.
        std::cout << "\033[1;33mTEST 3 : BHVRS testing .\033[0m" << std::endl;
        DiamondTrap* ptr1 = new DiamondTrap("Diamond");
        ClapTrap* ptr2 = new FragTrap("player3");
        ptr1->attack(ptr2->getName());
        ptr2->takeDamage(ptr1->getAttackDamage());
        ptr1->beRepaired(10);
        ptr2->attack(ptr1->getMyName());
        ptr1->takeDamage(ptr2->getAttackDamage());
        ptr2->beRepaired(3);
        ptr1->takeDamage(ptr2->getAttackDamage());
        delete ptr1;
        delete ptr2;
    }
    {
        std::cout << "\033[1;32mTEST 4 : Diamond CHECKS .\033[0m" << std::endl;
        DiamondTrap *ptr = new DiamondTrap("HUGGY");
        ptr->guardGate();
        ptr->highFivesGuys();
        ptr->whoAmI();
        delete ptr;
        
    }

    return (0);
}
