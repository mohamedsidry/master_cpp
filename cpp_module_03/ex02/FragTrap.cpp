/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:16:18 by msidry            #+#    #+#             */
/*   Updated: 2026/01/31 22:31:38 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


/**
 * @brief FragTrap: default constructor .
 * @details: set attributes to default values .
 * @param no_params
 * @return nothing !
*/
FragTrap::FragTrap():
ClapTrap()
{
    this->name = "FragTraper";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << "Default constructor called !" << std::endl;
}

/**
 * @brief FragTrap: constructor that takes a name .
 * @details: set attributes to default and name to name .
 * @param [in] name sets name attribute to name !
 * @return nothing !
*/
FragTrap::FragTrap(const std::string& name): 
ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << "Constructor with name was called !" << std::endl;
}
/**
 * @brief FragTrap: copy constructor .
 * @details: set new object attributes to other attributes values .
 * @param [in] other ref to object to copy from it !
 * @return nothing !
*/
FragTrap::FragTrap(const FragTrap& other):
ClapTrap(other)
{
    std::cout << "FragTrap " << "Copy constructor was called !" << std::endl;
}

/**
 * @brief operator=: copy assignment operator .
 * @details: set new object attributes to other attributes values .
 * @param [in] other ref to object to copy from it !
 * @return new object !
*/
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "FragTrap " << "Copy assignment operator was called !" << std::endl;
    return *this;
}

/**
 * @brief ~FragTrap: default destructor .
 * @details: release the resourses .
 * @param no_params
 * @return nothing !
*/
FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << "Destructor was called !" << std::endl;
}


/**
 * @brief attack: override attack behaviour .
 * @details : attack enemy name 'target' if attacker has energy points and still alive 
 *            this would cuz the attacker to lose energy point .
 * @param [in] target : name of the target .
 * @return nothing .
*/
void FragTrap::attack(const std::string& target)
{
    unsigned int hp, ep;

    hp = this->hitPoints;
    ep = this->energyPoints;
    if (hp == 0 || ep == 0)
        return ;
    this->energyPoints--;
    std::cout << "FragTrap "  << this->name << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}


/**
 * @brief beRepaired: Override repaire behaviour .
 * @details : call this would make FragTrap repairs itself by gaining hitpoints . 
 * @param [in] amount : number of hit points to regain .
 * @return nothing .
*/
void FragTrap::beRepaired(unsigned int amount)
{
    unsigned int hp, ep;

    hp = this->hitPoints;
    ep = this->energyPoints;
    if (hp == 0 || ep == 0)
        return ;
    this->energyPoints--;
    if (hp + amount < hp)
        amount = ~0 - hp;
    this->hitPoints+= amount;
    std::cout << "FragTrap " << this->name << " repairs itself, regaining " << amount << " hit points!" << std::endl;
}

/**
 * @brief takeDamage: Override takeDamage behaviour .
 * @details : call this would make FragTrap lost amount hitpoints . 
 * @param [in] amount : number of hit points to lose .
 * @return nothing .
*/
void FragTrap::takeDamage(unsigned int amount)
{
    unsigned int hp;

    hp = this->hitPoints;
    if (hp == 0)
    {
        std::cout << "FragTrap " << this->name << " is already destroyed!" << std::endl;
        return ;
    }
    if (amount >= hp)
        amount = hp;
    this->hitPoints -= amount;
    std::cout << "FragTrap "  << this->name << " has lost " << amount << " hit points!" << std::endl;
    if (this->hitPoints == 0)
        std::cout   << "FragTrap "  << this->name<< " has been destroyed!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout   << "FragTrap "  << this->name<< " high-fives guys ?" << std::endl;
}
