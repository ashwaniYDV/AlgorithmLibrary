
int dp[10][95][2];
string str;
int l, r, sum;

int digit_dp(int pos, int cursum, int tight){
    if(pos == str.length()) {
        return (cursum == sum);
    }

    if(dp[pos][cursum][tight] != -1) return dp[pos][cursum][tight];
    
    int res = 0;
    int ub = tight ? (str[pos] - '0') : 9;

    for(int i = 0; i <= ub; i++) {
        res += digit_dp(pos + 1, cursum + i, (tight & (i == ub)));
    }
    
    return dp[pos][cursum][tight] = res;
}

int go(int n) {
    memset(dp, -1, sizeof(dp));
    str = to_string(n);
    return digit_dp(0, 0, 1);
}

void solve() {
    cin >> l >> r >> sum;
    cout << go(r) - go(l - 1) << endl;
}
