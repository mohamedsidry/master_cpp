/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 10:58:23 by msidry            #+#    #+#             */
/*   Updated: 2026/01/27 14:07:00 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <cassert>
int main(void)
{
    {
        // NOTE : goal of this tests is to know the order of constructor / destructor
        std::cout << "\033[1;33mTEST 1 : constructor / destructor .\033[0m" << std::endl;
        ClapTrap pl1;
        ScavTrap pl2;
        FragTrap pl3;
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
    }
    {
        // NOTE : goal of this tests Polymorphism.
        std::cout << "\033[1;33mTEST 3 : BHVRS testing .\033[0m" << std::endl;
        ClapTrap* ptr1 = new ClapTrap("player1");
        ClapTrap* ptr2 = new ScavTrap("player2");
        ClapTrap* ptr3 = new FragTrap("player3");
        ptr1->attack(ptr2->getName());
        ptr2->takeDamage(ptr1->getAttackDamage());
        ptr1->beRepaired(10);
        ptr2->attack(ptr1->getName());
        ptr1->takeDamage(ptr2->getAttackDamage());
        ptr2->beRepaired(3);
        ptr3->attack(ptr2->getName());
        ptr2->takeDamage(ptr3->getAttackDamage());
        ptr2->attack(ptr3->getName());
        ptr1->takeDamage(ptr2->getAttackDamage());
        delete ptr1;
        delete ptr2; 
    }
    {
        std::cout << "\033[1;33mTEST 3 : special abilities .\033[0m" << std::endl;
        // NOTE : goal is to test derived class members !
        {
            // NOTE : goal is to test if ScavTrap can guard the gate !guard
            ScavTrap *guarder = new ScavTrap("GATEGUARDER");
            guarder->guardGate();
            delete guarder;
        }
        {
            // NOTE : goal is to test if fragTrap can d high-five
            FragTrap *ft = new FragTrap("CHARMBOY");
            ft->highFivesGuys();
            delete ft;
        } 
    }
    
    {
        std::cout << "\033[1;32mTEST 3 : GOAL CHECKS .\033[0m" << std::endl;
        ScavTrap *st;
        FragTrap *ft, *tmp;
        ClapTrap *players[] = {
            new ClapTrap("ENEMY 1"),
            new ClapTrap("ENEMY 2"), 
            new ClapTrap("ENEMY 3"),
            new ScavTrap("GUARDER"),
            new FragTrap("BOSS")
            };
        for (int i = 0; i < 5; i++)
        {
            st = dynamic_cast<ScavTrap *>(players[i]);
            if (st)
            {
                st->guardGate();
                continue;
            }
            ft = dynamic_cast<FragTrap *>(players[i]);
            if (ft)
            {
                for (int j = 0 ; j < 5; j++)
                {
                    tmp = dynamic_cast<FragTrap *>(players[j]);
                    if (tmp == ft)
                        continue;
                    st = dynamic_cast<ScavTrap *>(players[j]);
                    if (st)
                    {
                        ft->highFivesGuys();
                        st->guardGate();
                        continue;
                    }
                    ft->attack(players[j]->getName());
                    players[j]->takeDamage(ft->getAttackDamage());
                }
                continue;
            }
            players[i]->attack(players[4]->getName());
        }
        for (int i = 0; i < 5; i++)
            delete players[i];
        
    }

    return (0);
}
