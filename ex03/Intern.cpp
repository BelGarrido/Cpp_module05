#include "Intern.hpp"
#include <functional>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
//______________________ DEFAULT_CONSTRUCTOR__

Intern::Intern()
{
    print("created with default constructor");
}

//_________________________________DESTRUCTOR__

Intern::~Intern() {
    print("left the terminal");
}

std::string toUpperCase(std::string s){
    for (size_t i = 0; i < s.length(); i++) {
        s[i] = std::toupper(static_cast<unsigned char>(s[i]));
    }
    return s;
}

AForm *robotomyPtr(std::string &target) {
    std::cout << "robotomy constructor: " << target << std::endl;
    AForm *f = new RobotomyRequest(target);
    return f;
}

AForm *presidentialPtr(std::string &target) {
    std::cout << "presidential constructor: " << target << std::endl;
    AForm *f = new PresidentialPardon(target);
    return f;
}

AForm *shrubberyPtr(std::string &target) {
    std::cout << "shrubbery constructor: " << target << std::endl;
    AForm *f = new ShrubberyCreation(target);
    return f;
}

AForm* Intern::makeForm(const std::string &name, const std::string &target) {
    AForm *newForm = NULL;
    std::string argm = target;
    std::cout << "we are in the function make form " << target << std::endl;
    //normalizar a mayusculas
    std::string names[3] = {"ROBOTOMY REQUEST", "PRESIDENTIAL PARDON", "SHRUBBERY CREATION"};
    AForm *(*fPtr[])(std::string&) = {robotomyPtr, presidentialPtr, shrubberyPtr};
    std::string normName = toUpperCase(name);
    std::cout << normName << std::endl;
    int i = 0;
    while(names[i] && (names[i].compare(normName) != 0)){
        i++;
    }
    if(names[0].compare(normName) == 0)
        newForm = fPtr[0](argm);
    else if(names[1].compare(normName) == 0)
        newForm = fPtr[1](argm);
    else if(names[2].compare(normName) == 0)
        newForm = fPtr[2](argm);
    else
        print("does not know what are you talking about");
    return newForm; 
}


void Intern::print(const std::string &message) const {
    std::cout << RED << "Intern " << message << RESET << std::endl;
}

