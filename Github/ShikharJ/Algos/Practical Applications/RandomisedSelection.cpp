/*
Randomised Selection through Quick Sort
---------------------------------------
Time Complexity : Best and Average Case : O(n)
				  Worst Case : O(n^2)
Space Complexity : O(n)
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

srand(time(NULL));

size_t partition(vector<int> &v, size_t start, size_t end){
	size_t random_index = start + (rand() % (end - start + 1));
	swap(v[random_index], v[start]);
	int pivot = v[start];
	size_t i = start + 1;
	for (size_t j = start + 1; j <= end; j++){
		if (v[j] < v[pivot]){
			swap(v[i], v[j]);
			i += 1;
		}
	}
	swap(v[start], v[i - 1]);
	return i - 1;
}

size_t selection(vector<int> &v, size_t start, size_t end, size_t statistic){
	if (start == end){
		return v[p];
	}
	size_t pivot_index = partition(v, start, end);
	size_t range = start - end + 1;
	if (statistic == range){
		return v[pivot_index];
	} else if (statistic < range){
		return selection(v, start, pivot_index - 1, i);
	} else{
		return selection(v, pivot_index + 1, end, i - k);
	}
}