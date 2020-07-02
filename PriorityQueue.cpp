#include "PriorityQueue.h"
#include <iostream>
using namespace std;



template <typename type>
void PriorityQueue<type>::push(type element) {
	data.push_back(element);

	
	++size;

}

template <typename type>
void PriorityQueue<type>::pop() {

	if (size > 0) {
		data.erase(data.begin());
	}
	else {
		cout << "No more data in the queue" << endl;
	}
	
}
template <typename type>
void PriorityQueue<type>::update() {		//sorts the items by a comparable value... in this case, priority
	

	for (int i = 0; i < data.size(); ++i) {
		int pos_max = i;
		for (int j = i + 1; j < data.size(); ++j) {   //uses selection sort @ O(n^2)
			if (data[j] > data[pos_max])
				pos_max = j;
		}
		if (pos_max != i) {
			swap(data[i], data[pos_max]);
		}
	}

}
template <typename type>
type* PriorityQueue<type>::front() {
	return &data[0];
}
template <typename type>
void PriorityQueue<type>::print_queue() {
	for (int x = 0; x < data.size(); x++) {
		cout << data[x] << " ";
	}
	cout << "\n";
}

