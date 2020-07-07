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

	
	int ind = find_archive(book_name);
	
	if (ind == -1) {
		cout << book_name << " is not currently archived " << endl;
	}
	else {
		Book curr_book = archive[ind];
		
		curr_book.populate_queue(employees);
		curr_book.circulate(circ_date);
		
		books.push_back(curr_book);
		

		archive.erase(archive.begin() + ind);
		
		

		
		

	}
	//print_employees();
}
void Library::pass_on(string book_name, Date& pass_date) {
	
	int ind = find_circ(book_name);
	if (ind == -1) {
		cout << book_name << " is not currently in circulation " << endl;
	}
	else {
		
		if (books[ind].to_archive()) {
			
			cout << books[ind].getname() << " has been moved to the archive" << endl;
			archive.push_back(books[ind]);

			
			

			books.erase(books.begin()+ind);
		}
		else{
			
			int days_passed = pass_date - books[ind].getstartDate();
			//cout << days_passed << endl;
			books[ind].pass(days_passed);
			
		}
		

	}
	//print_employees();
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

//void Library::print_employees() {
//	for (int x = 0; x < employees.size(); ++x) {
//		Employee curr_employee = employees[x];
//		cout << curr_employee.to_string();
//		cout << " wait_time: " << curr_employee.get_wait_time();
//		cout << " retain_time: " << curr_employee.get_retain_time();
//		cout << " priority: " << curr_employee.priority() << endl;;
//	}
//}