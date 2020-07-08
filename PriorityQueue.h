#pragma once

#include <vector>

template <typename type>
class PriorityQueue {

private:
	
	int size;
	
	
	
public:
	//PriorityQueue() {
	std::vector<type> data;
	PriorityQueue() {
		size = 0;

	}

	PriorityQueue(const PriorityQueue<type>& other) {
		data = other.data;
		size = other.size;
	}
	
	void push(type& element);
	void pop();
	void update();
	type& front();
	void print_queue();
	bool empty();
	int get_size();


};
