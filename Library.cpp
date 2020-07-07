#include "Library.h"

using namespace std;

void Library::add_employee(string name) { // Creates a new employee and adds the to the vector
	Employee curr_employee(name);
	employees.push_back(&curr_employee);
	//std::cout << employees.size() << endl;
}

void Library::add_book(string name) { // Creates a new book and adds it to the book vector
	Book curr_book(name);
	archive.push_back(curr_book);
	//std::cout << archive.size() << endl;

}
void Library::circulate_book(string book_name, Date circ_date) { 


	int ind = find_ind(book_name, archive);
	if (ind == -1) {
		cout << book_name << " is not currently archived " << endl;
	}
	else {
		Book* curr_book = &archive[ind];
		books.push_back(*curr_book);

		archive.erase(archive.begin() + ind);
		cout << "employee vec before pq is popp'd: " <<employees.size()<< endl;
		curr_book->populate_queue(employees);

		
		curr_book->circulate(circ_date);

	}
}
void Library::pass_on(string book_name, Date pass_date) {
	//std::cout << books.size() << endl;
	int ind = find_ind(book_name, books);
	if (ind == -1) {
		cout << book_name << " is not currently in circulation " << endl;
	}
	else {
		cout << "CHECK FOR ARCHIVE?>?!?  ind: " <<ind<< endl;
		Book* curr_book = &books[ind];
		cout << books[ind].to_string() <<" "<<books[ind].size()<< endl;
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

int Library::find_ind(string name, vector<Book>& vec) { // returns index of the book in circulation or archive
	int loc = -1;
	for (int x = 0; x < vec.size(); x++) {
		//std::cout <<"VECNAME"<< vec.at(x).getname() << endl;
		//std::cout << "TargNAME" << name << endl;

		if (vec.at(x).getname() == name) {
			//cout << "FOUND!!!" << endl;
			loc=x;
		}
	}

	return loc;
} 