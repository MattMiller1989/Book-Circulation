#pragma once
//include header files
#include <stdio.h>
#include <string>
#include "Date.h"
using namespace std;
//declare class
class Employee
{
private:
	//data members
	string name;
	int waitTime;
	int retainTime;
public:
	//member functions
	Employee();
	Employee(string newName);
	const Employee& operator = (const Employee& rhs);
	void setName(string newName);
	void wait(int wait);
	void retain(int retain);
	string getName();
	int getWait();
	int getRetain();
	friend bool operator<(const Employee& lhs, const Employee& rhs);
	friend bool operator>(const Employee& lhs, const Employee& rhs);
};
