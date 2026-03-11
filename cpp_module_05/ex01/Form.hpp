/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:21:36 by msidry            #+#    #+#             */
/*   Updated: 2026/03/11 15:11:23 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP

# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    static const int DEFAULT_GRADE;
    static const std::string DEFAULT_NAME;
    
    private:
        const std::string   name;
        const int           grade_to_sign;
        const int           grade_to_execute;
        bool                is_signed;

    public:

        Form();
        Form(const std::string& name, int g_to_sign, int g_to_exe);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
        void beSigned(const Bureaucrat& bureaucrat);
        const std::string& getName(void) const;
        bool getIsSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class FormAlreadySignedException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& ref);

#endif // FORM_HPP
