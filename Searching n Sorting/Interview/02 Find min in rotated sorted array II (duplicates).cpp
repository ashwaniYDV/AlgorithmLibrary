// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// https://youtu.be/nhEMDKMB44g?si=2OdMI-0Fnp0ieeyK
// https://youtu.be/j3187M1P2Xg

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        int res = INT_MAX;
        
        while (lo <= hi) {
            // this is extra code we have to add when then are duplicates
            if( nums[lo] == nums[hi] ) {
                res = min(res, nums[lo]);
                ++lo; --hi;
                continue;
            }

            // array is already sorted perfectly
            if (nums[lo] <= nums[hi]) {
                res = min(res, nums[lo]);
                break;
            }

            int mid = (lo + hi) / 2;
            
            // left part is monotonic thus updating our answer 
            // and then we will look for answer in right part (lo = mid + 1)
            if (nums[lo] <= nums[mid]) {
                res = min(res, nums[lo]);
                lo = mid + 1;
            } 
            // right part is monotonic thus updating our answer
            // and then we will look for answer in left part (hi = mid - 1)
            else {
                res = min(res, nums[mid]);
                hi = mid - 1;
            }
        }
        
        return res;
    }
};




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
                continue;
            }
            
            // left part is monotonic thus pivot lies in right part
            if (nums[lo] <= nums[mid]) {
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
