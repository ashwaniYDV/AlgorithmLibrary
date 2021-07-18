// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

/*
Please refer to leetcode link for a better explanation.

Given a wooden stick of length n units. The stick is labelled from 0 to n.
Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
You should perform the cuts in order, you can change the order of the cuts as you wish.
The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. 
When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). 
Return the minimum total cost of the cuts.


Example 1:
Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:
The first cut is done to a rod of length 7 so the cost is 7. 
The second cut is done to a rod of length 6 (i.e. the second part of the first cut), 
the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).
*/



/*
Intuition:
Similar to the problem Minimum Cost to Merge Stones.

Instead of considering the cost to cut, we can transform the problem to the cost to stick all sticks.

Then we have the problem "merge stones".
Though in the format of dp, they are exatly the same.


Explanation
Add the "cut" index 0 and n, then sort all stick position.
dp[i][j] means the minimum cost to stick all sticks between A[i] and A[j]


Complexity
Time O(N^3)
Space O(N^2)
*/





class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // just to get the length
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());
        int m = cuts.size();

        vector<vector<int>> dp(m, vector<int>(m, INT_MAX));

        for (int gap = 0; gap < m; gap++) {
            for (int i = 0, j = gap; j < m; i++, j++) {
                if (gap == 0) {
                    dp[i][j] = 0;
                } else if (gap == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = INT_MAX;
                    for (int k = i + 1; k < j; k++) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                    }
                }
            }
        }

        return dp[0][m - 1];
    }
};
