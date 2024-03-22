// https://leetcode.com/problems/search-in-rotated-sorted-array/
// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14436/Revised-Binary-Search/191339
// https://youtu.be/oTfPJKGEHcc


/*
My intuitive thinking: 
The main idea is that we need to find some parts of array that we could adopt binary search on that, 
which means we need to find some completed sorted parts, then determine whether target is in left part or right part. 
There is at least one segment (left part or right part) is monotonically increasing.
*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (target == nums[mid]) {
                return mid;
            }
            
            // If the entire left part is monotonically increasing, which means the pivot point is on the right part
            if (nums[left] <= nums[mid]) {
                // must use "<=" at here since we need to make sure target is in the left part,
                // then safely drop the right part
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
        return -1;
    }
};

















class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r = nums.size()-1;
        while(l <= r) {
            int m = l+(r-l)/2;
            if(nums[m] == target) {
                return m;
            }
            if(nums[l] <= nums[m]) {
                if(target >= nums[l] && target < nums[m]) r = m-1;
                else l = m+1;
            } else {
                if(target > nums[m] && target <= nums[r]) l = m+1;
                else r = m-1;
            }
        }
        return -1;
    }
};
