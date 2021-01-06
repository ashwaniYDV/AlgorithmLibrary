/*
Counting Sort
-------------
An algorithm for sorting a collection of objects according to keys that 
are small integers. It operates by counting the number of objects that 
have each distinct key value, and using arithmetic on those counts to 
determine the positions of each key value in the output sequence.
-------------
Time Complexity : Best, Average and Worst Case : O(n+k)
Space Complexity : O(k)
Stable : Yes
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> count;

void counting_sort(vector<int> &v, size_t n, size_t k){
    size_t counter = 0;
    count.resize(k);
    for (size_t i = 0; i < n; i++){
        count[v[i]] += 1;
    }
    for (size_t i = 0; i < k; i++){
        while (count[i]){
            v[counter] = i;
            counter += 1;
            count[i] -= 1;
        }
    }
}