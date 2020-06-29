#pragma once

#include <stdio.h>
#include <string>
#include "Date.h"
using namespace std;

class Employee
{
private:
	//data members
	string name;
	int waitTime;
	int retainTime;
	bool has_book;


public:
	
	
	Employee(string newName);
	string getName();
	int getWait();
	int getRetain();
	int priority();
	void update_priority();
	void recieve_book(Date date);
	void pass_book(Date date);
	const Employee& operator = (const Employee& rhs);
	
	
	friend bool operator<(const Employee& lhs, const Employee& rhs);
	friend bool operator>(const Employee& lhs, const Employee& rhs);
};
