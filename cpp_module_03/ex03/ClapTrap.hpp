/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 10:58:30 by msidry            #+#    #+#             */
/*   Updated: 2026/01/28 15:15:57 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
    private:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;
    
    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap &other);
        ClapTrap(const std::string& name, unsigned int hp, unsigned int ep, unsigned int ad);
        virtual ~ClapTrap();

        // BHVR
        virtual void attack(const std::string& target);
        virtual void takeDamage(unsigned int amount);
        virtual void beRepaired(unsigned int amount);
        
        // GETTERS
        const std::string& getName(void) const;
        unsigned int getHitPoints(void) const;
        unsigned int getEnergyPoints(void) const;
        unsigned int getAttackDamage(void) const;
        
        // SETTERS
        void setName(const std::string&  value);
        void setHitPoints(unsigned int value);
        void setEnergyPoints(unsigned int value);
        void setAttackDamage(unsigned int value);
 
};


#endif // CLAPTRAP_HPP

