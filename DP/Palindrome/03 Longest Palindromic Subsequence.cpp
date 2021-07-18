// https://www.youtube.com/watch?v=RiNzHfoA2Lo&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=16

/*
dp[i][j] = length of longest palindromic subsequence in substring of s starting with index i and ending at index j
dp[0][n-1] = length of longest palindromic subsequence for whole string s
*/



void AllPalindromicSubsequences(string s) {
    int n = s.size();
    int dp[n][n];

    for (int gap = 0; gap < n; gap++) {
        for (int i = 0, j = gap;  j < n;  i++, j++) {
            dp[i][j] = 0;
            if (gap == 0) {
                dp[i][j] = 1;
            } else if (gap == 1) {
                if (s[i] == s[j]) dp[i][j] = 2;
                else dp[i][j] = 1;
            } else {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
    }

    cout << "Longest palindromic subsequence length = " << dp[0][n - 1] << endl;
}

void solve() {
    int x, y;
    string s;
    cin >> s;
    AllPalindromicSubsequences(s);
}

/*
Input:
abccbc

Output:
Longest palindromic subsequence length = 4
*/
