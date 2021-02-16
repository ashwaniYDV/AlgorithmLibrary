// https://codeforces.com/contest/1447/problem/D

/*
Let DP[i][j] be the maximum similarity score if we end the first subsequence with Ai and the second substring with Bj. 
We will also allow the corresponding most similar string to be empty so that DP[i][j] is always at least 0.

We have just two possibilities:

1) Ai and Bj are the same letters. 
In this case, we say that DP[i][j] = DP[i−1][j−1] + 2 
as the new letter will increase the LCS by 1, but both of the strings increase by one in length, so the total gain is 4−1−1=2.

2) We can refer to DP[i][j−1] or DP[i][j−1] to extend one of the previous substrings, but not the LCS, so: DP[i][j] = max(DP[i-1][j], DP[i][j-1]) — 1.

NOTE: If a dp[i][j] has a negative score, we can throw it away and start from scratch.
*/

int n, m;

// Method 1
void LCSubsequence(string s1, string s2){
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2+1, 0));
    int res = 0;
    for(int i = 0; i <= n1; i++) {
        for(int j = 0; j <= n2; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + (4 - 2);
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) - 1;
            }

            if(dp[i][j] < 0) dp[i][j] = 0;

            res = max(res, dp[i][j]);
        }
    }
    cout << res << endl;
}

// Method 2
int goAns = 0;
int dp[5005][5005];
int go(int i, int j, string& s1, string& s2){
    if(i == n || j == m) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
 
    int res = 0, x, y, z;
    
    x = go(i+1, j+1, s1, s2);
    y = go(i, j+1, s1, s2);
    z = go(i+1, j, s1, s2);
    
    if(s1[i] == s2[j]) {
        res = (4 - 2) + max(0LL, x);
    } else {
        res = max({0LL, -1 + y, -1 + z});
    }
    goAns = max(goAns, res);
    return dp[i][j] = res;
}

void solve() {
	int x, y, z;
	cin >> n >> m;
	string s1, s2;
	cin >> s1 >> s2;
	// LCSubsequence(s1, s2);

	memset(dp, -1, sizeof dp);
	x = go(0, 0, s1, s2);
	cout << goAns << endl;
}
