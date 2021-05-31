
ll fun(int pos1, int pos2, string s1, string s2) {
    if(pos1 < 0 || pos2 < 0) return 0;

    if(s1[pos1] == s2[pos2]) {
        return 1 + fun(pos1 - 1, pos2 - 1, s1, s2);
    } else {
        return max(fun(pos1 - 1, pos2, s1, s2), fun(pos1, pos2 - 1, s1, s2));
    }
}

void LC_Subsequence_Bottom_Up(string s1, string s2){
    ll n1 = s1.size(), n2=s2.size();
    ll dp[n1 + 1][n2 + 1];
    for(int i = 0; i <= n1; i++) {
        for(int j = 0; j <= n2; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int maxLength = dp[n1][n2];
    
    string ans = "";
    int i = n1, j = n2;
    while(i > 0 && j > 0) {
        if(s1[i - 1] == s2[j - 1]) {
            ans = s1[i-1] + ans;
            i--, j--;
        } else if(dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    cout << maxLength << endl;
    cout << ans << endl;
}

void solve() {
    int x, y;
    string s1, s2;
    cin >> s1 >> s2;
    LC_Subsequence_Bottom_Up(s1, s2);
    cout << fun(s1.size() - 1, s2.size() - 1, s1, s2) << endl;
}





























string lcs(string& A, string& B) {
    int n = A.size(), m = B.size();
    vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (A[i] == B[j])
                dp[i + 1][j + 1] = dp[i][j] + A[i];
            else
                dp[i + 1][j + 1] = dp[i + 1][j].size() > dp[i][j + 1].size() ?  dp[i + 1][j] : dp[i][j + 1];
    return dp[n][m];
}
