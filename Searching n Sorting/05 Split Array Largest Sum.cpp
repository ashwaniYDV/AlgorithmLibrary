// https://leetcode.com/problems/split-array-largest-sum/

/*
Given an array nums which consists of non-negative integers and an integer m.
You can split the array into m non-empty continuous subarrays.
Write an algorithm to minimize the largest sum among these m subarrays.

Example 1:
Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays. The best way is to split it into [7,2,5] and [10,8], 
where the largest sum among the two subarrays is only 18.
*/

// FFFFFTTTTT

class Solution {
public:
    bool check(int mid, vector<int>& nums, int m) {
        long long sum = 0, cnt = 0;
        for(int x: nums) {
            sum += x;
            if(sum > mid) {
                cnt++;
                sum = x;
            }
        }
        if(sum) cnt++;

        return cnt <= m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        long long lo = *max_element(nums.begin(), nums.end());
        long long hi = accumulate(nums.begin(), nums.end(), 0);
        
        while(lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if(check(mid, nums, m)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;

        /*
        while(lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if(check(mid, nums, m)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
        */
    }
};
