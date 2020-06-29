

#include "book.h"
//parametized constructor
Book::Book(string newName) {
	name = newName;

}
//attribute getter methods
string& Book::get_name() {
	return name;
}



void Book::circulate_book(Date& circDate, vector<Employee*> employees)
{
	PriorityQueue employeeQueue = fill_queue(employees);

}

PriorityQueue& Book::fill_queue(vector<Employee*> employees)
{
	PriorityQueue employeeQueue;

	vector<Employee*>::iterator it;

	for (it = employees.begin(); it != employees.end(); it++) {
		employeeQueue.push(*it);

	}
	
	return employeeQueue;
	

}

