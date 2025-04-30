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
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        int l = 0, r = n - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            int midMinusOne = mid - 1 >= 0 ? a[mid - 1] : INT_MIN;
            int midPlusOne = mid + 1 < n ? a[mid + 1] : INT_MIN;

            if(midMinusOne < a[mid] && midPlusOne < a[mid]) {
                return mid;
            }
            
            // right side of mid is increasing, thus answer lies in right part
            if (midPlusOne > a[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return 0;
    }
};
