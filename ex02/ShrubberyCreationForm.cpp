#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreation", 145, 137) {
    _target = target;
    std::cout << "ShrubberyCreation has been created with it's constructor with a target: " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &original) : AForm(original) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &original) {
    AForm::operator=(original);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreation Form left the terminal" << std::endl;
}

bool ShrubberyCreationForm::sign(Bureaucrat &b) {
    int sgnGrade = this->getSgnGrade();
    if (b.getGrade() <= sgnGrade) {
        this->toSign();
        std::cout << b << " signed " << this->getName() << std::endl;
        return true;
    }
    std::cout << b << " couldn’t sign " << this->getName() << " because " << "grade is too low" << std::endl;
    throw GradeTooLowException();
}


bool ShrubberyCreationForm::execute(Bureaucrat const &b) const {
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
