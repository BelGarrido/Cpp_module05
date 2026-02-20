#include "ShrubberyCreationForm.hpp"


//default constructor(?)

ShrubberyCreation::ShrubberyCreation(std::string &target): AForm("ShrubberyCreation", 145, 137) {
    _target = target;
    std::cout << "ShrubberyCreation has been created with it's constructor with a target: " << _target << std::endl;
    /* std::string fileName = target + "_shrubbery.txt";
    std::ofstream NewFile(fileName.c_str());
    NewFile << "Something";
    NewFile.close(); */
}

ShrubberyCreation::ShrubberyCreation(const ShrubberyCreation &original) : AForm(original) {}

//necesito repasar los asignadores de copia de este ejercicio y los anteriores
/* ShrubberyCreation &ShrubberyCreation::operator=(const ShrubberyCreation &original) {
    AForm::operator=(original);
    return *this;
} */

ShrubberyCreation::~ShrubberyCreation() {
    std::cout << GREEN << "ShrubberyCreation Form destroyed" << RESET << std::endl;
}

bool ShrubberyCreation::beSigned(Bureaucrat &b) {
    int sgnGrade = this->getSgnGrade();
    if (b.getGrade() <= sgnGrade) {
        this->toSign();
        std::cout << b << " signed " << this->getName() << std::endl;
        return true;
    }
    std::cout << b << " couldn’t sign " << this->getName() << " because " << "grade is too low" << std::endl;
    throw GradeTooLowException();
}


bool ShrubberyCreation::beExecuted(Bureaucrat &b) {
    int excGrade = this->getExcGrade();
    std::string tree = 
        "             /\\\n"
        "            <  >\n"
        "             \\/\n"
        "             /\\\n"
        "            /  \\\n"
        "           /++++\\\n"
        "          /  ()  \\\n"
        "          /      \\\n"
        "         /~`~`~`~`\\\n"
        "        /  ()  ()  \\\n"
        "        /          \\\n"
        "       /*&*&*&*&*&*&\\\n"
        "      /  ()  ()  ()  \\\n"
        "      /              \\\n"
        "     /++++++++++++++++\\\n"
        "    /  ()  ()  ()  ()  \\\n"
        "    /                  \\\n"
        "   /~`~`~`~`~`~`~`~`~`~`\\\n"
        "  /  ()  ()  ()  ()  ()  \\\n"
        "  /*&*&*&*&*&*&*&*&*&*&*&\\\n"
        " /                        \\\n"
        "/,.,.,.,.,.,.,.,.,.,.,.,.,.\\\n"
        "           |   |\n"
        "          |`````|\n"
        "          \\_____/\n";

    if(b.getGrade() <= excGrade) {
        std::string fileName = _target + "_shrubbery.txt";
        std::ofstream NewFile(fileName.c_str());
        NewFile << tree;
        NewFile.close();
        std::cout << b << " executed " << this->getName() << std::endl;
        return true;
    }
    std::cout << b << " couldn’t execute " << this->getName() << " because " << "grade is too low" << std::endl;
    throw GradeTooLowException();    
}
