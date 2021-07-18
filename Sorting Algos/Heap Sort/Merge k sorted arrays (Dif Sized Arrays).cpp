// https://www.geeksforgeeks.org/merge-k-sorted-arrays-set-2-different-sized-arrays/
// https://www.geeksforgeeks.org/merge-k-sorted-arrays/

/*
Given k sorted arrays of possibly different sizes, merge them and print the sorted output.

Examples: 
Input: 
k = 3 
arr[][] = { {1, 3},
          {2, 4, 6},
          {0, 9, 10, 11}};
Output: 0 1 2 3 4 6 9 10 11 

Input: 
k = 2
arr[][] = { {1, 3, 20},
          {2, 4, 6}};
Output: 1 2 3 4 6 20 
*/



// C++ program to merge k sorted arrays of size n each.
#include <bits/stdc++.h>
using namespace std;


// {value, { index of array,  index in the array}}
// {arr[i][j], { i,  j}}
typedef pair<int, pair<int, int> > ppi;

vector<int> mergeKArrays(vector<vector<int> > arr) {
    vector<int> output;

    // Create a min heap with k heap nodes.
    // Every heap node has first element of an array
    priority_queue<ppi, vector<ppi>, greater<ppi> > pq;

    for (int i = 0; i < arr.size(); i++) {
        pq.push({ arr[i][0], { i, 0 } });
    }

    // Now one by one get the minimum element from min heap
    // and replace it with next element of its array
    while (pq.empty() == false) {
        ppi cur = pq.top();
        pq.pop();

        // i ==> Array Number
        // j ==> Index in the array number
        int i = cur.second.first;
        int j = cur.second.second;

        output.push_back(cur.first);

        // The next element belongs to same array as current.
        if (j + 1 < arr[i].size()) {
            pq.push({ arr[i][j + 1], { i, j + 1 } });
        }
    }

    return output;
}

int main() {
    vector<vector<int> > arr{ { 2, 6, 12 },
        { 1, 9 },
        { 23, 34, 90, 2000 } };

    vector<int> output = mergeKArrays(arr);

    for (auto x : output) cout << x << " ";
    return 0;
}
