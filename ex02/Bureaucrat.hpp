#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "../colors.hpp"
#include "Form.hpp"

class Bureaucrat {
    
    private:
        const std::string _name;
        int _grade;

        // DEFAULT_CONSTRUCTOR

        Bureaucrat();

    public:

        // PARAMETIZED_CONSTRUCTOR

        Bureaucrat(std::string const &name, int grade);

        // COPY

        Bureaucrat(const Bureaucrat &original);
        Bureaucrat &operator=(const Bureaucrat &original);

        // DESTRUCTOR

        virtual ~Bureaucrat();

        // GETTERS

        std::string getName() const;
        int getGrade() const;

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

        // OTHER_MEMEBERS_FT

        void increment();
        void decrement();
        void signForm(AForm &f);
        void executeForm(AForm &f);
        
        void print(const std::string &message) const;    
} ;

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureau);

#endif