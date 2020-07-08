

#include "book.h"


//parametrized constructor

Book::Book(string bookName)
{
	name = bookName;
}


Book::Book(const Book& other) {
	/*Copy constructor that provides a deep copy of all of the 
		member variables*/
	
	name = other.name;
	startDate = other.startDate;
	endDate = other.endDate;
	archived = other.archived;
	wa = other.wa;
	
	
	
}

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



// Implement start date is
//also lastHeld for first pass_on()
void Book::setstartDate(Date& newDate)
{
	
	startDate = newDate;
	
}


//add vector to queue
void Book::populate_queue( vector<Employee>& empList)
{
	/*This method populates the priority queue with all of the employees
	who are able to receive said book. Not that this method does NOT sort
	the queue.*/

	vector<Employee>::iterator it;
	for (it = empList.begin(); it != empList.end(); ++it)
	{
		Employee e = *it;
		
		wa.push(e);
		
	}
	wa.update(); 
	
	/*^this is the first update of the queue.. mainly meant for 
	if a book has already been circulated. This accounts for the priority after
	the first circvulation.*/
	
}
bool Book::to_archive() {
	/*Determines if the book needs to be archived by checking to see if the respective
	priority queue is empty*/
	
	return wa.get_size()==1;
}
void Book::circulate(Date circ_date) {
	wa.update(); //updates the queue before passing book
	setstartDate(circ_date);
	wa.front().receive_book(0,name);

	
	
	

}

void Book::pass(int days_passed) {
	
	
	wa.front().pass_book(days_passed);
	

	cout <<  wa.front().get_name() << " has relinquished control of the book "<<name<<endl;
	

	wa.pop();
	wa.update(); //updates the queue before passing book
	
	if (wa.get_size() > 0) {
		
		wa.front().receive_book(days_passed,name);
	}
	
	
	



	
}
int Book::size() {
	return wa.get_size();
}

Employee* Book::get_current_employee() {
	if (!wa.empty()) {
		return &wa.front();
	}
	else {
		cout << "The book does not have an owner";
	}
}




