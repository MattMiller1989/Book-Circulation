
#include <iostream>
//#include "Library.cpp"
//#include "PriorityQueue.h"
//#include "PriorityQueue.cpp"
//#include "Employee.h"
#include "Library.h"
using namespace std;

int main()
{

    PriorityQueue<Employee> pq;

    pq.push(Employee("Jeff"));
    pq.push(Employee("Mike"));
    pq.push(Employee("Kyle"));
    pq.push(Employee("Lyle"));
    pq.push(Employee("Chet"));
    
    Employee* curr_employee = pq.front();
    curr_employee->receive_book(5);
    curr_employee->pass_book(7);

    cout << curr_employee->priority();
    /*
    pq.push(Employee("Jeff", 5));
    pq.push(Employee("Mike", 1));
    pq.push(Employee("Kyle", 7));
    pq.push(Employee("Lyle", 3));
    pq.push(Employee("Chet", 2));


    pq.update();
    //cout << *pq.front() << endl;
    pq.print_queue();
    pq.pop();
    cout << "after a pop: " << endl;
    pq.print_queue();

    pq.push(Employee("Roderick", 4));
    cout << "after a pop: " << endl;
    pq.print_queue();

    pq.update();
    cout << "after an update: " << endl;
    pq.print_queue();

    cout << "front: ";
    cout << pq.front()->to_string() << endl;


    */




    /*
    pq.push(5);
    pq.push(1);
    pq.push(7);
    pq.push(3);
    pq.push(9);
    pq.push(21);
    pq.push(12);
    pq.push(0);





   
    pq.print_queue();
    pq.update();
    pq.print_queue();
    cout << *pq.front() << endl;
    pq.pop();
    pq.pop();
    pq.print_queue();
    cout << *pq.front() << endl;
    pq.push(4);
    pq.print_queue();
    pq.update();
    cout << *pq.front() << endl;
    pq.print_queue();

    */

    return 0;
    /* Library library;
    library.add_book("Software Engineering");
    library.add_book("Chemistry");
    library.add_employee("Adam");
    library.add_employee("Sam");
    library.add_employee("Ann");
    library.circulate_book("Chemistry", Date(2015, 3, 1, DateFormat::US));
    library.circulate_book("Software Engineering", Date(2015, 4, 1, DateFormat::US));
    library.pass_on("Chemistry", Date(2015, 3, 5, DateFormat::US));
    library.pass_on("Chemistry", Date(2015, 3, 7, DateFormat::US));
    library.pass_on("Chemistry", Date(2015, 3, 15, DateFormat::US));
    library.pass_on("Software Engineering", Date(2015, 4, 5, DateFormat::US));
    library.pass_on("Software Engineering", Date(2015, 4, 10, DateFormat::US));
    library.pass_on("Software Engineering", Date(2015, 4, 15, DateFormat::US));
    */
}

