// https://leetcode.com/problems/maximum-width-ramp/description/

/*
A ramp is a pair (i, j) for which i < j and nums[i] <= nums[j]. 
The width of such a ramp is j - i.
Return the max width of a ramp in nums. 
If there is no ramp in nums, return 0. 

Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.

Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.
*/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        
        stack<int> monotonSt;
        monotonSt.push(0);

        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[monotonSt.top()]) {
                monotonSt.push(i);
            }
        }

        int res = 0;
        for(int r = n-1; r >= 0; r--) {
            while(!monotonSt.empty() && nums[monotonSt.top()] <= nums[r]) {
                int l = monotonSt.top();
                res = max(res, r - l);
                monotonSt.pop();
            }
        }
        return res;
    }
};