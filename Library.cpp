#include "Library.h"

using namespace std;

void Library::add_employee(string name) { // Creates a new employee and adds the to the vector
	Employee curr_employee(name);
	employees.push_back(curr_employee);
	//std::cout << employees.size() << endl;
}
void Library::add_new_book(string name) { // Creates a new book and adds it to the book vector
	Book curr_book(name);
	cout << &curr_book << endl;
	new_books.push_back(curr_book);
	//std::cout << archive.size() << endl;

}
void Library::print_new_books() { 
	cout << new_books[0].getname() << endl;
	

}

void Library::add_book(string name) { // Creates a new book and adds it to the book vector
	Book curr_book(name);
	cout << &curr_book << endl;
	archive.push_back(curr_book);
	//std::cout << archive.size() << endl;

}
void Library::circulate_book(string book_name, Date circ_date) { 

	cout <<"archive size: "<< archive.size() << endl;
	int ind = find_archive(book_name);
	cout << "CHECK FOR ARCHIVE?>?!?  ind: " << ind << endl;
	if (ind == -1) {
		cout << book_name << " is not currently archived " << endl;
	}
	else {
		Book* curr_book = &archive[ind];
		cout << &curr_book << endl;
		books.push_back(*curr_book);

		archive.erase(archive.begin() + ind);
		cout << "employee vec before pq is popp'd: " <<employees.size()<< endl;
		curr_book->populate_queue(employees);

		
		curr_book->circulate(circ_date);

	}
}
void Library::pass_on(string& book_name, Date pass_date) {
	//std::cout << books.size() << endl;
	int ind = find_circ(book_name);
	if (ind == -1) {
		cout << book_name << " is not currently in circulation " << endl;
	}
	else {
		cout << "CHECK FOR ARCHIVE?>?!?  ind: " <<ind<< endl;
		Book* curr_book = &books[ind];
		cout << curr_book <<" size: "<<curr_book->size()<< endl;
		if (curr_book->to_archive()) {
			// cout << books.size();
			cout << "archive" << endl;
			archive.push_back(*curr_book);

			Book* to_erase = &books[ind];
			cout << to_erase->to_string() << endl;

			books.erase(books.begin()+ind);
		}
		else{
			//curr_book->populate_queue(employees);
			cout << "pass" << endl;
			curr_book->pass(pass_date - curr_book->getstartDate());
		}
		

	}
}

int Library::find_archive(string& name) { // returns index of the book in circulation or archive
	int loc = -1;
	cout << archive_size() << endl;
	//cout << archive[0]->getname() << endl;
	for (int x = 0; x < archive_size(); x++) {
		// string curr_name =archive.at(x)->getname();
		// cout << &curr_name << endl;
		 //cout << &name << endl;
		//cout << archive[x]->getname() << endl;
		if (archive[x].getname()==name) {
			cout << &archive.at(x) << endl;
			loc=x;
		}
	}

	return loc;
}
int Library::find_circ(string& name) { // returns index of the book in circulation or archive
	int loc = -1;
	for (int x = 0; x < books_size(); x++) {
		//string curr_name = books.at(x)->getname();
		if (books[x].getname() == name) {
			cout << &books.at(x) << endl;
			loc = x;
		}
	}

	return loc;
}