#ifndef PRESIDENTIAL_HPP
#define PRESIDENTIAL_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

class PresidentialPardonForm: public AForm {
    private:
        std::string _target;
        PresidentialPardonForm();
        
    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &original);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &original);
        ~PresidentialPardonForm();

        virtual void sign(Bureaucrat &b);
        virtual void execute(Bureaucrat const &b) const;
        
} ;

#endif