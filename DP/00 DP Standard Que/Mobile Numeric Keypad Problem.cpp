// https://www.geeksforgeeks.org/mobile-numeric-keypad-problem/
// https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

/*
Given the mobile numeric keypad. You can only press buttons that are up, left, right, or down to the current button. 
You are not allowed to press bottom row corner buttons (i.e. * and # ). 
Given a number N, the task is to find out the number of possible numbers of the given length.

Example 1:
Input: 1
Output: 10
Explanation: Number of possible numbers would be 10 (0, 1, 2, 3, …., 9)  

Example 2:
Input: N = 2
Output: 36
Explanation: Possible numbers: 00, 08, 11, 12, 14, 22, 21, 23, 25 and so on.
*/


class Solution {
public:
    int n;
    map<int, vector<int>> g;

    long long go(int i, int cnt, vector<vector<long long>>& dp) {
        if (cnt == n) return 1;

        if (dp[i][cnt] != -1) return dp[i][cnt];

        long long res = 0;
        for (int x : g[i]) {
            res += go(x, cnt + 1, dp);
        }
        return dp[i][cnt] = res;
    }

    long long getCount(int n) {
        this->n = n;

        // neighbours including itself
        g[0] = {0, 8};
        g[1] = {1, 2, 4};
        g[2] = {1, 2, 3, 5};
        g[3] = {2, 3, 6};
        g[4] = {1, 4, 5, 7};
        g[5] = {2, 4, 5, 6, 8};
        g[6] = {3, 5, 6, 9};
        g[7] = {4, 7, 8};
        g[8] = {5, 7, 8, 9, 0};
        g[9] = {6, 8, 9};

        vector<vector<long long>> dp(10, vector<long long>(n + 1, -1));
        long long res = 0;
        for (int i = 0; i <= 9; i++) {
            res += go(i, 1, dp);
        }
        return res;
    }
};













class Solution {
public:
    map<int, vector<int>> g;

    long long getCount(int n) {
        // neighbours including itself
        g[0] = {0, 8};
        g[1] = {1, 2, 4};
        g[2] = {1, 2, 3, 5};
        g[3] = {2, 3, 6};
        g[4] = {1, 4, 5, 7};
        g[5] = {2, 4, 5, 6, 8};
        g[6] = {3, 5, 6, 9};
        g[7] = {4, 7, 8};
        g[8] = {5, 7, 8, 9, 0};
        g[9] = {6, 8, 9};

        vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 9; j++) {
                if (i == 1) {
                    dp[i][j] = 1;
                } else {
                    for (int v : g[j]) {
                        dp[i][j] += dp[i - 1][v];
                    }
                }
            }
        }

        long long res = 0;
        for (int j = 0; j <= 9; j++) {
            res += dp[n][j];
        }
        return res;
    }
};
