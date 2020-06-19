#pragma once
//include header files
#include <stdio.h>
#include <string>
#include <vector>
#include "Date.h"
#include "PriorityQueue.cpp"
#include "employee.cpp"
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
	Book(string& name);
	string& getName();
	Date& getStartDate();
	Date& getEndDate();
	
	void circulateBook(Date& circDate, vector<Employee*> employees);
	PriorityQueue& fillQueue(vector<Employee*> employees);

	


};