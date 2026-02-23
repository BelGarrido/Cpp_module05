#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern : public Bureaucrat {
    private:
    public:
        AForm* makeForm(std::string &formName, std::string &target);
};

#endif