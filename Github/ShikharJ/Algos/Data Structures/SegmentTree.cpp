/*
Segment Tree
------------
Segment Tree is a basically a binary tree used for storing the
intervals or segments. Each node in the segment tree represents an interval.
------------
Time Complexity : O(logn)
Space Complexity : O(n)
*/

#include <iostream>
#include <vector>

using namespace std;

size_t n;
vector<int> base(10000);
vector<int> tree(10000);

void init_tree(size_t index, size_t left, size_t right){
	if (left == right){
		tree[index] = base[left];
		return ;
	}
	size_t middle = (left + right) / 2;
	init_tree(2 * index, left, middle);
	init_tree(2 * index + 1, middle + 1, right);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

void update_tree(size_t index, size_t x, int value, size_t left, size_t right){
	if (left == right){
		tree[index] = value;
		return ;
	}
	size_t middle = (left + right) / 2;
	if (x <= middle){
		update_tree(2 * index, x, value, left, middle);
	} else {
		update_tree(2 * index + 1, x, value, middle + 1, right);
	}
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

int query_tree(size_t index, size_t l, size_t r, size_t left, size_t right){
	if (l <= left and r >= right){
		return tree[index];
	}
	int value = 999999999;
	size_t middle = (left + right) / 2;
	if (l <= middle){
		value = min(value, query_tree(2 * index, l, r, left, middle));
	}
	if (r > middle){
		value = min(value, query_tree(2 * index + 1, l, r, middle + 1, right));
	}
	return value;
}