/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:37:24 by msidry            #+#    #+#             */
/*   Updated: 2026/01/31 23:17:05 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap():
ClapTrap("DiamondTraper_clap_name", FragTrap::frag_hp, ScavTrap::scav_ep, FragTrap::frag_ad),
FragTrap(),
ScavTrap(),
name("DiamondTraper")
{
    std::cout << "DiamondTraper " << "Default constructor called !" << std::endl;
}



DiamondTrap::DiamondTrap(const std::string& name):
ClapTrap(name + "_clap_name", FragTrap::frag_hp, ScavTrap::scav_ep, FragTrap::frag_ad),
FragTrap(name),
ScavTrap(name),
name(name)
{
    std::cout << "DiamondTrap " << "Constructor with name was called !" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other):
ClapTrap(other),
FragTrap(other),
ScavTrap(other),
name(other.name)
{
    std::cout << "DiamondTrap " << "Copy constructor was called !" << std::endl;
}


DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->name = other.name;
    }
    std::cout << "DiamondTrap " << "Copy assignment operator was called !" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << "Destructor was called !" << std::endl;
}


void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::beRepaired(unsigned int amount)
{   
    unsigned int hp, ep;

    hp = this->hitPoints;
    ep = this->energyPoints;
    if (hp == 0 || ep == 0)
        return ;
    this->energyPoints--;
    if (hp + amount < hp)
        amount = ~0 - hp;
    this->hitPoints += amount;
    std::cout << "DiamondTrap " << this->name << " repairs itself, regaining " << amount << " hit points!" << std::endl;

}


void DiamondTrap::takeDamage(unsigned int amount)
{
    unsigned int hp;

    hp = this->hitPoints;
    if (hp == 0)
    {
        std::cout << "DiamondTrap " << this->name << " is already destroyed!" << std::endl;
        return ;
    }
    if (amount >= hp)
        amount = hp;
    this->hitPoints -= amount;
    std::cout << "DiamondTrap "  << this->name << " has lost " << amount << " hit points!" << std::endl;
    if (this->hitPoints == 0)
        std::cout   << "DiamondTrap "  << this->name << " has been destroyed!" << std::endl;
}


void DiamondTrap::whoAmI(void)
{
    std::cout << "I'am Mr." << this->name << std::endl;
    std::cout << "My subclass Name is " << this->getName() << ", is not that weird !"<< std::endl;
}

std::string const & DiamondTrap::getMyName(void)
{
    return this->name;
}
