#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    
    public:
        
        //___________________ PARAMETIZED_CONSTRUCTOR__
        Intern();
        //_______________________________________COPY__
        Intern(const Intern &original);
        Intern &operator=(const Intern &original);

        //_________________________________DESTRUCTOR__
        virtual ~Intern();
        AForm* makeForm(const std::string &formName, const std::string &target);
        void print(const std::string &message) const;
        
    private:
        static const int FORM_COUNT = 3;
        static std::string names[FORM_COUNT];
        static AForm *(*fPtr[FORM_COUNT])(const std::string&);
};


#endif