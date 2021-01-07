// https://leetcode.com/problems/dungeon-game/

/*
abs(DP[i][j]) represents min strength the Knight should have if he starts the game from the (i, j)th point to reach (n-1, m-1)th point
*/ 

// Recursive
class Solution {
public:
    int n, m;
    int calculate(int i, int j, vector<vector<int>>& dungeon, vector<vector<int>>& dp) {
        if(dp[i][j] != -1) return dp[i][j];
        
        // base cases
        if (i == n - 1 && j == m - 1) {
            return dp[i][j] = min(0, dungeon[i][j]);
        }
        // last row
        if (i == n - 1) {
            return dp[i][j] = min(0, dungeon[i][j] + calculate(i, j+1, dungeon, dp));
        }
        // last column
        if (j == m - 1) {
            return dp[i][j] = min(0, dungeon[i][j] + calculate(i+1, j, dungeon, dp));
        }

        return dp[i][j] = min(0, dungeon[i][j] + max(calculate(i + 1, j, dungeon, dp), calculate(i, j+1, dungeon, dp)));
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
        m = dungeon[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return 1 + abs(calculate(0, 0, dungeon, dp));
    }
};


// DP
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        
        for(int i = n-1; i >= 0; --i) {
            for(int j = m-1; j >= 0; --j) {
                //Bottom-Right cell (Princess Cell)
                if(i == n-1 && j == m-1) {
                    dp[i][j] = min(0, dungeon[i][j]);
                }
                //last row
                else if(i == n-1) {
                    dp[i][j] = min(0, dungeon[i][j] + dp[i][j+1]);
                }
                //last col
                else if(j == m-1) {
                    dp[i][j] = min(0, dungeon[i][j] + dp[i+1][j]);
                }
                else {
                    dp[i][j] = min(0, dungeon[i][j] + max(dp[i][j+1], dp[i+1][j]));
                }
            }
        }
        return abs(dp[0][0])+1;
    }
};
