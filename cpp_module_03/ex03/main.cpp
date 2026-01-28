/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 10:58:23 by msidry            #+#    #+#             */
/*   Updated: 2026/01/28 15:40:14 by msidry           ###   ########.fr       */
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
        ClapTrap pl1;
        ScavTrap pl2;
        FragTrap pl3;
        DiamondTrap pl4;
    }

    {
        std::cout << "\033[1;32mTEST 2 : Diamond CHECKS .\033[0m" << std::endl;
        ClapTrap *ptr = new DiamondTrap("HUGGY");
        DiamondTrap *ptrD;
        ptrD = dynamic_cast<DiamondTrap*>(ptr);
        ptrD->whoAmI();
        delete ptr;
        
    }

    return (0);
}
