/*
Disjoint Set Union
------------------
A disjoint-set data structure is a data structure that keeps track
of a set of elements partitioned into a number of disjoint subsets.
A union-find algorithm is an algorithm that performs two useful operations
on such a data structure
------------------
Time Complexity : O(n)
Space Complexity : O(n)
*/

#include <iostream>

using namespace std;

size_t components;

struct node{
	size_t parent;
	size_t rank;
};

node DisjointSetUnion[10000];

void makeset(size_t x){
	DisjointSetUnion[x].rank = 0;
	DisjointSetUnion[x].parent = x;
}

size_t find(size_t x){
	if (DisjointSetUnion[x].parent == x){
		return x;
	}
	DisjointSetUnion[x].parent = find(DisjointSetUnion[x].parent);
	return DisjointSetUnion[x].parent;
}

void unionset(size_t x, size_t y){
	size_t rootx = find(x);
	size_t rooty = find(y);
	if (rootx == rooty){
		return ;
	}
	components -= 1;
	if (DisjointSetUnion[rootx].rank < DisjointSetUnion[rooty].rank){
		DisjointSetUnion[rootx].parent = rooty;
	} else if (DisjointSetUnion[rootx].rank > DisjointSetUnion[rooty].rank){
		DisjointSetUnion[rooty].rank = rootx;
	} else {
		DisjointSetUnion[rooty].parent = rootx;
		DisjointSetUnion[rootx].rank += 1;
	}
}