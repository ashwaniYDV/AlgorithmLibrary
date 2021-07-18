// How many numbers 'x' are there in the range from 'l' to 'r' 
// where digit 'd' occurs exactly 'k' times
 

int l, r, digit, k;
int dp[11][2][11];
string str;

int digit_dp(int pos, int tight, int count) {
    if(pos == str.length()){
        return count == k;
    }

    if(dp[pos][tight][count]!=-1) return dp[pos][tight][count];
    
    int res = 0;
    int ub = tight ? (str[pos] - '0') : 9;

    for(int i = 0; i <= ub; i++) {
        int ct = count;
        if(i == digit) ct++;

        res += digit_dp(pos + 1, (tight & (i == ub)), ct);
    }
    
    return dp[pos][tight][count] = res;
}

int go(int n) {
    memset(dp, -1, sizeof(dp));
    str = to_string(n);
    return digit_dp(0, 1, 0);
}

void solve() {
    cin >> l >> r >> digit >> k;
    cout << go(r) - go(l - 1) << endl;
}
