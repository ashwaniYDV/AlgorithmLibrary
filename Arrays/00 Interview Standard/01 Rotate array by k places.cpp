// Left rotate by k places
// https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1

/*
k = 2
nums = 1 2 3 4 5

Step1: reverse the two parts
    1 2 3 4 5  =  2 1 5 4 3
    === =====     === =====

Step2: reverse whole array
    3 4 5 1 2
    =========

Ans = 3 4 5 1 2
*/

class Solution{
public:
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int k, int n){
        // since k is cyclic
        k = k % n;

        reverse(arr, arr + k);
        reverse(arr + k, arr + n);
        reverse(arr, arr + n);
    }
};







// Right rotate by k places
// https://leetcode.com/problems/rotate-array/

/*
k = 3
nums = 1 2 3 4 5 6 7

Step1: reverse the two parts
    1 2 3 4 5 6 7  = 4 3 2 1 7 6 5
    ======= =====    ======= =====

Step2: reverse whole array
    4 3 2 1 7 6 5
    =============

Ans = 5 6 7 1 2 3 4
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // since k is cyclic
        k = k % n;

        reverse(nums.begin(), nums.begin() + (n - k));
        reverse(nums.begin() + (n - k), nums.end());
        reverse(nums.begin(), nums.end());
    }
};