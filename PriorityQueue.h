#pragma once
//include required packages
#include <stdio.h>
#include <list>
#include "employee.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//declare class
class PriorityQueue
{
private:
	vector<Employee*> WorkQueue;
public:
	//member functions
	PriorityQueue();
	void addEmployee(Employee* temp);
	Employee* pop_max();
	Employee* top();
	bool empty();
};