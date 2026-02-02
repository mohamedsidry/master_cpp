/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:40:02 by msidry            #+#    #+#             */
/*   Updated: 2026/02/02 11:29:54 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
    protected:
        std::string type;


    public:
        Animal();
        Animal(const Animal& other);
        Animal(const std::string& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();
        virtual void makeSound(void) const;
        std::string const& getType(void) const;
        
    
};


#endif // ANIMAL_HPP

