#pragma once
//include header files

#include "PriorityQueue.h"
#include "employee.h"
using namespace std;

//declare class
class Book
{
private:
	//data members
	string name;
	Date circulation_start;
	Date circulation_end;
	bool is_archived;
	PriorityQueue employee_priority;
	
	


public:
	//member functions
	Book(string name);
	string& get_name();
	//Date& getStartDate();
	//Date& getEndDate();
	
	void circulate_book(Date& circDate, vector<Employee*> employees);
	PriorityQueue& fill_queue(vector<Employee*> employees);

	


};