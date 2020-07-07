
#include <iostream>
//#include "Library.cpp"
//#include "PriorityQueue.h"
//#include "PriorityQueue.cpp"
//#include "Employee.h"
#include "Library.h"
using namespace std;

int main()
{
    
    

    
    Library library;
   // library.add_book("Software Engineering");
    library.add_book("Chemistry");
    library.add_employee("Adam");
    library.add_employee("Sam");
    library.add_employee("Ann");
    library.add_new_book("MYFUNBOOK");
    library.print_new_books();
    
    /*vector<Book*> bookvec;
    Book book("mybook!!");
    bookvec.push_back(&book);
    Book book1("mybook1!!");
    bookvec.push_back(&book1);
    Book book2("mybook2!!");
    bookvec.push_back(&book2);

    cout << bookvec[1]->getname() << endl;*/
    //library.circulate_book("Chemistry", Date(2015, 3, 1, DateFormat::US));
    //cout << library.books_size() << endl;
    //library.circulate_book("Software Engineering", Date(2015, 4, 1, DateFormat::US));
   // library.pass_on("Chemistry", Date(2015, 3, 5, DateFormat::US));
   // library.pass_on("Chemistry", Date(2015, 3, 7, DateFormat::US));
     //library.pass_on("Chemistry", Date(2015, 3, 15, DateFormat::US));
    //library.pass_on("Software Engineering", Date(2015, 4, 5, DateFormat::US));
    //library.pass_on("Software Engineering", Date(2015, 4, 10, DateFormat::US));
    //library.pass_on("Software Engineering", Date(2015, 4, 15, DateFormat::US));*/
    

    return 0;
}

