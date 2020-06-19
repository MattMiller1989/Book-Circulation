
#include "book.h"
#include <iostream>
using namespace std;

int main() {
	//just some testing of the Date classes/files
	Date today(2020, 6, 19);
	Date yesterday(2020, 6, 17);
	Book myBook("Slaughterhouse 5");
	cout << myBook.getName() << endl;
	cout << today - yesterday << endl;
	return 0;
}

void circulateBook(string& name, Date circDate) {

}
void passOn(string& name, Date passDate) {

}
void addEmployee(string& name) {

}
void addBook(string name) {

}