/*
https://leetcode.com/problems/find-the-duplicate-number/

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. 
Assume that there is only one duplicate number, find the duplicate one.

1) You must not modify the array (assume the array is read only).
2) You must use only constant, O(1) extra space.
3) Your runtime complexity should be less than O(n2).
4) There is only one duplicate number in the array, but it could be repeated more than once.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        
        int slow = nums[0];
        int fast = nums[0];
        while(1){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        slow = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow; // fast
    }
};
