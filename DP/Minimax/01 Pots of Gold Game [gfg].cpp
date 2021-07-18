// https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1

/*
Two players X and Y are playing a game in which there are pots of gold arranged in a line, each containing some gold coins. 
They get alternating turns in which the player can pick a pot from one of the ends of the line. 
The winner is the player who has a higher number of coins at the end. 
The objective is to maximize the number of coins collected by X, assuming Y also plays optimally.

Return the maximum coins X could get while playing the game. Initially, X starts the game.
*/



/*
Let, 
a = maximizer
b = minimizer

thus let,
diff = a - b
obviously sum = a + b
therefore a = (sum + diff) / 2
*/


class Solution {
public:
    int minimax(int left, int right, bool isMax, vector<int>& nums, vector<vector<vector<int>>>& dp) {
        // Terminating condition
        if (left > right) {
            return 0;
        }
        
        if(dp[left][right][isMax] != -1) return dp[left][right][isMax];
        
        //  If current move is maximizer, find the maximum attainable value
        if (isMax) {
            int l = nums[left] + minimax(left + 1, right, false, nums, dp);
            int r = nums[right] + minimax(left, right - 1, false, nums, dp);
           return dp[left][right][isMax] = max(l, r);
        }

        // Else (If current move is Minimizer), find the minimum attainable value
        else {
            int l = -nums[left] + minimax(left + 1, right, true, nums, dp);
            int r = -nums[right] + minimax(left, right - 1, true, nums, dp);
            return dp[left][right][isMax] = min(l, r);
        }
    }
    
    int maxCoins(vector<int>& nums, int n) {
        vector<vector<vector<int>>> dp(n+5, vector<vector<int>>(n+5, vector<int>(2, -1)));
        // a - b = diff
        // a + b = sum
        // a = (diff + sum) / 2
        int diff = minimax(0, n - 1, 1, nums, dp);
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        
        return (diff+sum) / 2;
    }
};
