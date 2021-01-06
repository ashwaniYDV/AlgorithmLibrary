/*
Selection Sort
--------------
A simple in-place comparison sorting algorithm. It sorts a list by 
finding the smallest / largest element (considering sorting order) from
the unsorted sublist and swapping it with the leftmost unsorted element, 
moving the sublist boundaries one element to the right.
Performs worst than insertion sort, but has advantaages in situations
where auxiliary memory is limited.
Use order = +/- 1 for increasing and decreasing orders respectively.
--------------
Time Complexity : Best, Average and Worst Case : O(n^2)
Space Complexity : O(1)
Stable : Yes
In-Place : Yes
Online : No
*/

#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int> &v, int order){
    size_t n = v.size();
    for (size_t gap = n / 2; gap > 0; gap /= 2){
        for (size_t i = gap; i < n; i++){
            int temp = v[i];
            size_t j = i;
            while (j >= gap and v[j - gap] * order > temp * order){
                v[j] = v[j - gap];
                j -= gap;
            }
            v[j] = temp;
        }
    }
}
