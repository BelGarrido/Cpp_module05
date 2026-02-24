#ifndef PRESIDENTIAL_HPP
#define PRESIDENTIAL_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

class PresidentialPardon: public AForm {
    private:
        std::string _target;

    public:
        PresidentialPardon();
        PresidentialPardon(const std::string &target);
        PresidentialPardon(const PresidentialPardon &original);
        //no se hacerlo, se me ocurre llamar al constructor de Aform en el cosntructor de SC y hay settear los artibutos (?)
        
        //tengo que checkear las copias
        PresidentialPardon &operator=(const PresidentialPardon &original);
        ~PresidentialPardon();

        virtual bool beSigned(Bureaucrat &b);
        virtual bool beExecuted(Bureaucrat &b);
} ;

#endif