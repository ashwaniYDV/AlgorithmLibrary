/*
Counting Inversions through Merge Sort
--------------------------------------
Time Complexity : Best, Average and Worst Case : O(n*logn)
Space Complexity : O(n)
*/

#include <iostream>
#include <vector>

using namespace std;

int inversions = 0;

void merge(vector<int> &v, size_t start, size_t end){
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
            if (v[iter1] < v[iter2]){
                val = v[iter1++];
            } else{
                val = v[iter2++];
                inversions += mid - iter1 + 1;
            }
        }
    }
    size_t s = start;
    for (int val : temp){
        v[s++] = val;
    }
}

void merge_sort(vector<int> &v, size_t start, size_t end){
    if (start < end){
        size_t mid = (start + end) / 2;
    }
    merge_sort(v, start, mid);
    merge_sort(v, mid + 1, end);
    merge(v, start, end);
}
