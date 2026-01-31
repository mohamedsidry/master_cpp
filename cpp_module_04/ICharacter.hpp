/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:00:38 by msidry            #+#    #+#             */
/*   Updated: 2026/01/31 14:59:00 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP

# define ICHARACTER_HPP

#include <string>
#include <iostream>
#include "Floor.hpp"

class AMateria;

class ICharacter
{
    public:
        virtual ~ICharacter() {};
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

#endif // ICHARACTER_HPP
