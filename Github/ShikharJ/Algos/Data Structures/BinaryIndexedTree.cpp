/*
Binary Indexed Tree
-------------------
Binary Indexed Tree also called Fenwick Tree provides a way to represent
an array of numbers in an array, allowing prefix sums to be calculated efficiently.
-------------------
Time Complexity : O(logn)
Space Complexity : O(n)
*/

#include <iostream>
#include <vector>

using namespace std;

size_t n;
vector<int> tree(10000);

void update_tree(size_t x, int value){
	while (x <= n){
		tree[x] += value;
		x += (x & -x);
	}
}

int read_tree(int x){
	int value = 0;
	while (x > 0){
		value += tree[x];
		x -= (x  & -x);
	}
	return value;
}