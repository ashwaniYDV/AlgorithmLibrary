// https://leetcode.com/problems/predict-the-winner/

/*
You are given an integer array nums. 
Two players are playing a game with this array: player 1 and player 2.
Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. 

At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. 
The player adds the chosen number to their score. The game ends when there are no more elements in the array.

Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. 
You may assume that both players are playing optimally.
*/


/*
Note: In this question array length can be either odd or even.

But if it would have been the case that array length is always even then player1 can always win the game as explained by sumit sir in this video 
https://youtu.be/ww4V7vRIzSk

The greedy strategy is:
1) Either of odd index elements sum or even index elements sum is greater than other.
2) Thus after checking which sum is greater, player1 can always force the opponent (player2) to choose the other parity elements.





Thus for this question we can also write as:

bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    if(n % 2 == 0) return true;

    vector<vector<vector<int>>> dp(n+5, vector<vector<int>>(n+5, vector<int>(2, -1)));
    return minimax(0, n - 1, 1, nums, dp) >= 0;
}
*/


// Method 1: Minimax Algo
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












// Method 2: Gap
class Solution {
public:
    int calculate(int i, int j, vector<vector<int>>& dp) {
        if (i <= j) return dp[i][j];
        return 0;
    }

    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if (n % 2 == 0) return true;

        int sum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> dp(n, vector<int>(n));

        // Fill the matrix in a diagonal manner
        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; i++, j++) {
                // if a player chooses the front pot `i`, the opponent is left to choose from `[i+1, j]`.
                // 1. If the opponent chooses front pot `i+1`, recur for `[i+2, j]`
                // 2. If the opponent chooses rear pot `j`, recur for `[i+1, j-1]`
                int start = nums[i] + min(calculate(i + 2, j, dp), calculate(i + 1, j - 1, dp));

                // if a player chooses rear pot `j`, the opponent is left to choose from `[i, j-1]`.
                // 1. If the opponent chooses front pot `i`, recur for `[i+1, j-1]`
                // 2. If the opponent chooses rear pot `j-1`, recur for `[i, j-2]`
                int end = nums[j] + min(calculate(i + 1, j - 1, dp), calculate(i, j - 2, dp));

                dp[i][j] = max(start, end);
            }
        }

        int player1 = dp[0][n - 1];
        int player2 = sum - player1;

        return player1 >= player2;

    }
};
