

#include "book.h"
Book::Book()
{
}

//parametrized constructor
Book::Book(string bookName)
{
	name = bookName;
}

Book::Book(string bookName, Date start) {
	name = bookName;
	startDate = start;
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

void Book::setendDate(Date newDate)
{
	endDate = newDate;
}

void Book::setarchived(bool newBool)
{
	archived = newBool;
}

void Book::setHeld(Date date)
{
	lastHeld = date;
}

//add list to queue
void Book::populate_queue(const list<Employee*> empList)
{
	list<Employee*>::const_iterator it;
	for (it = empList.begin(); it != empList.end(); it++)
	{
		wa.addEmployee(*it);
	}
}

//pop the element
Employee* Book::pop_max()
{
	return wa.pop_max();
}

//get the top of the queue
Employee* Book::top()
{
	return wa.top();
}

bool Book::isEmpty()
{
	return wa.empty();
}

