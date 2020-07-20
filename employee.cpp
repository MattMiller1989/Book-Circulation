#include "Employee.h"

Employee::Employee(string new_name) {
	name = new_name;
	wait_time = 0;
	retain_time = 0;
}
Employee::Employee(const Employee& other) {
	name = other.name;
	wait_time = other.wait_time;
	retain_time = other.retain_time;
	wait_start = other.wait_start;
	retain_start = other.retain_start;
	first_book = other.first_book;
	
}

string Employee::get_name() {
	return name;
}
void Employee::receive_book(int curr_wait,string book_name,Date circ_date) {

	if (first_book) {
		wait_time += curr_wait;
		first_book = false;
	}
	else {
		wait_time += circ_date - wait_start;
	}
	retain_start = circ_date;
	cout << name << " has received the book titled: " << book_name <<" on: "<< circ_date.toString()<< endl;
	
	
}
void Employee::pass_book(int curr_retain,Date pass_date) {
	wait_start = pass_date;
	retain_time += pass_date-retain_start;
	
	
}
int Employee::priority() {
	return wait_time - retain_time;
	
}

/*The following methods overload the comparator operators. 
These methods use the priority value*/
bool operator<(Employee& lhs, Employee& rhs) {
	return lhs.priority() < rhs.priority();
}
bool operator>(Employee& lhs, Employee& rhs) {
	return lhs.priority() > rhs.priority();
}

int Employee::get_wait_time() {
	return wait_time;
}
int Employee::get_retain_time() {
	return retain_time;

}
