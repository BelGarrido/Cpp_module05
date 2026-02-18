#include "Bureaucrat.hpp"

int main()
{
    std::cout << BLUE << "*´¯`*..*´¯`* [ B1: Intern ] *´¯`*..*´¯`* " << RESET << std::endl;    
    Bureaucrat *b1;
    Form *f1;
    try {
        b1 = new Bureaucrat("Intern", 149);
        f1 = new Form("form 1", 148, 130);
        b1->increment();
        b1->signForm(*f1);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }



    return 0;
}
