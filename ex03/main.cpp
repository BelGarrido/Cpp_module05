#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    std::srand(std::time(NULL));
    std::string target = "Fooo";

    std::cout << std::endl;

    //------------------------------------------------------------------------------------------------------------------

    std::cout << MAGENTA
              << "*´¯`*..*´¯`* [ F1: ShrubberyCreation ] *´¯`*..*´¯`* "
              << RESET << std::endl;

    try {
        ShrubberyCreationForm SC(target);
        Bureaucrat intern("Intern", 150);

        std::cout << MAGENTA << "-> Execute with no sign = FAILURE\n" << RESET;
        intern.executeForm(SC);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        ShrubberyCreationForm SC(target);
        Bureaucrat intern("Intern", 150);

        std::cout << MAGENTA << "-> Sign with low grade = FAILURE\n" << RESET;
        intern.signForm(SC);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        ShrubberyCreationForm SC(target);
        Bureaucrat manager("Manager", 100);

        std::cout << MAGENTA << "-> Sign = SUCCESS\n" << RESET;
        manager.signForm(SC);

        std::cout << MAGENTA << "-> Execute with low grade = FAILURE\n" << RESET;
        Bureaucrat lowExec("LowExec", 150);
        lowExec.executeForm(SC);

        std::cout << MAGENTA << "-> Execute = SUCCESS\n" << RESET;
        manager.executeForm(SC);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    //------------------------------------------------------------------------------------------------------------------

    std::cout << YELLOW
              << "*´¯`*..*´¯`* [ F2: RobotomyRequest ] *´¯`*..*´¯`* "
              << RESET << std::endl;

    try {
        RobotomyRequestForm RR(target);
        Bureaucrat boss("Boss", 45);

        std::cout << YELLOW << "-> Sign\n" << RESET;
        boss.signForm(RR);

        std::cout << YELLOW
                  << "-> Execute several times to check randomness\n"
                  << RESET;

        for (int i = 0; i < 3; i++)
            boss.executeForm(RR);

        std::cout << YELLOW << "-> Execute with low grade = FAILURE\n" << RESET;
        Bureaucrat low("Low", 150);
        low.executeForm(RR);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

//------------------------------------------------------------------------------------------------------------------

    std::cout << CYAN
              << "*´¯`*..*´¯`* [ F3: PresidentialPardon ] *´¯`*..*´¯`* "
              << RESET << std::endl;

    try {
        PresidentialPardonForm PP(target);
        Bureaucrat ceo("CEO", 6);

        std::cout << CYAN << "-> Execute with no sign = FAILURE\n" << RESET;
        ceo.executeForm(PP);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        PresidentialPardonForm PP(target);
        Bureaucrat ceo("CEO", 6);

        std::cout << CYAN << "-> Sign\n" << RESET;
        ceo.signForm(PP);

        std::cout << CYAN << "-> Execute with low grade = FAILURE\n" << RESET;
        ceo.executeForm(PP);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        PresidentialPardonForm PP(target);
        Bureaucrat supreme("Supreme CEO", 1);

        std::cout << CYAN << "-> Execute = SUCCESS\n" << RESET;
        supreme.signForm(PP);
        supreme.executeForm(PP);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    
    //------------------------------------------------------------------------------------------------------------------

    std::cout << GREEN
            << "*´¯`*..*´¯`* [ F4: Intern Factory ] *´¯`*..*´¯`* "
            << RESET << std::endl;

    try
    {
        Bureaucrat ceo("CEO", 1);
        Intern someRandomIntern;

        std::cout << GREEN << "-> Intern creates PresidentialPardonForm\n" << RESET;
        AForm* form = someRandomIntern.makeForm("presidential pardon", "Bender");

        if (form)
        {
            std::cout << GREEN << "-> Sign = SUCCESS\n" << RESET;
            ceo.signForm(*form);

            std::cout << GREEN << "-> Execute = SUCCESS\n" << RESET;
            ceo.executeForm(*form);

            delete form;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << WHITE
              << "*´¯`*..*´¯`* [ End ] *´¯`*..*´¯`* "
              << RESET << std::endl;

    return 0;
}
