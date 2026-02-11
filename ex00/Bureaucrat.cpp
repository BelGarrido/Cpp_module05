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
    if (validGrade(grade))
        _grade = grade;
    else
        std::cout << RED << "Bureaucrat can not be created" << RESET << std::endl;
        // problemaaaaaaaaaas, no deberia crearse
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
    if(validGrade(grade))
        _grade++;
    else
        ;
        //problemas
}
void Bureaucrat::increment()
{
    int grade = _grade;
    grade--;
    if(validGrade(grade))
        _grade--;
    else
        std::cout << "Bureaucrat can not be created" << std::endl;
        // problemas
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureau) {
  // Convert fixed-point number to float and insert into the stream
  output << bureau.getName();
  output << ", bureaucrat grade ";
  output << bureau.getGrade();
  return output;
}
