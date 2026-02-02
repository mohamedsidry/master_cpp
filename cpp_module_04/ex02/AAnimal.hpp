/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:40:02 by msidry            #+#    #+#             */
/*   Updated: 2026/02/02 19:03:22 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>

class AAnimal
{
    protected:
        std::string type;


    public:
        AAnimal();
        AAnimal(const AAnimal& other);
        AAnimal(const std::string& other);
        AAnimal& operator=(const AAnimal& other);
        virtual ~AAnimal();
        virtual void makeSound(void) const = 0;
        std::string const& getType(void) const;
        
    
};


#endif // AANIMAL_HPP

