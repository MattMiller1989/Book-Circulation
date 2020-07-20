#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include "Date.h"
using namespace std;

class Employee {
private:
	string name;
	int wait_time;
	int retain_time;
	Date wait_start;
	Date retain_start;
	

public:
	Employee() {};
	Employee(string new_name);
	Employee(const Employee& other);
	string get_name();
	int priority();
	void receive_book(int curr_wait,string name,Date circ_date);
	void pass_book(int days_passed);
	friend bool operator<(Employee& lhs, Employee& rhs);
	friend bool operator>(Employee& lhs, Employee& rhs);
	
	int get_wait_time();
	int get_retain_time();

	const string to_string() const { //toString method just for testing 
		ostringstream buffer;
		
		buffer << name << " ";
		 

		return buffer.str();
	}
};
