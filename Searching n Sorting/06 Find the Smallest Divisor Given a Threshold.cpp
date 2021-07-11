// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

/*
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, 
and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

It is guaranteed that there will be an answer.
*/

// FFFFFTTTTT

class Solution {
public:
    bool check(int mid, vector<int>& nums, int threshold) {
        int sum = 0;
        for (int x: nums) {
            sum += (x + mid - 1) / mid;
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = 1e6;
        
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            
            if (check(mid, nums, threshold)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
