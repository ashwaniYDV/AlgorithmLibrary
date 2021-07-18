// https://leetcode.com/problems/minimum-cost-to-merge-stones/
// https://leetcode.com/problems/minimum-cost-to-merge-stones/discuss/247567/JavaC++Python-DP

/*
There are n piles of stones arranged in a row. The ith pile has stones[i] stones.
A move consists of merging exactly k consecutive piles into one pile, and the cost of this move is equal to the total number of stones in these k piles.
Return the minimum cost to merge all piles of stones into one pile. If it is impossible, return -1.

Example 1:
Input: stones = [3,2,4,1], k = 2
Output: 20
Explanation: We start with [3, 2, 4, 1].
We merge [3, 2] for a cost of 5, and we are left with [5, 4, 1].
We merge [4, 1] for a cost of 5, and we are left with [5, 5].
We merge [5, 5] for a cost of 10, and we are left with [10].
The total cost was 20, and this is the minimum possible.
*/


class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if ((n - 1) % (K - 1)) return -1;

        vector<int> prefix(n + 1);
        for (int i = 0; i <  n; i++)
            prefix[i + 1] = prefix[i] + stones[i];

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; i++, j++) {
                if (gap == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = INT_MAX;
                    for (int mid = i; mid < j; mid += K - 1) {
                        dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
                    }
                    if ((j - i) % (K - 1) == 0) {
                        dp[i][j] += prefix[j + 1] - prefix[i];
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
