/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:56:56 by msidry            #+#    #+#             */
/*   Updated: 2026/02/01 12:56:37 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"


class ScavTrap: virtual public ClapTrap
{
    protected:
        const static unsigned int _scav_hp = 100;
        const static unsigned int _scav_ep = 50;
        const static unsigned int _scav_ad = 20;
        
    public:
        ScavTrap();
        ScavTrap(const std::string& name);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap();
        
        void guardGate(void);
        // NOTE : override bhvrs .
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        // HELPER
};


#endif // SCAVTRAP_HPP

