// https://www.techiedelight.com/find-minimum-number-merge-operations-make-array-palindrome/
// https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/

/*
Given an array of positive integers. We need to make the given array a ‘Palindrome’. 
The only allowed operation is ”merging” (of two adjacent elements). 
Merging two adjacent elements means replacing them with their sum. 
The task is to find the minimum number of merge operations required to make the given array a ‘Palindrome’.

Input:  [6, 1, 3, 7]
Output: 1
Explanation: [6, 1, 3, 7] —> Merge 6 and 1 —> [7, 3, 7]
 
 
Input:  [6, 1, 4, 3, 1, 7]
Output: 2
Explanation: [6, 1, 4, 3, 1, 7] —> Merge 6 and 1 —> [7, 4, 3, 1, 7] —> Merge 3 and 1 —> [7, 4, 4, 7]
 
 
Input:  [1, 3, 3, 1]
Output: 0
Explanation: The list is already a palindrome
*/



void solve() {
    vector<int> arr = { 6, 1, 4, 3, 1, 7 };
    n = arr.size();

    int res = 0, i = 0, j = n-1;

    while (i <= j) {
        // If corner elements are same, problem reduces arr[i+1, .., j-1]
        if (arr[i] == arr[j]) {
            i++;
            j--;
        }

        // If left element is greater, then we merge right two elements
        else if (arr[i] > arr[j]) {
            // need to merge from tail.
            j--;
            arr[j] += arr[j+1] ;
            res++;
        }

        // If right element is greater, then we merge left two elements
        else if (arr[i] < arr[j]) {
            i++;
            arr[i] += arr[i-1];
            res++;
        }
    }

    cout << res << endl;
}
