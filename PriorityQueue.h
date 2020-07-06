#pragma once

#include <vector>

template <typename type>
class PriorityQueue {

private:
	std::vector<type> data;
	int size;
	
	
	
public:
	//PriorityQueue() {
	PriorityQueue() {
		size = 0;

	}
	
	void push(type element);
	void pop();
	void update();
	type* front();
	void print_queue();
	bool empty();


};
