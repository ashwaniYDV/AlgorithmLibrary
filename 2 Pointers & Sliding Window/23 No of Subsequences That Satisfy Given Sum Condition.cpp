// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/

/*
You are given an array of integers nums and an integer target.
Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. 
Since the answer may be too large, return it modulo 109 + 7.

Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)

Input: nums = [3,3,6,8], target = 10
Output: 6
Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
Example 3:

Input: nums = [2,3,3,4,6,7], target = 12
Output: 61
Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
Number of valid subsequences (63 - 2 = 61).
 

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
1 <= target <= 10^6
*/


class Solution {
public:
    int MOD = 1e9+7;
    
    int binpow(long long n, long long p, long long mod) {
        long long res = 1;
        n %= mod;
        while (p > 0) {
            if (p & 1) res = (res * n) % mod;
            n = (n * n) % mod;
            p >>= 1;
        }
        return (int)res;
    }
    
    int numSubseq(vector<int>& a, int target) {
        int n = a.size();
        sort(a.begin(), a.end());

        int l = 0, r = n - 1;
        int res = 0;
        while(l <= r) {
            int sum = a[l] + a[r];
            if(sum <= target) {
                int cnt = binpow(2, r - l, MOD);
                res = (res + cnt) % MOD;
                l++;
            } else {
                r--;
            }
        }

        return res;
    }
};
