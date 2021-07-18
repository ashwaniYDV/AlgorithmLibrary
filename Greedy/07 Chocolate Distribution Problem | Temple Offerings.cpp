// https://www.geeksforgeeks.org/chocolate-distribution-problem-set-2/
// https://www.geeksforgeeks.org/temple-offerings/
// https://practice.geeksforgeeks.org/problems/temple-offerings2831/1


// Chocolate Distribution Problem
/*
Given an array A[] consisting of N integers, where each value represents the marks of the ith student.
The task is to find the minimum number of chocolates required to be distributed such that:
a) each student should be awarded with at least one chocolate
b) a student with higher marks should be awarded more chocolates than his adjacent students.

Examples:
Input: A[] = {10, 30, 20}
Output: 4
Explanation : Since, 30 is larger than its adjacent, so the second student must get more chocolates. 
Therefore, the minimum chocolates can be distributed as {1, 2, 1} = 1 + 2 + 1 = 4
*/



// Temple Offerings
/*
Consider a devotee wishing to give offerings to temples along a mountain range. 
The temples are located in a row at different heights. 
Devotee is very religious and wants to offer each temple at least one offering. 
If two adjacent temples are at different altitudes, then the temple that is higher up should receive more offerings than the one that is at lower altitude. 
If two adjacent temples are at the same height, then their offerings relative to each other does not matter. 
The height of the N temples are given in the array arr[]. 
Find the minimum number of offerings required.

Example 1:
Input: heights = {1, 2, 2}
Output: 4
Explaination: offerings = {1, 2, 3}

Example 2:
Input: heights = {1, 4, 3, 6, 2, 1}
Output: 10
Explaination: offerings = {1, 2, 1, 3, 2, 1}
*/





/*
If we somehow manage to make sure that the temple at higher mountain is getting more offerings than our problem is solved. 
For this we can make use of greedy (since we have to compare only the neighbors of current index). 
The approach is to do two traversals (in two directions), 
first one to make sure that the temple at higher position from left gets more offerings
second one to make sure that the temple at higher position from the right gets more offerings

Time = O(n), Space = O(n)
*/

class Solution {
public:
    int offerings(int n, int A[]) {
        int B[n];

        B[0] = 1;

        // Traverse from left to right
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1])
                B[i] = B[i - 1] + 1;
            else
                B[i] = 1;
        }

        // Traverse from right to left
        int res = B[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] > A[i + 1])
                B[i] = max(B[i], B[i + 1] + 1);

            res += B[i];
        }

        return res;
    }
};





class Solution {
public:
    int offerings(int n, int A[]) {
        int left[n], right[n];

        left[0] = 1;
        // Traverse from left to right
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1])
                left[i] = left[i - 1] + 1;
            else
                left[i] = 1;
        }

        right[n - 1] = 1;
        // Traverse from right to left
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] > A[i + 1])
                right[i] = right[i + 1] + 1;
            else
                right[i] = 1;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += max(left[i], right[i]);
        }

        return res;
    }
};
