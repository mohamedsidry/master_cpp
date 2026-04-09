#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"


class RobotomyRequestForm : public AForm
{
    private:
        std::string target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const & target);
        RobotomyRequestForm(RobotomyRequestForm const & other);
        RobotomyRequestForm& operator=(RobotomyRequestForm const & other);
        ~RobotomyRequestForm();

        virtual void execute(Bureaucrat const & executor) const;
        
    
};

#endif // ROBOTOMYREQUESTFORM_HPP
