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
void Library::circulate_book(string book_name, Date circ_date) { 

	int ind = find_ind(book_name, archive);
	if (ind == -1) {
		cout << book_name << " does not exist " << endl;
	}
	else {
		Book curr_book = archive[ind];
		books.push_back(curr_book);

		archive.erase(archive.begin() + ind);

		curr_book.populate_queue(employees);

		
		curr_book.circulate(circ_date);

	}
}
void Library::pass_on(string book_name, Date pass_date) {
	int ind = find_ind(book_name, books);
	if (ind == -1) {
		cout << book_name << " does not exist " << endl;
	}
	else {
		
		Book* curr_book = &books[ind];
		if (curr_book->to_archive()) {
			archive.push_back(*curr_book);
			books.erase(books.begin()+ind);
		}
		else{
			curr_book->populate_queue(employees);
			curr_book->pass(pass_date - curr_book->getstartDate());
		}
		

	}
}

int Library::find_ind(string name, vector<Book> vec) { // returns index of the book in circulation or archive
	for (int x = 0; x < vec.size(); x++) {
		if (vec.at(x).getname() == name) {
			return x;
		}
	}

	return -1;
} 