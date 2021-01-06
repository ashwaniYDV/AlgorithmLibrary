#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100000
#define MAX_VALUE 1000000

void BuildSegmentTree (int, int, int);
long long query (int, int, int, int, int);
void update (int, int, int, int, int);

int arr[] = {0, 4, -9, 3, 7, 1, 0, 2, 9}; // ***use the index 0 of both array as dummy (this is important)***
long long segment_tree[(3*MAX)+5];

int main()
{

	BuildSegmentTree (1, 1, 8);

	long long minValue = query(1, 1, 8, 2, 6);

	update(1, 1, 8, 2, 10);

	minValue = query(1, 1, 8, 1, 4);

	return 0;
}

void BuildSegmentTree (int root, int Start, int End){

	if( Start == End ){
		segment_tree[root] = arr[Start];
		return;
	}

	int left = root * 2;
	int right = left + 1;
	int mid = (Start+End) / 2;

	BuildSegmentTree (left, Start, mid);
	BuildSegmentTree (right, mid+1, End);

	segment_tree[root] = min( segment_tree[left], segment_tree[right]);
	
	return;
}

long long query (int root, int Start, int End, int lowerRange, int upperRange){

	if( lowerRange>End || upperRange<Start ) return MAX_VALUE;

	if( Start>=lowerRange && End<=upperRange ) return segment_tree[root];

	int left = root * 2;
	int right = left + 1;
	int mid = (Start+End) / 2;

	int l = query (left, Start, mid, lowerRange, upperRange);
	int r = query (right, mid+1, End, lowerRange, upperRange);

	return  min(l, r);
}

void update (int root, int Start, int End, int index, int newValue){

	if( index<Start || index>End ) return;

	if( index==Start && index==End ){
		segment_tree[root] = newValue;
		return;
	}

	int left = root * 2;
	int right = left + 1;
	int mid = (Start+End) / 2;

	update (left, Start, mid, index, newValue);
	update (right, mid+1, End, index, newValue);
	
	segment_tree[root] = min( segment_tree[left], segment_tree[right] );
}