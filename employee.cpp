#include "Employee.h"

Employee::Employee(string new_name) {
	name = new_name;
	wait_time = 0;
	retain_time = 0;
}
Employee::Employee(string new_name,int new_priority) {
	name = new_name;
	wait_time = 0;
	retain_time = 0;
	temp_priority = new_priority;
}
string Employee::get_name() {
	return name;
}
int Employee::priority() {
	//return wait_time - retain_time;
	return temp_priority;
}
bool operator<(Employee& lhs, Employee& rhs) {
	return lhs.priority() < rhs.priority();
}
bool operator>(Employee& lhs, Employee& rhs) {
	return lhs.priority() > rhs.priority();
}
