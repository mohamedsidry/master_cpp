/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:26:12 by msidry            #+#    #+#             */
/*   Updated: 2026/03/11 15:32:37 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
    static const std::string DEFAULT_NAME;
    static const int DEFAULT_GRADE;
    
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        const std::string& getName(void) const;
        int getGrade(void) const;
        void increase(void);
        void decrease(void);
        
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
};

std::ostream& operator <<(std::ostream& os, const Bureaucrat& ref);
#endif // BUREAUCRAT_HPP

