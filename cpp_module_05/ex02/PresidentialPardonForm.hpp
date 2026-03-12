/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 22:02:31 by msidry            #+#    #+#             */
/*   Updated: 2026/03/12 16:38:50 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP

#define PRESIDENTIALPARDONFORM_HPP



#include "AForm.hpp"



class PresidentialPardonForm : public AForm
{
    private:
        std::string target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const & target);
        PresidentialPardonForm(PresidentialPardonForm const & other);
        PresidentialPardonForm& operator=(PresidentialPardonForm const & other);
        ~PresidentialPardonForm();

        virtual void execute(Bureaucrat const & executor) const;
    
};

#endif // PRESIDENTIALPARDONFORM_HPP
