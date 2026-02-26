#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardon", 25, 5) {
    _target = target;
    std::cout << "PresidentialPardon has been created with it's constructor with a target: " << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &original) : AForm(original) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &original) {
    AForm::operator=(original);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardon Form left the terminal" << std::endl;
}

bool PresidentialPardonForm::sign(Bureaucrat &b) {
    int sgnGrade = this->getSgnGrade();
    if (b.getGrade() <= sgnGrade) {
        this->toSign();
        std::cout << b << " signed " << this->getName() << std::endl;
        return true;
    }
    std::cout << b << " couldn’t sign " << this->getName() << " because " << "grade is too low" << std::endl;
    throw GradeTooLowException();
}


bool PresidentialPardonForm::execute(Bureaucrat const &b) const {
    int excGrade = this->getExcGrade();
    if(b.getGrade() <= excGrade) {
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
        return true;
    }
    std::cout << b << " couldn’t execute " << this->getName() << " because " << "grade is too low" << std::endl;
    throw GradeTooLowException();    
}
