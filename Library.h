#pragma once

//include header files

#include "PriorityQueue.h"
#include "employee.h"
#include "book.cpp"
#include "Date.h"
using namespace std;

//declare class
class Library
{
private:
	//data members
	vector<Book*> books;
	vector<Employee*> employees;
	

public:
	//member functions
	

	void circulate_book(string name, Date date);
	void add_book(string name);
	void add_employee(string name);
	void pass_on(string name, Date date);
	

};