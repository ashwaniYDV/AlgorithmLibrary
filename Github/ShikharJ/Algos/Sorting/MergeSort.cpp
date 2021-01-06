/*
Merge Sort
----------
An efficient, comparison-based, divide and conquer sorting algorithm.
It divides input array into two halves, recursively calls itself for 
the two halves and then merges the two sorted halves.
Use order = +/- 1 for increasing and decreasing orders respectively.
----------
Time Complexity : Best, Average and Worst Case : O(n*logn)
Space Complexity : O(n)
Stable : Yes
In-Place : No
Online : No
*/

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &v, size_t start, size_t end, int order){
    size_t mid = (start + end) / 2;
    size_t iter1 = start;
    size_t iter2 = mid + 1;
    vector<int> temp(end - start + 1);
    for (int &val : temp){
        if (iter1 > mid){
            val = v[iter2++];
        } else if (iter2 > end){
            val = v[iter1++];
        } else{
            if (order * v[iter1] < order * v[iter2]){
                val = v[iter1++];
            } else{
                val = v[iter2++];
            }
        }
    }
    size_t s = start;
    for (int val : temp){
        v[s++] = val;
    }
}

void merge_sort(vector<int> &v, size_t start, size_t end, int order){
    if (start < end){
        size_t mid = (start + end) / 2;
    }
    merge_sort(v, start, mid, order);
    merge_sort(v, mid + 1, end, order);
    merge(v, start, end, order);
}
