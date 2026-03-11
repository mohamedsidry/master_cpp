/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:31:25 by msidry            #+#    #+#             */
/*   Updated: 2026/03/11 15:31:56 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
    {
        std::cout << "\033[33;1mTEST 0 : Instantiation \033[0m" << std::endl;
        Bureaucrat boss("boss", 1);
        Form taxForm("tax", 50, 50);
    }
    {
        std::cout << "\033[33;1mTEST 1 : attributes values \033[0m" << std::endl;
        Bureaucrat boss("bossName", 1);
        Form taxForm("taxName", 50, 50);
        std::cout << "Bureaucrat name is : " << boss.getName() << std::endl;
        std::cout << "Bureaucrat grade is : " << boss.getGrade() << std::endl;
        std::cout << "Form name is : " << taxForm.getName() << std::endl;
        std::cout << "Form grade to sign is : " << taxForm.getGradeToSign() << std::endl;
        std::cout << "Form grade to execute is : " << taxForm.getGradeToExecute() << std::endl;
        std::cout << "Form is signed : " << (taxForm.getIsSigned() ? "true" : "false") << std::endl;
    }
    {
        std::cout << "\033[33;1mTEST 2 : funcs BHVRS \033[0m" << std::endl;
        Bureaucrat boss("bossName", 1);
        std::cout << boss << std::endl;
        Form form;
        std::cout << form << std::endl;
        boss.signForm(form);
        std::cout << form << std::endl;
    }

    {
        std::cout << "\033[33;1mTEST 3 : Exceptions \033[0m" << std::endl;
        try
        {
            Bureaucrat staff1("staff N1", 50);
            Bureaucrat staff2("staff N2", 50);
            Bureaucrat dr("Dr Name", 20);
            Bureaucrat student("student Name", 150);
            Form freezRequest("Freez Request", 50 , 1);
            Form healthInsurance("health Insurance refound", 20, 1);
            Form project("project Name", 150, 1);
            student.signForm(project);
            student.signForm(freezRequest);
            staff1.signForm(freezRequest);
            staff2.signForm(freezRequest);
            student.signForm(healthInsurance);
            staff1.signForm(healthInsurance);
            dr.signForm(healthInsurance);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return (0);
}
