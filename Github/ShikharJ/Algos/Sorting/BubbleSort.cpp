/*
Bubble Sort
-----------
A simple sorting algorithm that repeatedly swaps pairs of 
wrongly placed adjacent elements. Also known as sinking sort.
Only advantage of using Bubble Sort is due to the best case time 
complexity.
Use order = +/- 1 for increasing and decreasing orders respectively.
-----------
Time Complexity : Best Case : O(n)
                  Average and Worst Case : O(n^2)
Space Complexity : O(1)
Stable : Yes
In-Place : Yes
Online : No
*/

#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int> &v, int order){
    for (size_t i = 0; i < v.size() - 1; i++){
        for (size_t j = 0; j < v.size() - i - 1; j++){
            if (order * values[j] > order * values[j + 1]){
                swap(v[j], v[j + 1]);
            }
        }
    }
}
