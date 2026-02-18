#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include "Form.hpp"

class ShrubberyCreation: public AForm {
    private:

    public:
        ShrubberyCreation();
        ShrubberyCreation(std::string &target);
        //no se hacerlo, se me ocurre llamar al constructor de Aform en el cosntructor de SC y hay settear los artibutos (?)
        ShrubberyCreation &operator=(const ShrubberyCreation &original);
        ~ShrubberyCreation();

} ;


#endif