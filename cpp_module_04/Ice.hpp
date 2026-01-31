/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:19:25 by msidry            #+#    #+#             */
/*   Updated: 2026/01/29 21:54:46 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    
    public:
        Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
        ~Ice();
        
        AMateria* clone(void) const;
        void use(ICharacter& target);
    
};

#endif // ICE_HPP
