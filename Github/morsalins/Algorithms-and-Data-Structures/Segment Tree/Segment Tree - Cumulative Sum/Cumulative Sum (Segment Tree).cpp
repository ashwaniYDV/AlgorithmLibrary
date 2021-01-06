#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100000
#define I64 long long

void init (int, int, int);
long long query (int, int, int, int, int);
void update (int, int, int, int, int);

int arr[] = {0, 4, -9, 3, 7, 1, 0, 2, 9}; // ***use the index 0 of both array as dummy (this is important)***
long long segment_tree[(3*MAX)+5];


int main()
{

	init(1, 1, 8);

	long long sum = query(1, 1, 8, 3, 7);

	update(1, 1, 8, 3, 10);

	sum = query(1, 1, 8, 3, 7);

	return 0;
}

void init (int root, int Start, int End){

	if( Start == End ){
		segment_tree[root] = arr[Start];
		return;
	}

	int left = root * 2;
	int right = left + 1;
	int mid = (Start + End) / 2;

	init(left, Start, mid);
	init(right, mid+1, End);
	segment_tree[root] = segment_tree[left] + segment_tree[right];

	return;
}

long long query (int root, int Start, int End, int lowerRange, int upperRange){

	if( lowerRange>End || upperRange<Start ) return 0;

	if( Start>=lowerRange && End<=upperRange ) return segment_tree[root];

	int left = root * 2;
	int right = left + 1;
	int mid = (Start+End) / 2;

	I64 l = query(left, Start, mid, lowerRange, upperRange);
	I64 r = query(right, mid+1, End, lowerRange, upperRange);

	return l + r;
}

void update (int root, int Start, int End, int index, int newValue){

	if( index<Start || index>End ) return;

	if( Start==index && End==index ){
		segment_tree[root] = newValue;
		return;
	}

	int left = root * 2;
	int right = left + 1;
	int mid = (Start+End) / 2;

	update(left, Start, mid, index, newValue);
	update(right, mid+1, End, index, newValue);

	segment_tree[root] = segment_tree[left] + segment_tree[right];

	return;
}
