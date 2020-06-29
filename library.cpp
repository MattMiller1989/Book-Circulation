#include "Library.h"

using namespace std;


void Library::add_book(string name) {
	
	Book new_book = Book(name);
	books.push_back(&new_book);


}
void Library::add_employee(string name) {
	Employee new_employee = Employee(name);
	employees.push_back(&new_employee);
}
void Library::circulate_book(string name, Date date) {
	
}
void Library::pass_on(string name, Date date) {

}
