// https://leetcode.com/problems/find-the-duplicate-number/
// https://youtu.be/32Ll35mhWg0?si=5EJ4SQ9zq5pDhArN

/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.

Input: nums = [1,3,4,2,2]
Output: 2

Input: nums = [3,1,3,4,2]
Output: 3

Input: nums = [1,1]
Output: 1
*/


// Floyd cycle detection
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        
        int slow = nums[0];
        int fast = nums[0];
        while(1) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) {
                slow = nums[0];
                while(slow != fast) {
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
        }
    }
};



class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            while (arr[i] != arr[arr[i] - 1]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return arr[i];
            }
        }
        return 0;
    }
};