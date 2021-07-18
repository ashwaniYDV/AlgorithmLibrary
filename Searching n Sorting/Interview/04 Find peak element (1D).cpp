// https://leetcode.com/problems/find-peak-element/
// https://youtu.be/cXxmbemS6XM?si=0uGPZ3C5adhtSByW

/*
A peak element is an element that is strictly greater than its neighbors.
Given an integer array nums where nums[i] != nums[i + 1] for all valid i, find a peak element, and return its index. 
If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞.

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        // we can neglect 0th and n-1th position since already checked
        int lo = 1, hi = n-2;

        while(lo <= hi) {
            int mid = (lo + hi) / 2;

            if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) {
                return mid;
            }

            // left side of mid is increasing, thus answer lies in right part
            // note: we dont have to check nums[lo] < nums[mid]
            if(nums[mid-1] < nums[mid]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return -1;
    }
};
