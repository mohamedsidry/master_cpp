/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:03:26 by msidry            #+#    #+#             */
/*   Updated: 2026/02/02 16:04:38 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
    private:
        std::string ideas[100];
    
    public:
        Brain();
        Brain(const Brain& other);
        Brain(const std::string& idea);
        Brain& operator=(const Brain& other);
        ~Brain();
        std::string getIdeaByIndex(unsigned int idx) const;
};


#endif // BRAIN_HPP 
