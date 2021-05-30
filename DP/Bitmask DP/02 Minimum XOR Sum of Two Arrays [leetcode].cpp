// https://leetcode.com/contest/biweekly-contest-53/problems/minimum-xor-sum-of-two-arrays/

/*
You are given two integer arrays nums1 and nums2 of length n.
The XOR sum of the two integer arrays is (nums1[0] XOR nums2[0]) + (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1] XOR nums2[n - 1]).
For example, the XOR sum of [1,2,3] and [3,2,1] is equal to (1 XOR 3) + (2 XOR 2) + (3 XOR 1) = 2 + 0 + 2 = 4.
Rearrange the elements of nums2 such that the resulting XOR sum is minimized.
Return the XOR sum after the rearrangement.

Constraints:
n == nums1.length
n == nums2.length
1 <= n <= 14
0 <= nums1[i], nums2[i] <= 10^7
*/

class Solution {
public:
    int dp[1 << 20];
    int n;

    int go(int mask, vector<int>& nums1, vector<int>& nums2) {
        int i = __builtin_popcount(mask);

        if(i == n) return 0;

        if (dp[mask] != -1) { 
            return dp[mask];
        }

        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!(mask & (1 << j))) {
                ans = min(ans, (nums1[i]^nums2[j]) + go(mask | (1 << j), nums1, nums2));
            }
        }
        return dp[mask] = ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        memset(dp, -1, sizeof dp);
        return go(0, nums1, nums2);
    }
};
