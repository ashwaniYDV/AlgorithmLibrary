// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// https://youtu.be/w2G2W8l__pc?si=jEdynq1WM9maZ1Yc

/*
Consider case like this
arr = 3 3 3 3 4 0 1 2 3

lo = 0, hi = n-1

When nums[lo] == nums[mid] == nums[hi]
so in this trickly case, just updat left and right
if( (nums[lo] == nums[mid]) && (nums[hi] == nums[mid]) ) {
    ++lo; --hi;
}
and continue the while loop.
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (target == nums[mid]) {
                return true;
            }
            
            // the only difference from the first one, trickly case, just update left and right
            if( (nums[left] == nums[mid]) && (nums[mid] == nums[right]) ) {
                ++left; --right;
                continue;
            }
            
            // If the entire left part is monotonically increasing, which means the pivot point is on the right part
            if (nums[left] <= nums[mid]) {
                //must use "<=" at here since we need to make sure target is in the left part,
                //then safely drop the right part
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    //right bias
                    left = mid + 1;
                }
            }

            // If the entire right part is monotonically increasing, which means the pivot point is on the left part
            else {
                //must use "<=" at here since we need to make sure target is in the right part,
                //then safely drop the left part
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
















class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                return true;
            }

            if (nums[left] == nums[mid]) {
                left++;
                continue;
            }
            if (nums[mid] == nums[right]) {
                right--;
                continue;
            }
            
            // If the entire left part is monotonically increasing, which means the pivot point is on the right part
            if (nums[left] < nums[mid]) {
                //must use "<=" at here since we need to make sure target is in the left part,
                //then safely drop the right part
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    //right bias
                    left = mid + 1;
                }
            }

            // If the entire right part is monotonically increasing, which means the pivot point is on the left part
            else if(nums[mid] < nums[right]) {
                //must use "<=" at here since we need to make sure target is in the right part,
                //then safely drop the left part
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
