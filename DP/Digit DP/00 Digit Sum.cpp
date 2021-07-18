// SPOJ Digit Sum
// https://www.spoj.com/problems/PR003004/
// https://www.youtube.com/watch?v=5ag4kmHVs8k&list=PLJSqVBBfSpyz_Lb0Baqg2V7cjAg3Rz3yz


/*
constraints and DP range
------------------------
constraint = (0 <= l <= r <= 10^15)

n = 15 digits max = 15
sum = 15*9 max = 15*9 = 135
tight = 0 or 1 = 2

dp[n][sum][tight]
dp[15][135][2]

to be safe we can take larger values

int dp[18][150][2]
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[18][150][2];
string str;

int digit_dp(int pos, int sum, int tight){
    if(pos == str.length()) return sum;

    if(dp[pos][sum][tight] != -1) return dp[pos][sum][tight];
    
    int res = 0;
    int ub = tight ? (str[pos] - '0') : 9;

    for(int i = 0; i <= ub; i++) {
        res += digit_dp(pos + 1, sum + i, (tight & (i == ub)));
    }
    
    return dp[pos][sum][tight] = res;
}

int go(int num) {
    str = to_string(num);
    memset(dp, -1, sizeof(dp));
    return digit_dp(0, 0, 1);
}

void solve() {
    int l, r;
    cin >> l >> r;
    cout << go(r) - go(l - 1) << endl;
}

int32_t main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
