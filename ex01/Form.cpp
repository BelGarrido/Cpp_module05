#include "Form.hpp"
#include "Bureaucrat.hpp"

//______________________ DEFAULT_CONSTRUCTOR__

Form::Form()
    :_name("Just another bureaucrat"),
    _isSigned(false),
    _sgnGrade(150),
    _excGrade(150)
{
    std::cout << _name << " created with default constructor" << std::endl;
}

//___________________ PARAMETIZED_CONSTRUCTOR__

Form::Form(std::string const &name, int sgnGrade, int excGrade)
    :_name(name),
    _isSigned(false),
    _sgnGrade(sgnGrade),
    _excGrade(excGrade)

{
    validGrade(_sgnGrade);
    validGrade(_excGrade);
    print("created with parametized constructor");
}

//_________________________________DESTRUCTOR__

Form::~Form() {
    print("left the terminal");
}

//_______________________________________COPY__

Form::Form(const Form &original)
    :_name(original._name),
    _isSigned(original._isSigned),
    _sgnGrade(original._sgnGrade),
    _excGrade(original._excGrade)
{
    print("cloned with copy constructor");
}

// the =operator is implemented however the name doesnt change because it was defined as const string 
/* Form& Form::operator=(const Form &original) {
    if (this != &original)
        this->_grade = original._grade;
    print("using copy assigment");
    return *this;
} */

void Form::validGrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}
const char*  Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char*  Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

//____________________________________GETTERS__

std::string Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _isSigned;
}

int Form::getSgnGrade() const {
    return _sgnGrade;
}

int Form::getExcGrade() const {
    return _excGrade;
}

std::ostream& operator<<(std::ostream& output, const Form& f) {
  output << f.getName();
  output << ", with sign grade of ";
  output << f.getSgnGrade();
  output << " and execution grade of ";
  output << f.getExcGrade();
  return output;
}

bool Form::beSigned(Bureaucrat &b) {
    if (b.getGrade() <= _sgnGrade) {
        _isSigned = true;
       std::cout << b << " signed " << this->getName() << std::endl;
       return true;
    }
    
    std::cout << b << " couldn’t sign  "<< this->getName() << " because " << "grade is too low" << std::endl;
    throw GradeTooLowException();
}


void Form::print(const std::string &message) const {
    std::cout << WHITE << *this << " " << message << RESET << std::endl;
}