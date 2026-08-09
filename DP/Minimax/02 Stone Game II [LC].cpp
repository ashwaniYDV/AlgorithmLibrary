// https://leetcode.com/problems/stone-game-ii/description/

/*
Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. 
The objective of the game is to end with the most stones.
Alice and Bob take turns, with Alice starting first.
On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.
The game continues until all the stones have been taken.
Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.


Example 1:
Input: piles = [2,7,9,4,4]
Output: 10
Explanation:
If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 stones in total.
If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 stones in total.
So we return 10 since it's larger.

Example 2:
Input: piles = [1,2,3,4,5,100]
Output: 104

 
Constraints:
1 <= piles.length <= 100
1 <= piles[i] <= 10^4
*/

class Solution {
public:
    int n;

    int f(int i, int isAlice, int m, auto& p, auto& dp) {
        if (i >= n) return 0;

        if(dp[i][isAlice][m] != -1) return dp[i][isAlice][m];

        // Alice wants MAX
        if (isAlice) {
            int sum = 0;
            int res = 0;

            for (int j = i; j < min(n, i + 2 * m); j++) {
                sum += p[j];
                int x = j - i + 1;
                res = max(res, sum + f(j + 1, 0, max(m, x), p, dp));
            }

            return dp[i][isAlice][m] = res;
        }

        // Bob wants MIN Alice's final score
        else {
            int res = INT_MAX;

            for (int j = i; j < min(n, i + 2 * m); j++) {
                int x = j - i + 1;
                res = min(res, f(j + 1, 1, max(m, x), p, dp));
            }

            return dp[i][isAlice][m] = res;
        }
    }

    int stoneGameII(vector<int>& p) {
        n = p.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2*n + 1, -1)));
        return f(0, 1, 1, p, dp);
    }
};
