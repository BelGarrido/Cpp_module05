#include "Bureaucrat.hpp"
#include "Intern.hpp"


int main()
{
    std::srand(std::time(NULL));
    std::cout << MAGENTA << "*´¯`*..*´¯`* [ F1: ShrubberyCreation ] *´¯`*..*´¯`* " << RESET << std::endl;    
    Bureaucrat *b1;
    Bureaucrat *b2;
    Bureaucrat *b3;
    AForm *f1;
    AForm *f2;
    AForm *f3;

    std::string target = "Fooo";
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
        b1 = new Bureaucrat("Intern", 178);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << WHITE << "*´¯`*..*´¯`* [ F2: RobotomyRequest ] *´¯`*..*´¯`* " << RESET << std::endl;    
    try {
        f2 = new RobotomyRequest(target);
        b2 = new Bureaucrat("Boss", 10);
        b2->decrement();
        b2->signForm(*f2);
        b2->executeForm(*f2);
        b1->executeForm(*f2);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << WHITE << "*´¯`*..*´¯`* [ F3: PresidentialPardon ] *´¯`*..*´¯`* " << RESET << std::endl;        
    try {
        f3 = new PresidentialPardon(target);
        b3 = new Bureaucrat("CEO", 1);
        b3->decrement();
        b3->signForm(*f3);
        b3->executeForm(*f3);
        b1->executeForm(*f3);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << WHITE << "*´¯`*..*´¯`* [ F4: makeForm ] *´¯`*..*´¯`* " << RESET << std::endl; 
    try {
        b3 = new Bureaucrat("CEO", 1);
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("f pardon", "Bender");
        if(rrf)
            b3->signForm(*rrf);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
