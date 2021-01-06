/*
Shell Sort
----------
An in-place comparison sort. It can be seen as either a generalization 
of bubble sort or insertion sort, but faster than both. The method starts 
by sorting pairs of elements far apart from each other, then progressively 
reducing the gap between elements to be compared. Starting with far apart 
elements, it can move some out-of-place elements into position faster than a 
simple nearest neighbor exchange. The running time of Shellsort is heavily 
dependent on the gap sequence it uses. For many practical variants, 
determining their time complexity remains an open problem.
The original 1959 algorithm is implemented here (using shell sequence).
Use order = +/- 1 for increasing and decreasing orders respectively.
----------
Time Complexity : Best Case : O(n*logn^2)
                  Average and Worst Case : O(n^2)
Space Complexity : O(1)
Stable : No
In-Place : Yes
Online : No
*/

#include <iostream>
#include <vector>

using namespace std;

void shell_sort(vector<int> &v, int order){
    for (size_t gap = v.size() / 2; gap > 0; gap /= 2){
        for (size_t i = gap; i < v.size(); i++){
            int element = v[i];
            size_t j;
            for (j = i; j >= gap && order * v[j - gap] > element; j -= gap){
                v[j] = v[j - gap];
            }
            v[j] = element;
        }
    }
}
