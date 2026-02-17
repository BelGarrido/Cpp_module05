#include "Bureaucrat.hpp"

int main()
{
    /* try {
        Bureaucrat b1("Intern", 0);
        Bureaucrat b2("Outsider", 2);
        Bureaucrat b3("Manager", 60);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    } */
 
    std::cout << BLUE << "*´¯`*..*´¯`* [ B1: Intern ] *´¯`*..*´¯`* " << RESET << std::endl;    
    try {
        Bureaucrat b1("Intern", 149);
        Form f1("form 1", 148, 130);
        b1.increment();
        b1.signForm(f1);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << BLUE << "*´¯`*..*´¯`* [ B2: Outsider ] *´¯`*..*´¯`* " << RESET << std::endl;
    try {
        Bureaucrat b2("Outsider", 151);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << BLUE << "*´¯`*..*´¯`* [ B3: Manager ] *´¯`*..*´¯`* " << RESET << std::endl;
    try {
        Bureaucrat b3("Manager", 60);
        b3.decrement();
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << BLUE << "*´¯`*..*´¯`* [ B4 and B5: Boss and Fake boss ] *´¯`*..*´¯`* " << RESET << std::endl;
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
    

    std::cout << std::endl;
     

    return 0;
}
