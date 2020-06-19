//inlcude hedaer files
#include "employee.h"
//constructor
Employee::Employee() {
	name = "unknown";
	waitTime = 0;
	retainTime = 0;
}
//paremetrized constructor
Employee::Employee(string newName) {
	name = newName;
	waitTime = 0;
	retainTime = 0;
}
const Employee& Employee::operator = (const Employee& rhs) {
	name = rhs.name;
	waitTime = rhs.waitTime;
	retainTime = rhs.retainTime;
	return *this;
}
void Employee::setName(string newName) {
	name = newName;
}
void Employee::wait(int wait) {
	waitTime += wait;
}
void Employee::retain(int retain) {
	retainTime += retain;
}
string Employee::getName() {
	return name;
}
int Employee::getWait() {
	return waitTime;
}
int Employee::getRetain() {
	return retainTime;
}
bool operator<(const Employee& lhs, const Employee& rhs)
{
	return ((lhs.waitTime - lhs.retainTime) < (rhs.waitTime - rhs.retainTime));
}
bool operator>(const Employee& lhs, const Employee& rhs)
{
	return ((lhs.waitTime - lhs.retainTime) > (rhs.waitTime - rhs.retainTime));
}


