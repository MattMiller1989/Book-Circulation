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
	Date startDate;
	Date endDate;
	bool isArchived;




public:
	//member functions
	Book(string name);
	string& getName();
	Date& getStartDate();
	Date& getEndDate();

	void circulateBook(Date& circDate, vector<Employee*> employees);
	PriorityQueue& fillQueue(vector<Employee*> employees);




};