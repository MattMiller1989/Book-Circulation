
#include <iostream>

#include "Library.h"
using namespace std;

int main()
{
    
    

    
    Library library;
    library.add_book("Software Engineering");
    library.add_book("Chemistry");
    library.add_employee("Adam");
    library.add_employee("Sam");
    library.add_employee("Ann");
    
    
    
    library.circulate_book("Chemistry", Date(2015, 3, 1, DateFormat::US));
    
    
    library.pass_on("Chemistry", Date(2015, 3, 5, DateFormat::US));
    library.pass_on("Chemistry", Date(2015, 3, 7, DateFormat::US));
    library.pass_on("Chemistry", Date(2015, 3, 15, DateFormat::US));
    library.print_employees();
    library.circulate_book("Software Engineering", Date(2015, 4, 1, DateFormat::US));

    library.pass_on("Software Engineering", Date(2015, 4, 5, DateFormat::US));
    library.pass_on("Software Engineering", Date(2015, 4, 10, DateFormat::US));
    library.pass_on("Software Engineering", Date(2015, 4, 15, DateFormat::US));
    library.print_employees();

    library.add_book("Underwater Basket Weaving");

    library.circulate_book("Underwater Basket Weaving", Date(2015, 4, 16, DateFormat::US));
    library.pass_on("Underwater Basket Weaving", Date(2015, 4, 17, DateFormat::US));
    library.pass_on("Underwater Basket Weaving", Date(2015, 4, 18, DateFormat::US));
    library.pass_on("Underwater Basket Weaving", Date(2015, 4, 24, DateFormat::US));
    library.print_employees();

    return 0;
}

