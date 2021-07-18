// https://cses.fi/problemset/task/2220/


int dp[20][11][2][2];
string str;

int digit_dp(int pos, int prevDigit, bool leadingZeros, bool tight) {
    if(pos == n) return 1;

    if(dp[pos][prevDigit][leadingZeros][tight] != -1) return dp[pos][prevDigit][leadingZeros][tight];

    ll res = 0;
    int ub = tight ? (str[pos] - '0') : 9;

    if(leadingZeros) {
        for(int dig = 0; dig <= ub; dig++) {
            if(dig == 0)
                res += digit_dp(pos + 1, dig, 1, tight & (ub == dig));
            else
                res += digit_dp(pos + 1, dig, 0, tight & (ub == dig));
        }
    } else {
        for(int dig = 0; dig <= ub; dig++) {
            if(dig != prevDigit) {
                res += digit_dp(pos + 1, dig, 0, tight & (ub == dig));
            }
        }
    }

    return dp[pos][prevDigit][leadingZeros][tight] = res;
}

int go(int num) {
    str = to_string(num);
    memset(dp, -1, sizeof dp);
    n = str.size();
    return digit_dp(0, 99, 1, 1);
}

void solve() {
    int l, r;
    cin >> l >> r;
    cout << go(r) - go(l - 1) << endl;
}
