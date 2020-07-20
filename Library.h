#pragma once


#include"Book.h"
#include <vector>
#include <string>
#include <iostream>
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
	
	
	
	int find_archive(string& name);
	int find_circ(string& name);
	int books_size() {
		return books.size();
	};
	int archive_size() {
		return archive.size();
	};

	void update_priorities(Employee& employee);
	void print_employees();
};
