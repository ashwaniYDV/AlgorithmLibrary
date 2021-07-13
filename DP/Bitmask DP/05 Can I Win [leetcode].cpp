// https://leetcode.com/problems/can-i-win/

/*
In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. 
The player who first causes the running total to reach or exceed 100 wins.
What if we change the game so that players cannot re-use integers?
For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.
Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise, return false. 
Assume both players play optimally.
*/

class Solution {
public:
    int dp[1 << 20];
    
    bool dfs(int mask, int M, int desiredTotal) {
        /*
        The player who first causes the running total to reach or exceed the desiredTotal wins. 
        If a player sees negative total in his turn, it means 
        the other player causes the running total to exceed the desiredTotal 
        in the previous move and wins.
        */
        if (desiredTotal <= 0) {
            return false;
        }
        
        if (dp[mask] != -1) return dp[mask];
        
        for (int i = 0; i < M; ++i) {
            // next state is legal and the opponet can't win that state.
            if (!(mask & (1 << i)) && !dfs(mask | (1 << i), M, desiredTotal - (i+1))) {
                // then this state we win
                return dp[mask] = 1;
            }
        }
        // after all tries, we can't win in this state
        return dp[mask] = false;
    }
    
    bool canIWin(int M, int desiredTotal) {
        // sum of entire choosable pool
        int sum = M * (M + 1) / 2;
        // I just pick 1 to win
        if(desiredTotal < 2) return true;
        // Total is too large, nobody can win
        if(sum < desiredTotal) return false;
        
        memset(dp, -1, sizeof dp);
        return dfs(0, M, desiredTotal);
    }
};
