#ifndef ROBOTOMY_HPP
#define ROBOTOMY_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

class RobotomyRequestForm: public AForm {
    private:
        std::string _target;
        RobotomyRequestForm();

    public:
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &original);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &original);
        ~RobotomyRequestForm();

        virtual void sign(Bureaucrat &b);
        virtual void execute(Bureaucrat const &b) const;
} ;

#endif