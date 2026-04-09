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

