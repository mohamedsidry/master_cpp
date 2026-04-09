#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

/**
 * @brief main - entry point of program .
 * @return 0 on success or exit code on failure .
*/
int main(void)
{
    {
        if (DEBUGMODE)
            std::cout << "\033[33;1mTEST 0 : Instantiation \033[0m" << std::endl;
        Bureaucrat boss("boss", 1);
        ShrubberyCreationForm shrubbery("HOME");
        RobotomyRequestForm robotomy("ROBO");
        PresidentialPardonForm president("PRESIDENT");
        Intern src;

    }
    {
        if (DEBUGMODE)
            std::cout << "\033[33;1mTEST 1 : attributes values \033[0m" << std::endl;
        Bureaucrat boss("bossName", 1);
        ShrubberyCreationForm shrubbery("HOME");
        PresidentialPardonForm president("PRESIDENT");
        RobotomyRequestForm robotomy("ROBO");
        std::cout << "Bureaucrat name is : " << boss.getName() << std::endl;
        std::cout << "Bureaucrat grade is : " << boss.getGrade() << std::endl;
        std::cout << "Form name is : " << shrubbery.getName() << std::endl;
        std::cout << "Form grade to sign is : " << shrubbery.getGradeToSign() << std::endl;
        std::cout << "Form grade to execute is : " << shrubbery.getGradeToExecute() << std::endl;
        std::cout << "Form is signed : " << (shrubbery.getIsSigned() ? "true" : "false") << std::endl;

        std::cout << "Form name is : " << president.getName() << std::endl;
        std::cout << "Form grade to sign is : " << president.getGradeToSign() << std::endl;
        std::cout << "Form grade to execute is : " << president.getGradeToExecute() << std::endl;
        std::cout << "Form is signed : " << (president.getIsSigned() ? "true" : "false") << std::endl;

        std::cout << "Form name is : " << robotomy.getName() << std::endl;
        std::cout << "Form grade to sign is : " << robotomy.getGradeToSign() << std::endl;
        std::cout << "Form grade to execute is : " << robotomy.getGradeToExecute() << std::endl;
        std::cout << "Form is signed : " << (robotomy.getIsSigned() ? "true" : "false") << std::endl;

        
    }
    {
        if (DEBUGMODE)
            std::cout << "\033[33;1mTEST 2 : funcs BHVRS \033[0m" << std::endl;
        try 
        {
            Bureaucrat farmer("Farmer", 137);
            Intern src;
            AForm *form = src.makeForm("shrubbery creation", "Bender");
            if (form)
            {
                farmer.signForm(*form);
                farmer.executeForm(*form); 
            }
            delete form;
        }
        catch (std::exception const & e)
        {
            std::cerr << e.what() << std::endl;
        }

        try 
        {
            Bureaucrat staff("staff", 5);
            Intern src;
            AForm *form = src.makeForm("presidential pardon", "Freez");
            if (form)
            {
                staff.signForm(*form);
                staff.executeForm(*form); 
            }
            delete form;
        }
        catch (std::exception const & e)
        {
            std::cerr << e.what() << std::endl;
        }

        try 
        {
            Bureaucrat doood("Roboticizer", 5);
            Intern src;
            AForm *form = src.makeForm("robotomy request", "Server");
            if (form)
            {
                doood.signForm(*form);
                doood.executeForm(*form); 
            }
            delete form;
        }
        catch (std::exception const & e)
        {
            std::cerr << e.what() << std::endl;
        }
        
    }
    return (0);
}
