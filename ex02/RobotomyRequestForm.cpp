#include "RobotomyRequestForm.hpp"

//default constructor(?)

RobotomyRequest::RobotomyRequest(std::string &target): AForm("RobotomyRequest", 72, 45) {
    _target = target;
    std::cout << "RobotomyRequest has been created with it's constructor with a target: " << _target << std::endl;
    /* std::string fileName = target + "_shrubbery.txt";
    std::ofstream NewFile(fileName.c_str());
    NewFile << "Something";
    NewFile.close(); */
}

RobotomyRequest::RobotomyRequest(const RobotomyRequest &original) : AForm(original) {}

//necesito repasar los asignadores de copia de este ejercicio y los anteriores
/* RobotomyRequest &RobotomyRequest::operator=(const RobotomyRequest &original) {
    AForm::operator=(original);
    return *this;
} */

RobotomyRequest::~RobotomyRequest() {
    std::cout << GREEN << "RobotomyRequest Form destroyed" << RESET << std::endl;
}

bool RobotomyRequest::beSigned(Bureaucrat &b) {
    int sgnGrade = this->getSgnGrade();
    if (b.getGrade() <= sgnGrade) {
        this->toSign();
        std::cout << b << " signed " << this->getName() << std::endl;
        return true;
    }
    std::cout << b << " couldn’t sign " << this->getName() << " because " << "grade is too low" << std::endl;
    throw GradeTooLowException();
}


bool RobotomyRequest::beExecuted(Bureaucrat &b) {
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
