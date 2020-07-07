#pragma once
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Employee {
private:
	string name;
	int wait_time;
	int retain_time;
	

public:
	
	Employee(string new_name);
	Employee(const Employee& other);
	string get_name();
	int priority();
	void receive_book(int curr_wait);
	void pass_book(int curr_retain);
	friend bool operator<(Employee& lhs, Employee& rhs);
	friend bool operator>(Employee& lhs, Employee& rhs);

	const string to_string() const { //toString method just for testing 
		ostringstream buffer;
		buffer << "Name: " << name << ", Priority: " <<wait_time-retain_time<< endl;
		//return name +" "+ to_string(temp_priority); 

		return buffer.str();
	}
};
