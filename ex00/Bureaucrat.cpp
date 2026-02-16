#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    :_name("Just another bureaucrat"),
    _grade(150)
{
    std::cout << _name << " created with parametized constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade)
    :_name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    
    _grade = grade;
    std::cout << "Bureaucrat " << _name << " created with parametized constructor" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat left the terminal" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &original)
    :_name(original._name),
    _grade(original._grade)
{
    print(" cloned with copy constructor");
}

// the =operator is implemented however the name doesnt change because it was defined as const string 
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &original) {
    if (this != &original && validGrade(original._grade))
    {
        this->_grade = original._grade;
    }
    else
        std::cout << "Bureaucrat can not be created" << std::endl;
        // problemaaaaaaaaaas, no deberia crearse
    print(" using copy assigment");
    return *this;
}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::print(const std::string &message) const {
    std::cout << message << std::endl;
}

// puede que no tenga que ser una member function
bool Bureaucrat::validGrade(int grade)
{
    if (grade <= 150 && grade >= 1)
        return true;
    return false;
}

void Bureaucrat::decrement()
{
    int grade = _grade;
    grade++;
    if (grade > 150)
        throw GradeTooLowException();
    else
        _grade = grade; 
}
void Bureaucrat::increment()
{
    int grade = _grade;
    grade--;
    if (grade < 1) {
        std::cout << "Increment is imposible: ";
        throw GradeTooHighException();
    }
    else
        _grade = grade; 
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureau) {
  output << bureau.getName();
  output << ", bureaucrat grade ";
  output << bureau.getGrade();
  return output;
}

const char*  Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char*  Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}
