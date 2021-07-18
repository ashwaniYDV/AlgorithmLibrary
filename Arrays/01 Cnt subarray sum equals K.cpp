// https://leetcode.com/problems/subarray-sum-equals-k/

/*
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

Constraints:
1 <= nums.length <= 2 * 10^4
-1000 <= nums[i] <= 1000
-10^7 <= k <= 10^7

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long prefSum = 0;
        int res = 0;
        map<long long, int> mp;
        // to take into account those subarrays that begin with index 0
        mp[0] = 1;
        
        for(int i = 0; i < nums.size(); i++){
            prefSum += nums[i];
            
            // count all subarrays ending at idx i and having sum = k
            res += mp[prefSum - k];
            
            mp[prefSum]++;
        }
        return res;
    }
};






class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefSum = 0;
        map<int, int> mp;
        
        int res = 0;
        
        for(int i = 0; i < nums.size(); i++){
            prefSum += nums[i];

            if(prefSum == k) res++;
            
            res += mp[prefSum - k];
            mp[prefSum]++;
        }
        return res;
    }
};
