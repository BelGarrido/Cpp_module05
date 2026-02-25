#include "Bureaucrat.hpp"

int main()
{
    std::cout << BLUE << "\n" << "*´¯`*..*´¯`* [ VALID FORM CREATION ] *´¯`*..*´¯`* " << RESET << std::endl;    
    try {
        Bureaucrat b1("Intern", 149);
        Form f1("form 1", 148, 130);
        b1.increment();
        b1.signForm(f1);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << BLUE << "\n" << "*´¯`*..*´¯`* [ INVALID FORM: TOO HIGH GRADE ] *´¯`*..*´¯`* " << RESET << std::endl;
    try {
        Bureaucrat b2("Outsider", 151);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << BLUE << "\n" << "*´¯`*..*´¯`* [ INVALID FORM: TOO LOW GRADE ] *´¯`*..*´¯`* " << RESET << std::endl;
    try {
        Bureaucrat b3("Manager", 60);
        Form f3("form 3", 3, 1);
        b3.decrement();
        b3.signForm(f3);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << BLUE << "\n" << "*´¯`*..*´¯`* [ IGNING FORM SUCCESS & FAILURE ] *´¯`*..*´¯`* " << RESET << std::endl;
    try {
        Bureaucrat b4("Boss", 1);
        Bureaucrat b5("Fake Boss", 150);
        b5 = b4;
        //b5.print("copy with operator =");
        b4.increment();
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
