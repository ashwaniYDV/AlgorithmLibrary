// https://www.youtube.com/watch?v=WpYHNHofwjc&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=7


void LongestPalindromicSubstrings(string s){
    int n = s.size();
    int dp[n][n];
    int count = 0;
    int maxLength = 0;
    string ans;

    for(int gap = 0; gap < n; gap++) {
        for(int i=0, j=gap;  j<n;  i++, j++) {
            dp[i][j] = 0;
            if(gap == 0) {
                dp[i][j] = 1;
            } else if(gap == 1) {
                if(s[i] == s[j]) dp[i][j] = 1;
                else dp[i][j] = 0;
            } else {
                if(s[i] == s[j] && dp[i + 1][j - 1]) dp[i][j] = 1;
                else dp[i][j] = 0;
            }

            if(dp[i][j] == 1) {
                count++;
                // maxLength = max(maxLength, gap + 1);
                maxLength = max(maxLength, j - i + 1);
                // ans = s.substr(i, gap + 1);
                ans = s.substr(i, j - i + 1);
                
                // store substring length in dp table
                // dp[i][j] = gap + 1;
                dp[i][j] = j - i + 1;
            };
        }
    }

    cout << "Total palindromic substrings = " << count << endl;
    cout << "Max length of palindromic substring = " << maxLength << endl;
    cout << "A substring of maxLength= " << ans << endl;

    // Since there can be multiple answers of maxlength
    // To print them all
    cout << "\nTo print all the substrig of maxLength:\n";
    for(int gap = 0; gap < n; gap++) {
        for(int i=0, j=gap;  j<n;  i++, j++) {
            if(dp[i][j] == maxLength) {
                // cout << s.substr(i, gap + 1) << endl;
                cout << s.substr(i, j - i + 1) << endl;
            }
        }
    }
}

void solve() {
    int x, y;
    string s;
    cin >> s;
    LongestPalindromicSubstrings(s);
}

/*
Input:
cbcdbd

Output:
Total palindromic substrings = 8
Max length of palindromic substring = 3
A substring of maxLength= dbd

To print all the substrig of maxLength:
cbc
dbd

*/
