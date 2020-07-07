

#include "book.h"


//parametrized constructor
Book::Book(string bookName)
{
	name = bookName;
}

Book::Book(string bookName, Date start) {
	name = bookName;
	startDate = start;
}
/*
Book::Book(const Book& other) {
	name = other.name;
	startDate = other.startDate;
	endDate = other.endDate;
	archived = other.archived;
	wa = other.wa;
}*/

//implement getter and setters
string Book::getname()
{
	return name;
}
Date Book::getstartDate()
{
	return startDate;
}

Date Book::getendDate()
{
	return endDate;
}

bool Book::getarchived()
{
	return archived;
}

Date Book::getHeld()
{
	return lastHeld;
}

void Book::setname(string newName)
{
	name = newName;
}

// Implement start date is
//also lastHeld for first pass_on()
void Book::setstartDate(Date newDate)
{
	startDate = lastHeld = newDate;
}


//add vector to queue
void Book::populate_queue( vector<Employee*> empList)
{
	vector<Employee*>::iterator it;
	for (it = empList.begin(); it != empList.end(); ++it)
	{
		Employee* e = *it;
		wa.push(e);
	}

	
}
bool Book::to_archive() {
	//cout << "ARCHIVE??" << endl;
	//cout << wa.size << endl;
	return wa.empty();
}
void Book::circulate(Date circ_date) {
	setstartDate(circ_date);
	wa.front()->receive_book(0);

}

void Book::pass(int days_passed) {
	
	wa.print_queue();
	wa.front()->pass_book(days_passed);
	wa.pop();
	wa.update(); //updates the queue before passing book
	wa.front()->receive_book(days_passed);



	
}
int Book::size() {
	return wa.get_size();
}




