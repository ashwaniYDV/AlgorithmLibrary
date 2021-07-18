// https://www.geeksforgeeks.org/maximum-sum-path-across-two-arrays/
// https://practice.geeksforgeeks.org/problems/max-sum-path-in-two-arrays/1


/*
Given two sorted arrays A1 and A2 of size N1 and N2 respectively. 
Each array contains only distinct elements but may have some elements in common with the other array. 
Find the sum of the maximum sum path to reach from the beginning of any array to end of any of the two arrays.
We can switch from one array to another array only at the common elements.

Note: The common elements do not have to be at the same indexes.


Input: ar1[] = {2, 3, 7, 10, 12}
       ar2[] = {1, 5, 7, 8}
Output: 35
Explanation: 35 is sum of 1 + 5 + 7 + 10 + 12.
We start from the first element of arr2 which is 1, then we
move to 5, then 7.  From 7, we switch to ar1 (as 7 is common)
and traverse 10 and 12.

Input: ar1[] = {10, 12}
       ar2 = {5, 7, 9}
Output: 22
Explanation: 22 is the sum of 10 and 12.

Input: ar1[] = {2, 3, 7, 10, 12, 15, 30, 34}
        ar2[] = {1, 5, 7, 8, 10, 15, 16, 19}
Output: 122
Explanation: 122 is sum of 1, 5, 7, 8, 10, 12, 15, 30, 34


Input: ar1[] = 1 1 2 2 2 2 1 1 2 2 2
       ar2[] = 2 2 2 1 1 2 2 2 2 1 1
Output: 22
*/


/*
Efficient Approach: 
The idea is to do something similar to merge process of merge sort. 
This involves calculating the sum of elements between all common points of both arrays. 
Whenever there is a common point, compare the two sums and add the maximum of two to the result.
*/

class Solution {
public:
    int max_path_sum(int a1[], int a2[], int n1, int n2) {
        int sum1 = 0, sum2 = 0, res = 0;
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (a1[i] < a2[j]) {
                sum1 += a1[i];
                i++;
            } else if (a2[j] < a1[i]) {
                sum2 += a2[j];
                j++;
            } else {
                res += max(sum1, sum2) + a1[i];
                sum1 = 0, sum2 = 0;
                i++; j++;
            }
        }

        while (i < n1) {
            sum1 += a1[i++];
        }

        while (j < n2) {
            sum2 += a2[j++];
        }

        res += max(sum1, sum2);

        return res;
    }
};
