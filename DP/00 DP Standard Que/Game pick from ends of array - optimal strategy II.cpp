// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1
// https://www.techiedelight.com/pots-gold-game-dynamic-programming/


/*
You are given an array A of size N. The array contains integers and is of even length. 
The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.
In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.
You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.

Example 1:
Input:
N = 4
A[] = {5,3,7,10}
Output: 15
Explanation: The user collects maximum value as 15(10 + 5)

Example 2:
Input:
N = 4
A[] = {8,15,3,7}
Output: 22
Explanation: The user collects maximum value as 22(7 + 15)
*/





// Method 1: Top Down
class Solution {
public:
    #define ll long long

    // Recursive function to maximize the number of coins collected by a player, assuming that the opponent also plays optimally
    ll findMaxCoins(int i, int j, int nums[], vector<vector<ll>>& dp) {
        // base case: one pot left, only one choice possible
        if (i == j) {
            return nums[i];
        }

        // if we are left with only two pots, choose one with maximum coins
        if (i + 1 == j) {
            return max(nums[i], nums[j]);
        }

        if (dp[i][j] != -1) return dp[i][j];

        // if a player chooses the front pot `i`, the opponent is left to choose from `[i+1, j]`.
        // 1. If the opponent chooses front pot `i+1`, recur for `[i+2, j]`
        // 2. If the opponent chooses rear pot `j`, recur for `[i+1, j-1]`
        ll start = nums[i] + min(findMaxCoins(i + 2, j, nums, dp), findMaxCoins(i + 1, j - 1, nums, dp));

        // if a player chooses rear pot `j`, the opponent is left to choose from `[i, j-1]`.
        // 1. If the opponent chooses front pot `i`, recur for `[i+1, j-1]`
        // 2. If the opponent chooses rear pot `j-1`, recur for `[i, j-2]`
        ll end = nums[j] + min(findMaxCoins(i + 1, j - 1, nums, dp), findMaxCoins(i, j - 2, nums, dp));

        // return the maximum of two choices
        return dp[i][j] = max(start, end);
    }

    long long maximumAmount(int arr[], int n) {
        vector<vector<ll>> dp(n + 5, vector<ll>(n + 5, -1));
        ll x = findMaxCoins(0, n - 1, arr, dp);
        return x;
    }
};





// Method 1.1: Bottom Up
class Solution {
public:
#define ll long long

    int calculate(int i, int j, vector<vector<ll>>& dp) {
        if (i <= j) return dp[i][j];
        return 0;
    }

    long long maximumAmount(int coin[], int n) {
        vector<vector<ll>> dp(n, vector<ll>(n));

        // Fill the matrix in a diagonal manner
        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; i++, j++) {
                if (gap == 0) {
                    dp[i][j] = coin[i];
                } else if (gap == 1) {
                    dp[i][j] = max(coin[i], coin[i + 1]);
                } else {
                    // if a player chooses the front pot `i`, the opponent is left to choose from `[i+1, j]`.
                    // 1. If the opponent chooses front pot `i+1`, recur for `[i+2, j]`
                    // 2. If the opponent chooses rear pot `j`, recur for `[i+1, j-1]`
                    ll start = coin[i] + min(calculate(i + 2, j, dp), calculate(i + 1, j - 1, dp));

                    // if a player chooses rear pot `j`, the opponent is left to choose from `[i, j-1]`.
                    // 1. If the opponent chooses front pot `i`, recur for `[i+1, j-1]`
                    // 2. If the opponent chooses rear pot `j-1`, recur for `[i, j-2]`
                    ll end = coin[j] + min(calculate(i + 1, j - 1, dp), calculate(i, j - 2, dp));

                    dp[i][j] = max(start, end);
                }
            }
        }

        return dp[0][n - 1];
    }
};






// Method 1.2: Bottom Up
class Solution {
public:
#define ll long long

    int calculate(int i, int j, vector<vector<ll>>& dp) {
        if (i <= j) return dp[i][j];
        return 0;
    }

    long long maximumAmount(int coin[], int n) {
        vector<vector<ll>> dp(n, vector<ll>(n));

        // Fill the matrix in a diagonal manner
        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; i++, j++) {
                // if a player chooses the front pot `i`, the opponent is left to choose from `[i+1, j]`.
                // 1. If the opponent chooses front pot `i+1`, recur for `[i+2, j]`
                // 2. If the opponent chooses rear pot `j`, recur for `[i+1, j-1]`
                ll start = coin[i] + min(calculate(i + 2, j, dp), calculate(i + 1, j - 1, dp));

                // if a player chooses rear pot `j`, the opponent is left to choose from `[i, j-1]`.
                // 1. If the opponent chooses front pot `i`, recur for `[i+1, j-1]`
                // 2. If the opponent chooses rear pot `j-1`, recur for `[i, j-2]`
                ll end = coin[j] + min(calculate(i + 1, j - 1, dp), calculate(i, j - 2, dp));

                dp[i][j] = max(start, end);
            }
        }

        return dp[0][n - 1];
    }
};




















// Method 2.1: (TLE)
class Solution {
public:
    #define ll long long

    // minimax returns player1score - player2score
    ll minimax(int left, int right, bool isMax, int nums[], vector<vector<vector<ll>>>& dp) {
        // Terminating condition
        if (left > right) {
            return 0;
        }

        if (dp[left][right][isMax] != -1) return dp[left][right][isMax];

        //  If current move is maximizer, find the maximum attainable value
        if (isMax) {
            ll l = nums[left] + minimax(left + 1, right, false, nums, dp);
            ll r = nums[right] + minimax(left, right - 1, false, nums, dp);
            return dp[left][right][isMax] = max(l, r);
        }

        // Else (If current move is Minimizer), find the minimum attainable value
        else {
            ll l = -nums[left] + minimax(left + 1, right, true, nums, dp);
            ll r = -nums[right] + minimax(left, right - 1, true, nums, dp);
            return dp[left][right][isMax] = min(l, r);
        }
    }

    long long maximumAmount(int arr[], int n) {
        vector<vector<vector<ll>>> dp(n + 5, vector<vector<ll>>(n + 5, vector<ll>(2, -1)));
        ll x = minimax(0, n - 1, 1, arr, dp);

        ll sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i];

        /*
            player1 + player2 = sum
            player1 - player2 = x

            player1 = (sum + x) / 2;
        */

        return (sum + x) / 2;
    }
};







// Method 2.2: (TLE)
class Solution {
public:
#define ll long long

    // minimax returns player1score - player2score
    ll minimax(int left, int right, bool isMax, int nums[], vector<vector<vector<ll>>>& dp) {
        // Terminating condition
        if (left > right) {
            return 0;
        }

        if (dp[left][right][isMax] != -1) return dp[left][right][isMax];

        //  If current move is maximizer, find the maximum attainable value
        if (isMax) {
            ll l = nums[left] + minimax(left + 1, right, false, nums, dp);
            ll r = nums[right] + minimax(left, right - 1, false, nums, dp);
            return dp[left][right][isMax] = max(l, r);
        }

        // Else (If current move is Minimizer), find the minimum attainable value
        else {
            ll l = minimax(left + 1, right, true, nums, dp);
            ll r = minimax(left, right - 1, true, nums, dp);
            return dp[left][right][isMax] = min(l, r);
        }
    }

    long long maximumAmount(int arr[], int n) {
        vector<vector<vector<ll>>> dp(n + 5, vector<vector<ll>>(n + 5, vector<ll>(2, -1)));
        ll x = minimax(0, n - 1, 1, arr, dp);

        return x;
    }
};
