/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:31:32 by msidry            #+#    #+#             */
/*   Updated: 2026/01/31 15:01:30 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Character.hpp"

/**
 * @brief Character Default constructor .
*/
Character::Character():
name("Unknown")
{
    //inventory
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
    if (Floor::debugging())
        std::cout << "Character default constructor was called !" << std::endl; 
}


/**
 * @brief Character constructor .
*/
Character::Character(const std::string& name):
name(name)
{
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
    if (Floor::debugging())
        std::cout << "Character constructor was called !" << std::endl; 
}


/**
 * @brief Character copy constructor .
*/
Character::Character(const Character& other):
name(other.name)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
    if (Floor::debugging())
        std::cout << "Character copy constructor was called !" << std::endl;  
}

/**
 * @brief Character copy assign constructor .
 * @param [in] other object to copy from .
 * @return copy of object 
*/
Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->name = other.name;
        for (int i = 0; i < 4; i++)
        {
            delete this->inventory[i];
            if (other.inventory[i])
                this->inventory[i] = other.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
    }
    if (Floor::debugging())
        std::cout << "Character copy assign constructor was called !" << std::endl; 
    return *this;
}

/**
 * @brief Destructor constructor .
*/
Character::~Character()
{
    for (int i = 0; i < 4; i ++)
        delete this->inventory[i];
    if (Floor::debugging())
        std::cout << "Character destructor was called !" << std::endl; 
}


/**
 * @brief getName Get name  att of object .
 * @return ref to name of object .
*/
std::string const& Character::getName(void) const
{
    return (this->name);
}


/**
 * @brief equip Equip materia to inventory empty slot or do nothing if full .
 * @param [in] m materia to be injected .
*/
void Character::equip(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == NULL)
        {
            this->inventory[i] = m;
            return;
        }
    }
    Floor::instance().add(m);
}

/**
 * @brief unequip release inventory slot .
 * @param [in] idx slot index to be released .
*/

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
        return ;
    Floor::instance().add(this->inventory[idx]);
    this->inventory[idx] = NULL;
}


void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3 || this->inventory[idx] == NULL)
        return;
    this->inventory[idx]->use(target);
}
