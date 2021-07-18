// https://leetcode.com/problems/single-element-in-a-sorted-array/
// https://youtu.be/AZOmHuHadxQ?si=GN4e1BWeWMjHKR7O

/*
Given a sorted array where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Explanation
===========
        0  1  2  3  4  5  6  7  8
nums = [1, 1, 2, 2, 3, 4, 4, 5, 5]

let's classify the indexes as even and odd
  0  1        2  3        4         5  6          7  8
 (1, 1)      (2, 2)      (3)       (4, 4)        (5, 5)
even, odd   even, odd             odd, even    odd, even
*/

// Method 1 (long code)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) {
            return nums[0];
        }
        if (nums[n - 1] != nums[n - 2]) {
            return nums[n - 1];
        }

        int lo = 0, hi = n-1;

        while(lo <= hi) {
            int mid = (lo + hi) / 2;

            if((mid - 1 >= 0 && nums[mid] != nums[mid - 1]) && (mid + 1 < n && nums[mid] != nums[mid + 1])) {
                return nums[mid];
            }

            // mid is odd
            if(mid % 2 == 1) {
                // single element is present in right half
                if(mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                    lo = mid + 1;
                } 
                // single element is present in left half
                else if(mid + 1 < n && nums[mid] == nums[mid + 1]) {
                    hi = mid - 1;
                }
            } 
            // mid is even
            else {
                // single element is present in left half
                if(mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                    hi = mid - 1;
                } 
                // single element is present in right half
                else if(mid + 1 < n && nums[mid] == nums[mid + 1]) {
                    lo = mid + 1;
                }
            }

            /*
            // single element is present in right half
            if((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                lo = mid + 1;
            } 
            // single element is present in left half
            else {
                hi = mid - 1;
            }
            */
        }
        return -1;
    }
};







// Method 2 (shorter code)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) {
            return nums[0];
        }
        if (nums[n - 1] != nums[n - 2]) {
            return nums[n - 1];
        }

        // we can neglect 0th and n-1th position since already checked
        int lo = 1, hi = n-2;

        while(lo <= hi) {
            int mid = (lo + hi) / 2;

            if((nums[mid] != nums[mid - 1]) && (nums[mid] != nums[mid + 1])) {
                return nums[mid];
            }

            // single element is present in right half
            if((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                lo = mid + 1;
            } 
            // single element is present in left half
            else {
                hi = mid - 1;
            }
        }
        return -1;
    }
};