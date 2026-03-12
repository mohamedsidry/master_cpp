/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:48:33 by msidry            #+#    #+#             */
/*   Updated: 2026/03/12 18:25:44 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const & target);
        ShrubberyCreationForm(ShrubberyCreationForm const & other);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const & other);
        ~ShrubberyCreationForm();
        virtual void execute(Bureaucrat const & executor) const ;
        class FailedToOpenFileException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

