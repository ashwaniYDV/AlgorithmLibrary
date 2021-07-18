// https://www.geeksforgeeks.org/minimum-number-of-increasing-subsequences/

/*
Minimum number of increasing subsequences

Given an array of integers of size N, you have to divide it into the minimum number of “strictly increasing subsequences” 
For example: let the sequence be {1, 3, 2, 4}, then the answer would be 2. 
In this case, the first increasing sequence would be {1, 3, 4} and the second would be {2}.

Examples: 
Input : arr[] = {1 3 2 4} 
Output: 2 
There are two increasing subsequences {1, 3, 4} and {2}

Input : arr[] = {4 3 2 1} 
Output : 4

Input : arr[] = {1 2 3 4} 
Output : 1

Input : arr[] = {1 6 2 4 3} 
Output : 3
*/


/*
If we focus on the example we can see that the Minimum number of increasing subsequences equals to the 
length of longest decreasing subsequence where each element from the longest decreasing subsequence represents an increasing subsequence, 
so it can be found in N*Log(N) time complexity in the same way as longest increasing subsequence by multiplying all the elements with -1. 

We iterator over all elements and store in a sorted array (multiset) S the last element in each one of the increasing subsequences found so far 
and for every element X, we pick the largest element smaller than X -using binary search- in the S 
and replace it with X which means that we added the current element to increasing subsequence ending with X, 
otherwise, if there is no element smaller than X in S we insert it in S which forms a new increasing subsequence 
and so on until the last element and our answer in the last will be the size of S.
*/




// C++ program to count the Minimum number of
// increasing subsequences
#include <bits/stdc++.h>
using namespace std;

int MinimumNumIncreasingSubsequences(int arr[], int n) {
	multiset<int> last;

	// last element in each increasing subsequence
	// found so far
	for (int i = 0; i < n; i++) {

		// here our current element is arr[i]
		multiset<int>::iterator it = last.lower_bound(arr[i]);

		// iterator to the first element larger
		// than or equal to arr[i]
		if (it == last.begin())

			// if all the elements in last larger
			// than or to arr[i] then insert it into last
			last.insert(arr[i]);

		else {
			it--;

			// the largest element smaller than arr[i] is the number
			// before *it which is it--
			last.erase(it); // erase the largest element smaller than arr[i]
			last.insert(arr[i]); // and replace it with arr[i]
		}
	}
	return last.size(); // our answer is the size of last
}

// Driver program
int main() {
	int arr[] = { 8, 4, 1, 2, 9 };
	int n = sizeof(arr) / sizeof(int);
	cout << "Minimum number of increasing subsequences are : "
		<< MinimumNumIncreasingSubsequences(arr, n);
	return 0;
}
