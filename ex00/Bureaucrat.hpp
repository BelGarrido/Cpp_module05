#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

#include "colors.hpp"

class Bureaucrat {
    protected:
        const std::string _name;
        int _grade;

        Bureaucrat();

    public:
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(const Bureaucrat &original);
        Bureaucrat &operator=(const Bureaucrat &original);
        virtual ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;

        bool validGrade(int grade);
        void increment();
        void decrement();

        void print(const std::string &message) const;
} ;


std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureau);

#endif