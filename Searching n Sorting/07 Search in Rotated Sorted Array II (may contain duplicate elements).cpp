// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

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
            
            //if left part is monotonically increasing, or the pivot point is on the right part
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

            //if right part is monotonically increasing, or the pivot point is on the left part
            else if(nums[mid] < nums[right]) {
                //must use "<=" at here since we need to make sure target is in the right part,
                //then safely drop the left part
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            else {
                if (nums[left] == nums[mid]) left++;
                if (nums[mid] == nums[right]) right--;
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
            
            // the only difference from the first one, trickly case, just updat left and right
            if( (nums[left] == nums[mid]) && (nums[right] == nums[mid]) ) {
                ++left; --right;
            }
            
            //if left part is monotonically increasing, or the pivot point is on the right part
            else if (nums[left] <= nums[mid]) {
                //must use "<=" at here since we need to make sure target is in the left part,
                //then safely drop the right part
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    //right bias
                    left = mid + 1;
                }
            }

            //if right part is monotonically increasing, or the pivot point is on the left part
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
