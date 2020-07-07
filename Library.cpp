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
}
void Library::pass_on(string book_name, Date& pass_date) {
	
	int ind = find_circ(book_name);
	if (ind == -1) {
		cout << book_name << " is not currently in circulation " << endl;
	}
	else {
		
		if (books[ind].to_archive()) {
			
			cout << "archive" << endl;
			archive.push_back(books[ind]);

			
			cout << books[ind].to_string() << endl;

			books.erase(books.begin()+ind);
		}
		else{
			
			//cout << pass_date.toString() << endl;
			//cout << books[ind].getstartDate().toString() << endl;
			cout << "pass" << endl;
			cout << books[ind].size() << " " << books[ind].getstartDate().toString() << endl;
			books[ind].pass(pass_date - books[ind].getstartDate());
			cout << "dates working?" << endl;
		}
		

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