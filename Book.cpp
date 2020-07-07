

#include "book.h"


//parametrized constructor
Book::Book(string bookName)
{
	name = bookName;
}


Book::Book(const Book& other) {

	
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

	vector<Employee>::iterator it;
	for (it = empList.begin(); it != empList.end(); ++it)
	{
		Employee e = *it;
		
		wa.push(e);
		
	}

	
}
bool Book::to_archive() {
	
	return wa.empty();
}
void Book::circulate(Date circ_date) {
	
	setstartDate(circ_date);
	wa.front().receive_book(0);
	
	wa.pop();

}

void Book::pass(int days_passed) {
	
	//wa.print_queue();
	wa.front().pass_book(days_passed);
	wa.pop();
	wa.update(); //updates the queue before passing book
	if (wa.get_size() > 0) {
		cout << wa.front().to_string() << endl;
		wa.front().receive_book(days_passed);
	}
	
	
	



	
}
int Book::size() {
	return wa.get_size();
}




