#include "Library.h"

using namespace std;

void Library::add_employee(string name) { // Creates a new employee and adds the to the vector
	Employee curr_employee(name);
	employees.push_back(curr_employee);
	
}



void Library::add_book(string name) { // Creates a new book and adds it to the book vector
	Book curr_book(name);
	
	archive.push_back(curr_book);
	

}
void Library::circulate_book(string book_name, Date& circ_date) { 
	/*Starts the curcylation of the book*/
	
	int ind = find_archive(book_name);
	
	if (ind == -1) {
		cout << book_name << " is not currently archived " << endl;
	}
	else {
		Book curr_book = archive[ind];
		
		curr_book.populate_queue(employees);    //populates the priority queue
		curr_book.circulate(circ_date);
		
		books.push_back(curr_book);
		
		update_priorities(*(curr_book).get_current_employee()); 
		/*^makes sure that any changes to the employees priority gets added to the global scopr*/
		
		archive.erase(archive.begin() + ind); //removes the book from the arcvhive
	

	}
	
}
void Library::pass_on(string book_name, Date& pass_date) {
	
	int ind = find_circ(book_name); //returns the book object from the object in circulation
	if (ind == -1) {
		cout << book_name << " is not currently in circulation " << endl;
	}
	else {
		
		if (books[ind].to_archive()) { //checks to see if the book needs to be archived
			
			cout << books[ind].getname() << " has been moved to the archive" << endl;
			archive.push_back(books[ind]);
			/*^ puts the book into the archive*/
			
			

		}
		else{
			
			int days_passed = pass_date - books[ind].getstartDate();
			
			books[ind].pass(days_passed);
			
		}
		update_priorities(*(books[ind]).get_current_employee());
		/*^makes sure that any changes to the employees priority gets added to the global scopr*/

	}
	
}

int Library::find_archive(string& name) { // returns index of the book in circulation or archive
	int loc = -1;
	
	for (int x = 0; x < archive_size(); x++) {
		
		if (archive[x].getname()==name) {
			
			loc=x;
		}
	}

	return loc;
}
int Library::find_circ(string& name) { // returns index of the book in circulation or archive
	int loc = -1;
	for (int x = 0; x < books_size(); x++) {
		
		if (books[x].getname() == name) {
			
			loc = x;
		}
	}

	return loc;
}
void Library::update_priorities(Employee& employee) {
	/*Makes sure that the priority of the employees gets
	updated outside of the scope of the local priority queue*/

	for (int x = 0; x < employees.size(); ++x) {  //Update method with O(n)
		if (employees[x].get_name() == employee.get_name()) {
			employees[x] = employee;
		}
	}
}
void Library::print_employees() {
	/*This function is used to check and make sure that the priorities are 
	being properly updated*/
	for (int x = 0; x < employees.size(); ++x) {
		Employee curr_employee = employees[x];
		cout << curr_employee.to_string();
		cout << " priority: " << curr_employee.priority() << endl;;
	}
}