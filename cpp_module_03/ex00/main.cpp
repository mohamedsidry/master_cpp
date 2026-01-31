/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 10:58:23 by msidry            #+#    #+#             */
/*   Updated: 2026/01/26 22:58:11 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include <cassert>

int main(void)
{
    {
        ClapTrap tmp1("PLAYER 1");
        ClapTrap tmp2("PLAYER 2");
        {
            // NOTE : This checks default attributes .
            assert(tmp1.getHitPoints() == 10);
            assert(tmp1.getEnergyPoints() == 10);
            assert(tmp1.getAttackDamage() == 0);
        }
        {
            // NOTE : This checks behaviours .
            tmp1.attack(tmp2.getName());
            tmp2.takeDamage(0);
            tmp1.attack(tmp2.getName());
            tmp2.takeDamage(0);
            tmp2.attack(tmp1.getName());
            tmp1.takeDamage(0);
            tmp1.beRepaired(1);
        }

        {
            // NOTE : This checks changes of attributes values .
            assert(tmp1.getHitPoints() == 11);
            assert(tmp1.getEnergyPoints() == 10 - 2 - 1);
            assert(tmp2.getHitPoints() == 10);
            assert(tmp2.getEnergyPoints() == 10 - 1);
        }
    }
    ClapTrap *player1 = new ClapTrap();
    ClapTrap *player2 = new ClapTrap("player2");
    player1->attack(player2->getName());
    player2->takeDamage(3);
    player1->attack(player2->getName());
    player2->takeDamage(3);
    player1->attack(player2->getName());
    player2->takeDamage(3);
    player1->attack(player2->getName());
    player2->takeDamage(3);
    player2->attack(player1->getName());
    delete player1;
    delete player2;
    return (0);
}
