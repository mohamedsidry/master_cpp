/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:31:25 by msidry            #+#    #+#             */
/*   Updated: 2026/03/09 15:49:33 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    {
        std::cout << "\033[33;1mTEST 0 : Instantiation \033[0m" << std::endl;
        Bureaucrat b1;
        Bureaucrat b2("Cypher-1", 1);
        Bureaucrat b3(b2);
        Bureaucrat b4("morpheus-100", 100);
        b4 = b2;
    }
    {
        std::cout << "\033[33;1mTEST 1 : attributes values \033[0m" << std::endl;
        Bureaucrat b1("Cypher-42", 42);
        std::cout << "Bureaucrat name is : " << b1.getName() << std::endl;
        std::cout << "Bureaucrat grade is : " << b1.getGrade() << std::endl;
        Bureaucrat b2("morpheus-99", 99);
        std::cout << "Bureaucrat name is : " << b2.getName() << std::endl;
        std::cout << "Bureaucrat grade is : " << b2.getGrade() << std::endl;
    }

    {
        std::cout << "\033[33;1mTEST 2 : funs BHVS \033[0m" << std::endl;
        Bureaucrat b("Cypher-100", 100);
        std::cout << b << std::endl;
        b.increase();
        b.increase();
        b.increase();
        std::cout << b << std::endl;
        b.decrease();
        b.decrease();
        std::cout << b << std::endl;
    }
    {
        std::cout << "\033[33;1mTEST 3 : Exceptions \033[0m" << std::endl;
        
        {
            try
            {
                Bureaucrat b("Bureaucrat 0", 0);
            }catch (const std::exception& e) 
            {
                std::cerr << e.what() << std::endl;
            }
            try
            {
                Bureaucrat b("Bureaucrat 1337", 1337);
            }catch (const std::exception& e) 
            {
                std::cerr << e.what() << std::endl;
            }
        }

        {
            
            try
            {
                Bureaucrat b1("Bureaucrat 1", 1);
                b1.increase();
            } catch(const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
            }

            try
            {
                Bureaucrat b150("Bureaucrat 1", 150);
                b150.decrease();
            } catch (const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
    }
    return (0);
}
