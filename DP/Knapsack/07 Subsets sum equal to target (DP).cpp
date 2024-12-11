/*
Case 1: When constraints are small such that we can use DP

N = 1000
Sum = 1000
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    // Base case
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    
    // DP transition
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j >= a[i - 1]) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][sum] << endl;
}