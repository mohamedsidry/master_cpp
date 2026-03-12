/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:53:32 by msidry            #+#    #+#             */
/*   Updated: 2026/03/12 21:06:57 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
    private:
        AForm * createShrubberyCreation(std::string const & target) ;
        AForm * createRobotomyRequest(std::string const & target) ;
        AForm * createPresidentialPardon(std::string const & target) ;
        
    public:
        Intern();
        Intern(Intern const & other);
        Intern& operator=(Intern const &other);
        ~Intern();

        AForm* makeForm(std::string const &name, std::string const & target);

};


typedef struct s_form_map
{
    const std::string name;
    AForm * (Intern::*creator)(std::string const &);
} t_form_map;


#endif // INTERN_HPP

