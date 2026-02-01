/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:56:49 by msidry            #+#    #+#             */
/*   Updated: 2026/02/01 13:02:01 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


/**
 * @brief ScavTrap: default constructor .
 * @details: set attributes to default values .
 * @param no_params
 * @return nothing !
*/
ScavTrap::ScavTrap():
ClapTrap("ScavTraper", ScavTrap::_scav_hp, ScavTrap::_scav_ep, ScavTrap::_scav_ad)
{
    std::cout << "ScavTrap " << "Default constructor called !" << std::endl;
}

/**
 * @brief ScavTrap: constructor that takes a name .
 * @details: set attributes to default and name to name .
 * @param [in] name sets name attribute to name !
 * @return nothing !
*/
ScavTrap::ScavTrap(const std::string& name): 
ClapTrap(name, ScavTrap::_scav_hp, ScavTrap::_scav_ep, ScavTrap::_scav_ad)
{
    std::cout << "ScavTrap " << "Constructor with name was called !" << std::endl;
}
/**
 * @brief ScavTrap: copy constructor .
 * @details: set new object attributes to other attributes values .
 * @param [in] other ref to object to copy from it !
 * @return nothing !
*/
ScavTrap::ScavTrap(const ScavTrap& other):
ClapTrap(other)
{
    std::cout << "ScavTrap " << "Copy constructor was called !" << std::endl;
}

/**
 * @brief operator=: copy assignment operator .
 * @details: set new object attributes to other attributes values .
 * @param [in] other ref to object to copy from it !
 * @return new object !
*/
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "ScavTrap " << "Copy assignment operator was called !" << std::endl;
    return *this;
}

/**
 * @brief ~ScavTrap: default destructor .
 * @details: release the resourses .
 * @param no_params
 * @return nothing !
*/
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << "Destructor was called !" << std::endl;
}


/**
 * @brief attack: override attack behaviour .
 * @details : attack enemy name 'target' if attacker has energy points and still alive 
 *            this would cuz the attacker to lose energy point .
 * @param [in] target : name of the target .
 * @return nothing .
*/
void ScavTrap::attack(const std::string& target)
{
    unsigned int hp, ep;

    hp = this->hitPoints;
    ep = this->energyPoints;
    if (hp == 0 || ep == 0)
        return ;
    this->energyPoints--;
    std::cout << "ScavTrap "  << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}


/**
 * @brief beRepaired: Override repaire behaviour .
 * @details : call this would make ScavTrap repairs itself by gaining hitpoints . 
 * @param [in] amount : number of hit points to regain .
 * @return nothing .
*/
void ScavTrap::beRepaired(unsigned int amount)
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
    std::cout << "ScavTrap " << this->name << " repairs itself, regaining " << amount << " hit points!" << std::endl;
}

/**
 * @brief takeDamage: Override takeDamage behaviour .
 * @details : call this would make ScavTrap lost amount hitpoints . 
 * @param [in] amount : number of hit points to lose .
 * @return nothing .
*/
void ScavTrap::takeDamage(unsigned int amount)
{
    unsigned int hp;

    hp = this->hitPoints;
    if (hp == 0)
    {
        std::cout << "ScavTrap " << this->name << " is already destroyed!" << std::endl;
        return ;
    }
    if (amount >= hp)
        amount = hp;
    this->hitPoints -= amount;
    std::cout << "ScavTrap "  << this->name << " has lost " << amount << " hit points!" << std::endl;
    if (this->hitPoints == 0)
        std::cout   << "ScavTrap "  << this->name<< " has been destroyed!" << std::endl;
}

/**
 * @brief guardGate: ScavTrap display a message indicate  ScavTrap that in Gate keeper mode .
 * @param no_params .
 * @return nothing .
*/
void ScavTrap::guardGate(void)
{
    std::cout   << "ScavTrap "  << this->name << " is now in Gate keeper mode!" << std::endl;
}
