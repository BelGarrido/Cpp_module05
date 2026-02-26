#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequest", 72, 45) {
    _target = target;
    std::cout << "RobotomyRequest has been created with it's constructor with a target: " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &original) : AForm(original) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &original) {
    AForm::operator=(original);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequest Form left the terminal" << std::endl;
}

bool RobotomyRequestForm::sign(Bureaucrat &b) {
    int sgnGrade = this->getSgnGrade();
    if (b.getGrade() <= sgnGrade) {
        this->toSign();
        return true;
    }
    std::cout << b << " couldn’t sign " << this->getName() << " because " << "grade is too low" << std::endl;
    throw GradeTooLowException();
}


bool RobotomyRequestForm::execute(Bureaucrat const &b) const {
    int excGrade = this->getExcGrade();
    if(b.getGrade() <= excGrade) {
        std::cout << b << " Grrrrrr..Drrrrrr..Trtrtrtr...Ratatatat...GRRRRKKK" << std::endl;
        if(std::rand() % 2 == 0)
            std::cout << _target << " has been robotomized" << std::endl;
        else
            std::cout << _target << " could not be robotomized" << std::endl;
        std::cout << b << " executed " << this->getName() << std::endl;
        return true;
    }
    std::cout << b << " couldn’t execute " << this->getName() << " because " << "grade is too low" << std::endl;
    throw GradeTooLowException();    
}
