// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
// https://youtu.be/XjLT4TaXsgw

/*
Given an integer array nums, return the number of all the arithmetic subsequences of nums.
A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
*/


/*
dp[i] = hashmap {key = common difference, value = no of APs having atleast 2 elements}
dp[i][j] = no of APs having >= 2 elements ending at index i whose common difference is j 
*/

class Solution {
public:
    using ll = long long;
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        vector<unordered_map<ll, ll>> dp(n);
        int res = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                ll dif = (ll)nums[i] - (ll)nums[j];
                ll APsEndingOnJ = dp[j][dif];

                res += APsEndingOnJ;

                dp[i][dif] += APsEndingOnJ + 1;
            }
        }

        return res;
    }
};
