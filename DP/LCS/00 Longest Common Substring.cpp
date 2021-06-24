

ll fun(int pos1, int pos2, int count, string s1, string s2) {
    if(pos1 < 0 || pos2 < 0) return count;

    int res = count;

    if(s1[pos1] == s2[pos2]) {
        res = max(res, fun(pos1 - 1, pos2 - 1, count + 1, s1, s2));
    } else {
        res = max({res, fun(pos1 - 1, pos2, 0, s1, s2), fun(pos1, pos2 - 1, 0, s1, s2)});
    }

    return res;
}

void LC_Substring_Bottom_Up(string s1, string s2){
    ll n1 = s1.size(), n2=s2.size();
    ll dp[n1 + 1][n2 + 1];
    ll ans = 0, pos;
    for(int i = 0; i <= n1; i++) {
        for(int j = 0; j <= n2; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if(dp[i][j] > ans) {
                    ans = dp[i][j];
                    pos = i;
                }
            }else{
                dp[i][j] = 0;
            }
        }
    }

    cout << ans <<endl;
    cout << s1.substr(pos - ans, ans) << endl;
}

void solve() {
    int x, y;
    string s1, s2;
    cin >> s1 >> s2;
    LC_Substring_Bottom_Up(s1, s2);
    cout << fun(s1.size() - 1, s2.size() - 1, 0, s1, s2) << endl;
}
