#include "PriorityQueue.h"
#include <iostream>
using namespace std;



template <typename type>
void PriorityQueue<type>::push(type& element) {
	
	/*Pushes the element into the back of the data vector... 
		It is unsorted at this point*/
	//cout << "retain: " << element.get_retain_time() << endl;
	
	data.push_back(element);

	
	size += 1;
	

}

template <typename type>
void PriorityQueue<type>::pop() {	//removes the first element in the queue... Also checks to see if Queue is empty
	
	/*Pops the sorted element from the top of the queue
	 It also checks to make sure that the queue is not empty
	 before attempting to pop*/

	if (!empty()){
		data.erase(data.begin());
		size-=1;
	}
	else {
		cout << "No more data in the queue" << endl;
	}
	
}
template <typename type>
void PriorityQueue<type>::update() {		//sorts the items by a comparable value... in this case, priority
	

	for (int i = 0; i < size; ++i) {
		int pos_max = i;
		for (int j = i + 1; j < size; ++j) {   //uses selection sort @ O(n^2)
			if (data[j] > data[pos_max])
				pos_max = j;
		}
		if (pos_max != i) {
			swap(data[i], data[pos_max]);
		}
	}

}
template <typename type>
type& PriorityQueue<type>::front() { //returns a pointer to the front of the priority queue
	
	/*Returns a pointer to the front of the Priority Queue
	this method does not sort or update the queue so it already assumes that 
	the qeue had been updated*/
	
	if (!empty()) {
		//cout <<data[0].get_name()<<" retain "<< data[0].get_retain_time()<<endl;
		return data[0];
	}
}
template <typename type>
void PriorityQueue<type>::print_queue() { //Prints each item in the queue. For testing purposes
	
	
	for (int x = 0; x < size; x++) {
		cout <<x<< data[x].to_string() << " ";
	}
	cout << "\n";
}
template <typename type>
bool PriorityQueue<type>::empty() { //Checks to see if Pqueue is empty
	
	return size == 0;
}
template <typename type>
int PriorityQueue<type>::get_size() {
	return size;
}

