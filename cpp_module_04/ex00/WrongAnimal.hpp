/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:41:58 by msidry            #+#    #+#             */
/*   Updated: 2026/02/02 12:00:17 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
    protected:
        std::string type;


    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal(const std::string& other);
        WrongAnimal& operator=(const WrongAnimal& other);
        ~WrongAnimal();
        void makeSound(void) const;
        std::string const& getType(void) const;
        
    
};


#endif // WRONGANIMAL_HPP

