#ifndef ROBOTOMY_HPP
#define ROBOTOMY_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

class RobotomyRequest: public AForm {
    private:
        std::string _target;

    public:
        RobotomyRequest();
        RobotomyRequest(std::string &target);
        RobotomyRequest(const RobotomyRequest &original);
        //no se hacerlo, se me ocurre llamar al constructor de Aform en el cosntructor de SC y hay settear los artibutos (?)
        
        //tengo que checkear las copias
        RobotomyRequest &operator=(const RobotomyRequest &original);
        ~RobotomyRequest();

        virtual bool beSigned(Bureaucrat &b);
        virtual bool beExecuted(Bureaucrat &b);
} ;

#endif