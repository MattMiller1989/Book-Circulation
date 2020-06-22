

#include "book.h"
//parametized constructor
Book::Book(string newName) {
	name = newName;

}
//attribute getter methods
string& Book::getName() {
	return name;
}

Date& Book::getStartDate() {
	return startDate;
}
Date& Book::getEndDate() {
	return endDate;
}

void Book::circulateBook(Date& circDate, vector<Employee*> employees)
{
	PriorityQueue employeeQueue = fillQueue(employees);

}

PriorityQueue& Book::fillQueue(vector<Employee*> employees)
{
	PriorityQueue employeeQueue;

	vector<Employee*>::iterator it;

	for (it = employees.begin(); it != employees.end(); it++) {
		employeeQueue.addEmployee(*it);

	}
	
	return employeeQueue;
	

}

