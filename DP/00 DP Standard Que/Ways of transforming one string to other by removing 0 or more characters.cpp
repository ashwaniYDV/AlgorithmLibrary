// Distinct Transformations 
// https://www.geeksforgeeks.org/ways-transforming-one-string-removing-0-characters/
// https://youtu.be/VOWpn_bWS0U

/*
Given two sequences s, t, find out number of unique ways in sequence s, to form a subsequence of s that is identical to sequence t. 
Transformation is meant by converting string s (by removing 0 or more characters) to string t.

Examples:
Input : s = "abcccdf", t = "abccdf"
Output : 3
Explanation : Three ways will be -> "ab.ccdf", "abc.cdf" & "abcc.df" .
"." is where character is removed. 

Input : s = "aabba", t = "ab"
Output : 4
Expalnation : Four ways will be -> "a.b..", "a..b.", ".ab.." & ".a.b." .
"." is where characters are removed.
*/


int go(int i, int j, string &s, string &t) {
    if (i == n) return j == m;
    if (j == m) return i <= n;

    int res = 0;
    if (s[i] == t[j]) {
        res += go(i + 1, j + 1, s, t);
    }
    res += go(i + 1, j, s, t);
    return res;
}

void solve() {
    string s, t;
    cin >> s >> t;
    n = s.size(), m = t.size();
    cout << go(0, 0, s, t);
}








void solve() {
    string s, t;
    cin >> s >> t;
    n = s.size(), m = t.size();

    int dp[n + 1][m + 1];

    // when both s and t are empty
    // thus one way by removing no character from s
    dp[0][0] = 1;

    // when t is empty
    // thus one way by removing all character from s
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
    }

    // when s is empty and t is non empty
    // thus no way
    for (int j = 1; j <= m; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = 0;

            if (s[i - 1] == t[j - 1]) dp[i][j] += dp[i - 1][j - 1];
            dp[i][j] += dp[i - 1][j];
        }
    }

    cout << dp[n][m] << endl;
}
