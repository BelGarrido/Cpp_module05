#include "Intern.hpp"
#include <functional>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

std::string toUpperCase(std::string s);

//_________________________ FACTORY_FUNCTIONS__

AForm *robotomyPtr(const std::string &target) {
    std::cout << "robotomy constructor: " << target << std::endl;
    return new RobotomyRequest(target);
}

AForm *presidentialPtr(const std::string &target) {
    std::cout << "presidential constructor: " << target << std::endl;
    return new PresidentialPardon(target);
}

AForm *shrubberyPtr(const std::string &target) {
    std::cout << "shrubbery constructor: " << target << std::endl;
    return new ShrubberyCreation(target);
}

//_________________ STATIC_ARRAYS_DEFINITIONS__

std::string Intern::names[Intern::FORM_COUNT] = {
    "ROBOTOMY REQUEST",
    "PRESIDENTIAL PARDON",
    "SHRUBBERY CREATION"
};
AForm* (*Intern::fPtr[Intern::FORM_COUNT])(const std::string&) = {
    &robotomyPtr,
    &presidentialPtr,
    &shrubberyPtr
};

//______________________ DEFAULT_CONSTRUCTOR__

Intern::Intern() {
    print("created with default constructor");
}

//_________________________________DESTRUCTOR__

Intern::~Intern() {
    print("left the terminal");
}

AForm* Intern::makeForm(const std::string &name, const std::string &target) {
    AForm *newForm = NULL;
    int i = 0;
    std::string argm = target;
    
    std::cout << "we are in the function make form " << target << std::endl;
    std::string normName = toUpperCase(name);
    std::cout << normName << std::endl;
    
    while(i < 3 && (names[i].compare(normName) != 0)){
        i++;
    }

    if(names[i].compare(normName) == 0)
        newForm = fPtr[i](argm);
    else
        print("does not know what are you talking about");
    
    return newForm; 
}

void Intern::print(const std::string &message) const {
    std::cout << RED << "Intern " << message << RESET << std::endl;
}

std::string toUpperCase(std::string s){
    for (size_t i = 0; i < s.length(); i++) {
        s[i] = std::toupper(static_cast<unsigned char>(s[i]));
    }
    return s;
}