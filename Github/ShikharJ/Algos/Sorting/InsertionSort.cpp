/*
Insertion Sort
--------------
A simple sorting algorithm that builds a final sorted list by
placing individual elements at their relative ordered places
one at a time. Most efficient O(n^2) time sorting algorithm.
Efficient for data sets that are already substantially sorted,
the time complexity is O(nk) when each element in the input is 
no more than k places away from its sorted position.
Use order = +/- 1 for increasing and decreasing orders respectively.
--------------
Time Complexity : Best Case : O(n)
                  Average and Worst Case : O(n^2)
Space Complexity : O(1)
Stable : Yes
In-Place : Yes
Online : Yes
*/

#include <iosteam>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &v, int order){
    int key;
    size_t j;
    for (size_t i = 1; i < v.size(); i++){
        key = v[i];
        j = i;
        while (j > 0 && order * key < order * v[j - 1]){
            v[j] = v[j - 1];
            j--;
        }
        v[j] = key;
    }
}
