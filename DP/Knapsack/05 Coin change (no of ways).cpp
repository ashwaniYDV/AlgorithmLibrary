// https://leetcode.com/problems/coin-change-2/
// https://youtu.be/jaNZ83Q3QGc

/*
Que 1:
------
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, 
how many ways can we make the change? The order of coins doesn’t matter.
For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
So output should be 4. 
For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. 
So the output should be 5.

Que 2:
------
ax+by+cz+..... = sum
Find number of non negative solutions
*/



// Top down
// ll fun(ll a[], ll sum, ll n){
//     if(n < 0 || sum < 0) return 0;
//     if(sum == 0) return 1;

//     return fun(a, sum, n - 1) + fun(a, sum - a[n], n);
// }
// cout << fun(a, sum, n - 1)






// order of m memory
class Solution {
public:
    int change(int sum, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (j >= coins[i]) {
                    dp[j] += dp[j - coins[i]];
                }
            }
        }
        return dp[sum];
    }
};






// order of n*m memory
void solve() {
    ll x, y, z, sum;
    cin >> n;
    ll a[n];
    f(i, n) cin >> a[i];
    cin >> sum;
    ll dp[n + 1][sum + 1];
    for(ll i = 0; i <= n; i++) dp[i][0] = 1;
    for(ll j = 1; j <= sum; j++) dp[0][j] = 0;

    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= sum; j++){
            if(j < a[i - 1]){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j] + dp[i][j - a[i - 1]];
            }
        }
    }
    cout << dp[n][sum] << endl;
}
