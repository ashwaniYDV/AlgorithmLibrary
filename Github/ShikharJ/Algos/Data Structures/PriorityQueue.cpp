/*
Priority Queue
--------------
An abstract data type which is like a regular queue or stack data
structure, but where additionally each element has a priority associated
with it. In a priority queue, an element with high priority is served
before an element with low priority.
--------------
Time Complexity : Push/Pop : O(logn)
				  Empty/Extract : O(1)
Space Complexity : O(n)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> priority_queue(10000);
size_t heap_size = 0;

bool empty(){
	return heap_size == 0;
}

int extract(){
	if (empty()){
		return -1;
	}
	return priority_queue[1];
}

void push(int x){
	priority_queue[heap_size++] = x;
	size_t position = heap_size;
	while (position > 1 and priority_queue[position / 2] > priority_queue[position]){
		swap(priority_queue[position / 2], priority_queue[position]);
		position /= 2;
	}
}

void pop(int x){
	if (empty()){
		return -1;
	}
	size_t position = 1;
	swap(priority_queue[position], priority_queue[heap_size--]);
	while (position <= heap_size){
		size_t current = position;
		size_t left = 2 * position;
		size_t right = 2 * position + 1;
		if (left <= heap_size and priority_queue[left] < priority_queue[current]){
			current = left;
		}
		if (right <= heap_size and priority_queue[right] < priority_queue[current]){
			current = right;
		}
		if (current != position){
			swap(priority_queue[current], priority_queue[position])
			position = current;
		} else {
			break;
		}
	}
}