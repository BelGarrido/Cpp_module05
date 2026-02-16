#include "Bureaucrat.hpp"

int main()
{


    try {
        Bureaucrat b1("Intern", 0);
        Bureaucrat b2("Outsider", 2);
        Bureaucrat b3("Manager", 60);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
/* 
    std::cout << "\033[1;96m" << "*´¯`*..*´¯`* [ Test Construction ] *´¯`*..*´¯`* " << "\033[0m" << std::endl; 
    try {
        Bureaucrat b1("Intern", 149);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Outsider", 151);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Manager", 60);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("Boss", 1);
        b4.increment();
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    } */
  
    std::cout << std::endl;
    std::cout << BLUE << "*´¯`*..*´¯`* [ Test Copy and Copy Assigment ] *´¯`*..*´¯`* " << RESET << std::endl; 

    return 0;
}
