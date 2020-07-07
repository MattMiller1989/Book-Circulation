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
}

string Employee::get_name() {
	return name;
}
void Employee::receive_book(int curr_wait,string book_name) {
	cout << name << " has received the book titled: " << book_name << endl;
	wait_time += curr_wait;
}
void Employee::pass_book(int curr_retain) {
	
	retain_time += curr_retain;
}
int Employee::priority() {
	return wait_time - retain_time;
	
}


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
