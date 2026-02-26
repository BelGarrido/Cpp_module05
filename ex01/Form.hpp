#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "../colors.hpp"

//#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private: 
        const std::string _name;
        bool _isSigned;
        const int _sgnGrade;
        const int _excGrade;

        // DEFAULT_CONSTRUCTOR
        Form();

    public:
                
        // PARAMETIZED_CONSTRUCTOR
        Form(const Form &original);

        // COPY
        Form(std::string const &name, int sgnGrade, int excGrade);
        Form& operator=(const Form &original);

        // DESTRUCTOR
        ~Form();

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

        // OTHER_MEMEBERS_FT
        bool sign(Bureaucrat &b);
        void print(const std::string &message) const;
} ;

std::ostream& operator<<(std::ostream& output, const Form& f);

#endif