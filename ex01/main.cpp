#include "Bureaucrat.hpp"

int main()
{
    std::cout << CYAN << "\n" << "*´¯`*..*´¯`* [ VALID FORM CREATION ] *´¯`*..*´¯`* " << RESET << std::endl;    
    try {
        Form f1("Form 1", 50, 100);
        std::cout << f1 << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << CYAN << "\n" << "*´¯`*..*´¯`* [ INVALID FORM: TOO HIGH GRADE ] *´¯`*..*´¯`* " << RESET << std::endl;
    try {
        Form f2("Form 2", 0, 50);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << CYAN << "\n" << "*´¯`*..*´¯`* [ INVALID FORM: TOO LOW GRADE ] *´¯`*..*´¯`* " << RESET << std::endl;
    try {
        Form f3("Form 3", 50, 151); 
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << CYAN << "\n" << "*´¯`*..*´¯`* [ SIGNING FORM FAILURE ] *´¯`*..*´¯`* " << RESET << std::endl;
    try {
        Bureaucrat b1("Jeff", 53);
        Form f4("Form 4", 50, 100);

        std::cout << f4 << std::endl;
        b1.increment();  // 53 -> 52
        b1.signForm(f4); // FAIL: grade 53 > 50 required
 
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << CYAN << "\n" << "*´¯`*..*´¯`* [ SIGNING FORM SUCCESS ] *´¯`*..*´¯`* " << RESET << std::endl;
    try {
        Bureaucrat b1("Jeff", 50);
        Form f4("Form 4", 50, 100);
        std::cout << f4 << std::endl;
        b1.signForm(f4); // SUCCESS
        b1.signForm(f4); // already signed

    }
        catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
