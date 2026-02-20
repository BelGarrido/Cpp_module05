#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "colors.hpp"
//#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private: 
        const std::string _name;
        bool _isSigned;
        const int _sgnGrade;
        const int _excGrade;
        AForm();

    public:
        AForm(std::string const &name, int sgnGrade, int excGrade);
        AForm(const AForm &original);
        AForm& operator=(const AForm &original);
        //Lo que hace virtual es permitir binding dinámico cuando usas punteros o referencias a la clase base.
        virtual ~AForm();
        virtual bool beSigned(Bureaucrat &b) = 0;
        virtual bool beExecuted(Bureaucrat &b) = 0;

        //_________________________________EXCEPTIONS__

        void validGrade(int grade);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        //GETTERS
        std::string getName() const;
        bool isSigned() const;
        int getSgnGrade() const;
        int getExcGrade() const;

        //SETTERS
        void toSign();
        void print(const std::string &message) const;
} ;


#endif