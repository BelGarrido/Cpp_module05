#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
//#include <ctime>
#include "../colors.hpp"
//#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private: 
        const std::string _name;
        bool _isSigned;
        const int _sgnGrade;
        const int _excGrade;

        // DEFAULT_CONSTRUCTOR
        AForm();

    public:
        // PARAMETIZED_CONSTRUCTOR
        AForm(std::string const &name, int sgnGrade, int excGrade);

        // COPY
        AForm(const AForm &original);
        AForm& operator=(const AForm &original);    

        // DESTRUCTOR
        virtual ~AForm();
        
        // EXCEPTIONS
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

        // OTHER_MEMEBERS_FT
        //Lo que hace virtual es permitir binding dinámico cuando usas punteros o referencias a la clase base.
        virtual bool sign(Bureaucrat &b) = 0;
        virtual bool execute(Bureaucrat const &b) const = 0;
} ;

std::ostream& operator<<(std::ostream& output, const AForm& f);

#endif