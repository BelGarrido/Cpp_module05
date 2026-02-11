#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\033[1;96m" << "*´¯`*..*´¯`* [ Test Construction ] *´¯`*..*´¯`* " << "\033[0m" << std::endl; 
    Bureaucrat b1("Intern", 149);
    Bureaucrat b2("Outsider", 151);
    Bureaucrat b3("Manager", 60);
    Bureaucrat b4("Boss", 0);
    std::cout << std::endl;
    std::cout << BLUE << "*´¯`*..*´¯`* [ Test Copy and Copy Assigment ] *´¯`*..*´¯`* " << RESET << std::endl; 
    
    std::cout << b1 << " Before increment" << std::endl;
    b1.decrement();
    std::cout << b1 << " After increment" << std::endl;
    
    return 0;
}

/* try - defines the code to test
throw - triggers an exception
catch - handles the error */