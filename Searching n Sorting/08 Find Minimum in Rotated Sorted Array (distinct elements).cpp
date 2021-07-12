// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

/*
Classic binary search problem.

Looking at subarray with index [lo, hi]. We can find out that if the first member is less than the last member, there's no rotation in the array. 
So we could directly return the first element in this subarray.

If the first element is larger than the last one, then we compute the element in the middle, and compare it with the first element. 
If value of the element in the middle is larger than the first element, we know the rotation is at the second half of this array. 
Else, it is in the first half in the array.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        
        while (lo < hi) {
            if (nums[lo] < nums[hi]) return nums[lo];
            
            int mid = (lo + hi) / 2;
            
            if (nums[lo] <= nums[mid]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        return nums[lo];
    }
};
