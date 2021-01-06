/*
Quick Sort
----------
Quicksort or Partition-Exchange Sort is an efficient sorting algorithm, serving as a systematic method 
for placing the elements of an array in order. Developed by Tony Hoare (ACM Turing Award Recipient), 
it is still a commonly used algorithm for sorting. When implemented well, it can be about two or three 
times faster than its main competitors, merge sort and heapsort.
Use order = +/- 1 for increasing and decreasing orders respectively.
----------
Time Complexity : Best and Average Case : O(n*logn)
 				  Worst Case : O(n^2)
Space Complexity : O(n)
Stable : No
In-Place : Yes
Online : No
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

srand(time(NULL));

size_t partition(vector<int> &v, size_t start, size_t end, int order){
	size_t random_index = start + (rand() % (end - start + 1));
	swap(v[random_index], v[start]);
	int pivot = v[start];
	size_t i = start + 1;
	for (size_t j = start + 1; j <= end; j++){
		if (order * v[j] < order * v[pivot]){
			swap(v[i], v[j]);
			i += 1;
		}
	}
	swap(v[start], v[i - 1]);
	return i - 1;
}

void quick_sort(vector<int> &v, size_t start, size_t end, int order){
	if (start < end){
		size_t pivot_index = partition(v, start, end, order);
		quick_sort(v, start, pivot_index - 1, order);
		quick_sort(v, pivot_index + 1, end, order);
	}
}