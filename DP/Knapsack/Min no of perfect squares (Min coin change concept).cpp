// https://leetcode.com/problems/perfect-squares/
// same as min coin change problem

#define ll int
#define INF 1e9

class Solution {
public:
    ll fun(ll a[], ll sum, ll n){
        ll dp[n + 1][sum + 1];
        for(ll i = 0; i <= n; i++) dp[i][0] = 0;
        for(ll j = 1; j <= sum; j++) dp[0][j] = INF;

        for(ll i = 1; i <= n; i++){
            for(ll j = 1; j <= sum; j++){
                if(j < a[i - 1]){
                    dp[i][j] = dp[i - 1][j];
                }else{
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - a[i - 1]] + 1);
                }
            }
        }
        return dp[n][sum];
    }
    int numSquares(int n) {
        int k = ceil(sqrt(n));
        ll a[k];
        for(ll i = 0; i < k; i++) a[i] = (i+1)*(i+1);
        return fun(a, n, k);
    }
};
