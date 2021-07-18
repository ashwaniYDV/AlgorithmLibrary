// https://leetcode.com/problems/predict-the-winner/

/*
You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.
Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. 
At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. 
The player adds the chosen number to their score. The game ends when there are no more elements in the array.

Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. 
You may assume that both players are playing optimally.
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
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n+5, vector<vector<int>>(n+5, vector<int>(2, -1)));
        return minimax(0, n - 1, 1, nums, dp) >= 0;
    }
};
