/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:31:25 by msidry            #+#    #+#             */
/*   Updated: 2026/03/12 19:40:15 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    {
        if (DEBUGMODE)
            std::cout << "\033[33;1mTEST 0 : Instantiation \033[0m" << std::endl;
        Bureaucrat unknown;
        Bureaucrat boss("BOSS", 1);
        Bureaucrat staff_1("STAFF", 50);
        Bureaucrat staff_2(staff_1);
        Bureaucrat student("Student Name", 150);
        student = Bureaucrat(staff_2);
    }
    {
        if (DEBUGMODE)
            std::cout << "\033[33;1mTEST 1 : attributes values \033[0m" << std::endl;
        Bureaucrat staff("STAFF", 50);
        std::cout << "Bureaucrat name is : " << staff.getName() << std::endl;
        std::cout << "Bureaucrat grade is : " << staff.getGrade() << std::endl;
        Bureaucrat student("Student Name", 150);
        std::cout << "Bureaucrat name is : " << student.getName() << std::endl;
        std::cout << "Bureaucrat grade is : " << student.getGrade() << std::endl;
    }

    {
        if (DEBUGMODE)
            std::cout << "\033[33;1mTEST 2 : funs BHVS \033[0m" << std::endl;
        Bureaucrat volunteer("Student", 100);
        std::cout << volunteer << std::endl;
        volunteer.increase();
        volunteer.increase();
        volunteer.increase();
        std::cout << volunteer << std::endl;
        volunteer.decrease();
        volunteer.decrease();
        std::cout << volunteer << std::endl;
    }
    {
        if (DEBUGMODE)
            std::cout << "\033[33;1mTEST 3 : Exceptions \033[0m" << std::endl;
        
        {
            try
            {
                Bureaucrat hacker("Hackeeeer", 0);
            }catch (const std::exception& e) 
            {
                std::cerr << e.what() << std::endl;
            }
            try
            {
                Bureaucrat pooler("pooler-1337", 1337);
            }catch (const std::exception& e) 
            {
                std::cerr << e.what() << std::endl;
            }
        }

        {
            
            try
            {
                Bureaucrat boss("Bossy", 1);
                boss.increase();
            } catch(const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
            }

            try
            {
                Bureaucrat dump("Dumpa$$ 1", 150);
                dump.decrease();
            } catch (const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
    }
    return (0);
}
