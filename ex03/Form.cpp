#include "Form.hpp"
#include "Bureaucrat.hpp"

//______________________ DEFAULT_CONSTRUCTOR__

AForm::AForm()
    :_name("Just another bureaucrat"),
    _isSigned(false),
    _sgnGrade(150),
    _excGrade(150)
{
    print("created with default constructor");
    //std::cout << _name << " created with default constructor" << std::endl;
}

//___________________ PARAMETIZED_CONSTRUCTOR__

AForm::AForm(std::string const &name, int sgnGrade, int excGrade)
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

AForm::~AForm() {
    print("left the terminal");
}

//_______________________________________COPY__

AForm::AForm(const AForm &original)
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

void AForm::validGrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}
const char*  AForm::GradeTooHighException::what() const throw() {
    return "EXEPTION!: Grade is too high";
}

const char*  AForm::GradeTooLowException::what() const throw() {
    return "EXEPTION!: Grade is too low";
}

//____________________________________GETTERS__

std::string AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _isSigned;
}

int AForm::getSgnGrade() const {
    return _sgnGrade;
}

int AForm::getExcGrade() const {
    return _excGrade;
}

std::ostream& operator<<(std::ostream& output, const AForm& f) {
  output << f.getName();
  output << ", with sign grade of ";
  output << f.getSgnGrade();
  output << " and execution grade of ";
  output << f.getExcGrade();
  return output;
}

bool AForm::beSigned(Bureaucrat &b) {
    if (b.getGrade() <= _sgnGrade) {
        toSign();
        std::cout << YELLOW << b << " signed " << this->getName() << RESET << std::endl;
        return true;
    }
    
    std::cout << b << " couldn’t sign "<< this->getName() << " because " << "grade is too low" << std::endl;
    throw GradeTooLowException();
}

bool AForm::beExecuted(Bureaucrat &b) {
    if(b.getGrade() <= _excGrade) {
        print("executed");
        return true;
    }
    std::cout << b << " couldn’t be executed " << this->getName() << " because " << "grade is too low" << std::endl;
    throw GradeTooLowException();   
}


void AForm::toSign() {
    print("signed");
    _isSigned = true;
}

void AForm::print(const std::string &message) const {
    std::cout << CYAN << *this << " " << message << RESET << std::endl;
}
