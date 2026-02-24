#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

class ShrubberyCreation: public AForm {
    private:
        std::string _target;

    public:
        ShrubberyCreation();
        ShrubberyCreation(const std::string &target);
        ShrubberyCreation(const ShrubberyCreation &original);
        //no se hacerlo, se me ocurre llamar al constructor de Aform en el cosntructor de SC y hay settear los artibutos (?)
        
        //tengo que checkear las copias
        ShrubberyCreation &operator=(const ShrubberyCreation &original);
        ~ShrubberyCreation();

        virtual bool beSigned(Bureaucrat &b);
        virtual bool beExecuted(Bureaucrat &b);
} ;


#endif