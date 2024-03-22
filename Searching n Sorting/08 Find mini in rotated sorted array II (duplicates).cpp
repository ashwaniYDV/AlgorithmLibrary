// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

// https://youtu.be/j3187M1P2Xg

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
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        
        while (lo < hi) {
            if (nums[lo] < nums[hi]) return nums[lo];
            
            int mid = (lo + hi) / 2;
            
            // the only difference from the first one, trickly case, just updat left and right
            if( (nums[lo] == nums[mid]) && (nums[hi] == nums[mid]) ) {
                ++lo; --hi;
            }
            
            // left part is monotonic thus pivot lies in right part
            else if (nums[lo] <= nums[mid]) {
                lo = mid + 1;
            } 
            // right part is monotonic thus pivot lies in left part
            else {
                hi = mid;
            }
        }
        
        return nums[lo];
    }
};











class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        
        while (lo < hi) {
            if (nums[lo] < nums[hi]) return nums[lo];
            
            int mid = (lo + hi) / 2;
            
            if (nums[lo] < nums[mid]) {
                lo = mid + 1;
            } else if (nums[mid] < nums[hi]) {
                hi = mid;
            } else {
                if (nums[lo] == nums[mid]) lo++;
                if (nums[mid] == nums[hi]) hi--;
            }
        }
        
        return nums[lo];
    }
};
