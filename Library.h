#pragma once

//#include "Date.h"
//#include"PriorityQueue.cpp"
//#include"PriorityQueue.h"
//#include"Employee.h"
#include"Book.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Library {
private:
	vector<Book> new_books;
	vector<Book> books;
	vector<Book> archive;
	vector<Employee> employees;


public:
	void add_book(string name);
	void add_employee(string employee);
	void circulate_book(string book_name, Date circ_date);
	void pass_on(string& book_name, Date pass_date);
	void add_new_book(string name);
	void print_new_books();
	int find_archive(string& name);
	int find_circ(string& name);
	int books_size() {
		return books.size();
	};
	int archive_size() {
		return archive.size();
	};
};