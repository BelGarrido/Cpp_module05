#include "Bureaucrat.hpp"

//______________________ DEFAULT_CONSTRUCTOR__

Bureaucrat::Bureaucrat()
    :_name("Just another bureaucrat"),
    _grade(150) {
    std::cout << MAGENTA << _name << " created with parametized constructor" << std::endl;
}

//___________________ PARAMETIZED_CONSTRUCTOR__

Bureaucrat::Bureaucrat(std::string const &name, int grade)
    :_name(name) {
    validGrade(grade);
    _grade = grade;
    print("created with parametized constructor");
}

//_________________________________DESTRUCTOR__

Bureaucrat::~Bureaucrat() {
    print("left the terminal");
}

//_______________________________________COPY__

Bureaucrat::Bureaucrat(const Bureaucrat &original)
    :_name(original._name),
    _grade(original._grade) {
    print("cloned with copy constructor");
}

// Name is const, so only grade can be reassigned
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &original) {
    if (this != &original)
        this->_grade = original._grade;
    print("using copy assigment");
    return *this;
}

//____________________________________GETTERS__

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

//________________________________EXCEPTIONS__

void Bureaucrat::validGrade(int grade) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "EXCEPTION(bureaucrat)!: Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "EXCEPTION(bureaucrat)!: Grade is too low";
}

//________________________OTHER_MEMEBERS_FT__

void Bureaucrat::decrement() {
    int grade = _grade;
    grade++;
    validGrade(grade);
    _grade = grade; 
    print("grade -");

}

void Bureaucrat::increment() {
    int grade = _grade;
    grade--;
    validGrade(grade);
    _grade = grade; 
    print("grade +");
}

void Bureaucrat::signForm(AForm &f) {
    f.beSigned(*this);
}

void Bureaucrat::executeForm(AForm &f) {
    f.beExecuted(*this);
}

//_____________________________INSERTION__

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureau) {
  output << bureau.getName();
  output << ", bureaucrat grade ";
  output << bureau.getGrade();
  return output;
}

void Bureaucrat::print(const std::string &message) const {
    std::cout << MAGENTA << *this << " " << message << RESET << std::endl;
}
