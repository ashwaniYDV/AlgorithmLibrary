/*
Heap Sort
---------
A comparison-based sorting algorithm that uses 
an array-implemented heap to sort a list of integers.
Use order = +/- 1 for increasing and decreasing orders respectively.
---------
Time Complexity : Best, Average and Worst Case : O(n*logn)
Space Complexity : O(1)
Stable : No
In-Place : Yes
Online : Yes
*/

#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> v, int parent, const int last, int order){
	int child = 2 * parent + 1;
	while (child <= last){
		if (child + 1 <= last and v[child + 1] * order > v[child] * order){
			child ++;
		}
		if (v[parent] * order < v[child] * order){
			swap(v[parent], v[child])
		}
		parent = child;
		child = 2 * parent + 1;
	}
}

void heap_sort(vector<int> v, const int size, int order){
	int last = size - 1;
	while (last >= 0){
		swap(v[0], v[last]);
		last--;
		heapify(v, 0, last, order);
	}
}

void make_heap(vector<int> v, const int size, int order){
	for (int current = (size / 2) - 1; current >= 0; current--){
		heapify(v, current, size, order);
	}
}