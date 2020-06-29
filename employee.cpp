
#include "employee.h"

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


