/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:06:43 by msidry            #+#    #+#             */
/*   Updated: 2026/02/01 12:58:25 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    protected:
        const static unsigned int _frag_hp = 100;
        const static unsigned int _frag_ep = 100;
        const static unsigned int _frag_ad = 30;
        
    public:
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();

        
        void highFivesGuys(void);
        // NOTE : override bhvrs .
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    
};


#endif //FRAGTRAP_HPP


