#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "colors.hpp"

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;

        //______________________ DEFAULT_CONSTRUCTOR__

        Bureaucrat();

    public:

        //___________________ PARAMETIZED_CONSTRUCTOR__

        Bureaucrat(std::string const &name, int grade);

        //_______________________________________COPY__

        Bureaucrat(const Bureaucrat &original);
        Bureaucrat &operator=(const Bureaucrat &original);

        //_________________________________DESTRUCTOR__

        virtual ~Bureaucrat();

        //____________________________________GETTERS__

        std::string getName() const;
        int getGrade() const;

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

        //________________________OTHER_MEMEBERS_FT__

        void increment();
        void decrement();
        void signForm();
        
        void print(const std::string &message) const;    
} ;

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureau);

#endif