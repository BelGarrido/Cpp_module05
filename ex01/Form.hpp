#ifndef FORM_HPP
#define FROM_HPP

#include <string>
#include <iostream>
#include "colors.hpp"
#include "Bureaucrat.hpp"


class Form {
    private: 
        const std::string _name;
        bool _isSigned = false;
        const int _sgnGrade;
        const int _excGrade;
        Form();

    public:

        Form(const Form &original);
        Form::Form(std::string const &name, int sgnGrade, int excGrade);
        Form& operator=(const Form &original);
        Form::~Form();
        bool beSigned(Bureaucrat &b);

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
        
        void print(const std::string &message) const;
} ;


#endif