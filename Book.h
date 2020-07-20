//book.h

#pragma once

//include header files
#include <string>
#include "PriorityQueue.h"
#include "PriorityQueue.cpp"
#include <list>
#include "Date.h"
#include "employee.h"
#include <sstream>
using namespace std;

//declare class Book
class Book
{
private:

	string name;
	Date startDate;
	Date endDate;
	bool archived;
	PriorityQueue<Employee> wa;
	Date lastHeld;
	Employee current_employee;

public:
	Book();
	Book(string bookName);
	Book(const Book& other);
	string getname();
	Date getstartDate();
	Date getendDate();
	
	void setstartDate(Date& newDate);
	void populate_queue(vector<Employee>& empList);
	void circulate(Date circ_date);
	bool to_archive();
	Employee pass(int days_passed,bool archive);
	int size();

	Employee get_current_employee();


	

	const string to_string() const { //toString method just for testing 
		ostringstream buffer;
		buffer << "Name: " << name<< endl;
		

		return buffer.str();
	}

	

};


