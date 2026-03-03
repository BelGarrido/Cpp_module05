#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

class ShrubberyCreationForm: public AForm {
    private:
        std::string _target;
        ShrubberyCreationForm();

    public:
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &original);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &original);
        ~ShrubberyCreationForm();

        virtual void sign(Bureaucrat &b);
        virtual void execute(Bureaucrat const &b) const;
} ;


#endif