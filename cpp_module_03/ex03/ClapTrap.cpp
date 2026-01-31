/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 10:58:34 by msidry            #+#    #+#             */
/*   Updated: 2026/01/31 22:53:29 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


/**
 * @brief ClapTrap: default constructor .
*/
ClapTrap::ClapTrap():
name("ClapTraper"),
hitPoints(10),
energyPoints(10),
attackDamage(0)
{
    std::cout << "ClapTraper " << "Default constructor called !" << std::endl;
}

ClapTrap::ClapTrap(std::string const& name,
                   unsigned int hp,
                   unsigned int energy,
                   unsigned int attack)
    : name(name), hitPoints(hp), energyPoints(energy), attackDamage(attack)
{
    std::cout << "ClapTraper " << "custom constructor called !" << std::endl;
}

/**
 * @brief ClapTrap: constructor that takes a name .
 * @details: set attributes to default and name to name .
 * @param [in] name sets name attribute to name !
*/
ClapTrap::ClapTrap(const std::string& name):
name(name),
hitPoints(10),
energyPoints(10),
attackDamage(0)
{
    std::cout << "ClapTraper " << "Constructor with name was called !" << std::endl;
}

/**
 * @brief ClapTrap: copy constructor .
 * @details: set new object attributes to other attributes values .
 * @param [in] other ref to object to copy from it !
*/
ClapTrap::ClapTrap(const ClapTrap& other):
name(other.name),
hitPoints(other.hitPoints),
energyPoints(other.energyPoints),
attackDamage(other.attackDamage)
{
    std::cout << "ClapTraper " << "Copy constructor was called !" << std::endl;
}

/**
 * @brief operator=: copy assignment operator .
 * @details: set new object attributes to other attributes values .
 * @param [in] other ref to object to copy from it !
 * @return new object !
*/

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "ClapTraper " << "Copy assignment operator was called !" << std::endl;
    return *this;
}

/**
 * @brief ~ClapTrap: default destructor .
 * @details: release the resourses .
*/
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTraper " << "Destructor was called !" << std::endl;
}

/**
 * @brief attack: attack behaviour .
 * @details : attack enemy name 'target' if attacker has energy points and still alive 
 *            this would cuz the attacker to lose energy point .
 * @param [in] target : name of the target .
*/

void ClapTrap::attack(const std::string& target)
{
    unsigned int hp, ep, ad;
    hp = this->hitPoints;
    ep = this->energyPoints;
    ad = this->attackDamage;
    if (hp == 0 || ep == 0)
        return ;
    this->energyPoints--;
    std::cout << "ClapTraper " << this->name << " attacks " << target << ", causing " << ad << " points of damage!" << std::endl;
}

/**
 * @brief beRepaired: repaire behaviour .
 * @details : call this would make ClapTrap repairs itself by gaining hitpoints . 
 * @param [in] amount : number of hit points to regain .
*/
void ClapTrap::beRepaired(unsigned int amount)
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
    std::cout << "ClapTraper " << this->name << " repairs itself, regaining " << amount << " hit points!" << std::endl;
}

/**
 * @brief takeDamage: getting attacked behaviour .
 * @details : call this would make ClapTrap lost amount hitpoints . 
 * @param [in] amount : number of hit points to lose .
*/
void ClapTrap::takeDamage(unsigned int amount)
{
    unsigned int hp;

    hp = this->hitPoints;
    if (hp == 0)
    {
        std::cout << "ClapTraper " << this->name << " is already destroyed!" << std::endl;
        return ;
    }
    if (amount >= hp)
        amount = hp;
    this->hitPoints -= amount;
    std::cout << "ClapTraper "  << this->name << " has lost " << amount << " hit points!" << std::endl;
    if (this->hitPoints == 0)
        std::cout   << "ClapTraper "  << this->name << " has been destroyed!" << std::endl;
}

// GETTERS 


/**
 * @brief getName: get attribute name .
 * @return name attribute of object .
*/
const std::string& ClapTrap::getName(void) const {return this->name;}


/**
 * @brief getHitPoints: get attribute HP .
 * @return hit points attribute of object .
*/
unsigned int ClapTrap::getHitPoints(void) const {return this->hitPoints;}




/**
 * @brief getEnergyPoints: get attribute EP .
 * @return energy points attribute of object .
*/
unsigned int ClapTrap::getEnergyPoints(void) const {return this->energyPoints;}

/**
 * @brief getAttackDamage: get attribute AD .
 * @return attack damage attribute of object .
*/
unsigned int ClapTrap::getAttackDamage(void) const {return this->attackDamage;}

