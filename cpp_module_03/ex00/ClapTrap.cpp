/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 10:58:34 by msidry            #+#    #+#             */
/*   Updated: 2026/01/27 14:03:29 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


/**
 * @brief ClapTrap: default constructor .
 * @details: set attributes to default values .
 * @param no_params
 * @return nothing !
*/
ClapTrap::ClapTrap():
name("ClapTraper"),
hitPoints(10),
energyPoints(10),
attackDamage(0)
{
    std::cout << "ClapTraper " << "Default constructor called !" << std::endl;
}

/**
 * @brief ClapTrap: constructor that takes a name .
 * @details: set attributes to default and name to name .
 * @param [in] name sets name attribute to name !
 * @return nothing !
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
 * @return nothing !
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
 * @param no_params
 * @return nothing !
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
 * @return nothing .
*/

void ClapTrap::attack(const std::string& target)
{
    unsigned int hp, ep, ad;
    hp = this->getHitPoints();
    ep = this->getEnergyPoints();
    ad = this->getAttackDamage();
    if (hp == 0 || ep == 0)
        return ;
    this->setEnergyPoints(ep - 1);
    std::cout << "ClapTraper " << this->getName() << " attacks " << target << ", causing " << ad << " points of damage!" << std::endl;
}

/**
 * @brief beRepaired: repaire behaviour .
 * @details : call this would make ClapTrap repairs itself by gaining hitpoints . 
 * @param [in] amount : number of hit points to regain .
 * @return nothing .
*/
void ClapTrap::beRepaired(unsigned int amount)
{
    unsigned int hp, ep;

    hp = this->getHitPoints();
    ep = this->getEnergyPoints();
    if (hp == 0 || ep == 0)
        return ;
    this->setEnergyPoints(ep - 1);
    if (hp + amount < hp)
        amount = ~0 - hp;
    this->setHitPoints (hp + amount);
    std::cout << "ClapTraper " << this->getName() << " repairs itself, regaining " << amount << " hit points!" << std::endl;
}

/**
 * @brief takeDamage: getting attacked behaviour .
 * @details : call this would make ClapTrap lost amount hitpoints . 
 * @param [in] amount : number of hit points to lose .
 * @return nothing .
*/
void ClapTrap::takeDamage(unsigned int amount)
{
    unsigned int hp;

    hp = this->getHitPoints();
    if (hp == 0)
    {
        std::cout << "ClapTraper " << this->getName() << " is already destroyed!" << std::endl;
        return ;
    }
    if (amount >= hp)
        amount = hp;
    this->setHitPoints (hp - amount);
    std::cout << "ClapTraper "  << this->getName() << " has lost " << amount << " hit points!" << std::endl;
    if (this->getHitPoints() == 0)
        std::cout   << "ClapTraper "  << this->getName() << " has been destroyed!" << std::endl;
}

// GETTERS && SETTERS 


/**
 * @brief setName: update attribute name .
 * @param [in] value : new name .
 * @return nothing .
*/
void ClapTrap::setName(const std::string& value){this->name = value;}

/**
 * @brief getName: get attribute name .
 * @param on_params .
 * @return name attribute of object .
*/
const std::string& ClapTrap::getName(void) const {return this->name;}

/**
 * @brief setHitPoints: update attribute HP  .
 * @param [in] value : new hit points value .
 * @return nothing .
*/
void ClapTrap::setHitPoints(unsigned int value){this->hitPoints = value;}

/**
 * @brief getHitPoints: get attribute HP .
 * @param on_params .
 * @return hit points attribute of object .
*/
unsigned int ClapTrap::getHitPoints(void) const {return this->hitPoints;}


/**
 * @brief setEnergyPoints: update attribute EP .
 * @param [in] value : new energy points value .
 * @return nothing .
*/
void ClapTrap::setEnergyPoints(unsigned int value){this->energyPoints = value;}

/**
 * @brief getEnergyPoints: get attribute EP .
 * @param on_params .
 * @return energy points attribute of object .
*/
unsigned int ClapTrap::getEnergyPoints(void) const {return this->energyPoints;}

/**
 * @brief setAttackDamage: update attribute AD .
 * @param [in] value : new attack damage value .
 * @return nothing .
*/
void ClapTrap::setAttackDamage(unsigned int value){this->attackDamage = value;}

/**
 * @brief getAttackDamage: get attribute AD .
 * @param on_params .
 * @return attack damage attribute of object .
*/
unsigned int ClapTrap::getAttackDamage(void) const {return this->attackDamage;}

