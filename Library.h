#pragma once

#include "Date.h"
#include"PriorityQueue.cpp"
#include"Employee.cpp"
//#include"Book.cpp"
#include <vector>
#include <string>
using namespace std;


class Library {
private:
	vector<Book> books;
	vector<Book> archive;
	vector<Employee> employees;


public:
	void add_book(string name);
	void add_employee(string employee);
	void circulate_book(string book_name, Date circ_date);
	void pass_on(string book_name, Date pass_date);
	template<typename type>
	int find_ind(string name, vector<type> vec);
};