#include "PresidentialPardonForm.hpp"

//default constructor(?)

PresidentialPardon::PresidentialPardon(const std::string &target): AForm("PresidentialPardon", 25, 5) {
    _target = target;
    std::cout << "PresidentialPardon has been created with it's constructor with a target: " << _target << std::endl;
    /* std::string fileName = target + "_shrubbery.txt";
    std::ofstream NewFile(fileName.c_str());
    NewFile << "Something";
    NewFile.close(); */
}

PresidentialPardon::PresidentialPardon(const PresidentialPardon &original) : AForm(original) {}

//necesito repasar los asignadores de copia de este ejercicio y los anteriores
/* PresidentialPardon &PresidentialPardon::operator=(const PresidentialPardon &original) {
    AForm::operator=(original);
    return *this;
} */

PresidentialPardon::~PresidentialPardon() {
    std::cout << GREEN << "PresidentialPardon Form destroyed" << RESET << std::endl;
}

bool PresidentialPardon::beSigned(Bureaucrat &b) {
    int sgnGrade = this->getSgnGrade();
    if (b.getGrade() <= sgnGrade) {
        this->toSign();
        std::cout << b << " signed " << this->getName() << std::endl;
        return true;
    }
    std::cout << b << " couldn’t sign " << this->getName() << " because " << "grade is too low" << std::endl;
    throw GradeTooLowException();
}


bool PresidentialPardon::beExecuted(Bureaucrat &b) {
    int excGrade = this->getExcGrade();
    if(b.getGrade() <= excGrade) {
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
        return true;
    }
    std::cout << b << " couldn’t execute " << this->getName() << " because " << "grade is too low" << std::endl;
    throw GradeTooLowException();    
}
