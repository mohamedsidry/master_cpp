/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:21:36 by msidry            #+#    #+#             */
/*   Updated: 2026/03/12 21:25:20 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP

# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    static const int DEFAULT_GRADE;
    static const std::string DEFAULT_NAME;
    
    private:
        const std::string   name;
        const int           grade_to_sign;
        const int           grade_to_execute;
        bool                is_signed;

    public:

        AForm();
        AForm(const std::string& name, int g_to_sign, int g_to_exe);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
        const std::string& getName(void) const;
        bool getIsSigned(void) const;
        bool ReadyToBeExecutedBy(Bureaucrat const & executor) const;
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

        class FormIsNotSignedException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& ref);

#endif // FORM_HPP
