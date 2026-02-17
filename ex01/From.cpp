#include "Form.hpp"

//______________________ DEFAULT_CONSTRUCTOR__

Form::Form()
    :_name("Just another bureaucrat"),
    _sgnGrade(150),
    _excGrade(150),
    _isSigned(false)
{
    std::cout << _name << " created with parametized constructor" << std::endl;
}

//___________________ PARAMETIZED_CONSTRUCTOR__

Form::Form(std::string const &name, int sgnGrade, int excGrade)
    :_name(name),
    _sgnGrade(sgnGrade),
    _excGrade(excGrade),
    _isSigned(false)
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
Form& Form::operator=(const Form &original) {
    if (this != &original)
        this->_grade = original._grade;
    print("using copy assigment");
    return *this;
}

void Form::validGrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
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

void Form::print(const std::string &message) const {
    std::cout << WHITE << *this << " " << message << RESET << std::endl;
}