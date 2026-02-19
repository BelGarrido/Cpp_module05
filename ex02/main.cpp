#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::cout << BLUE << "*´¯`*..*´¯`* [ B1: Intern ] *´¯`*..*´¯`* " << RESET << std::endl;    
    Bureaucrat *b1;
    AForm *f1;
    std::string target = "tree";
    //char *target = "person";
    try {
        //creamos el fomulario SC
        f1 = new ShrubberyCreation(target);
        //creamos el Burocrata
        b1 = new Bureaucrat("Intern", 100);
        //procedemos a firmarlo
        b1->increment();
        b1->signForm(*f1);
        b1->executeForm(*f1);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
