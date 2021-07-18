// https://leetcode.com/problems/perfect-squares/
// Min coin change problem concept

/*
Given an integer n, return the least number of perfect square numbers that sum to n.

Example 1:
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/


class Solution {
public:
    #define ll int
    #define INF 1e9

    ll fun(ll a[], ll sum, ll n) {
        vector<ll> dp(sum + 1, INF);
        dp[0] = 0;

        for (ll i = 0; i < n; i++) {
            for (ll j = 1; j <= sum; j++) {
                if (j >= a[i]) {
                    dp[j] = min(dp[j], dp[j - a[i]] + 1);
                }
            }
        }
        return dp[sum];
    }
    int numSquares(int n) {
        int k = ceil(sqrt(n));
        ll a[k];
        for (ll i = 0; i < k; i++) a[i] = (i + 1) * (i + 1);
        return fun(a, n, k);
    }
};










class Solution {
public:
    #define ll int
    #define INF 1e9

    ll fun(ll a[], ll sum, ll n) {
        ll dp[n + 1][sum + 1];
        for (ll i = 0; i <= n; i++) dp[i][0] = 0;
        for (ll j = 1; j <= sum; j++) dp[0][j] = INF;

        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= sum; j++) {
                if (j < a[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - a[i - 1]] + 1);
                }
            }
        }
        return dp[n][sum];
    }
    int numSquares(int n) {
        int k = ceil(sqrt(n));
        ll a[k];
        for (ll i = 0; i < k; i++) a[i] = (i + 1) * (i + 1);
        return fun(a, n, k);
    }
};
