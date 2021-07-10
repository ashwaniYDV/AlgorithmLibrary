// https://leetcode.com/problems/find-peak-element/
// https://youtu.be/r7U0N2EE_l8

/*
A peak element is an element that is strictly greater than its neighbors.
Given an integer array nums where nums[i] != nums[i + 1] for all valid i, find a peak element, and return its index. 
If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞.
You must write an algorithm that runs in O(log n) time.
Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Constraints:
nums[i] != nums[i + 1] for all valid i.
-231 <= nums[i] <= 231 - 1
*/

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int low = 0;
        int high = num.size()-1;
        
        while(low < high) {
            int mid1 = (low+high)/2;
            int mid2 = mid1+1;
            if(num[mid1] < num[mid2])
                low = mid2;
            else
                high = mid1;
        }
        return low;
    }
};
