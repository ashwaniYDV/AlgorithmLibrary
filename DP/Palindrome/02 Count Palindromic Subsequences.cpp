// https://youtu.be/YHSjvswCXC8

/*
                                count(c1+str+c2)
                            ________________________
                                        |
            if(c1 == c2)                |                   if(c1 != c2)
                                        | 
                                        |
    count(c1+str) + count(str+c2) + 1   |       count(c1+str) + count(str+c2) - count(str)
                                        | 
                                        |
___________________________________________________________________________________________
Let s = abcd
n = s.size()
Total subsequences = 2^n

All subsequnces of above example are shown below:
- - - -
- - - d
- - c -
- - c d
- b - -
- b - d
- b c -
- b c d
a - - -
a - - d
a - c -
a - c d
a b - -
a b - d
a b c -
a b c d

dp[i][j] = total no. of palindromic subsequences in substring of s starting with index i and ending at index j
dp[0][n-1] = total no. of palindromic subsequences for whole string s
*/



/*
NOTE:
This solution does not count different (unique) non-empty palindromic subsequences. It counts all the non-empty palindromic subsequences.
Example: s = bccb
Asn = 9
But there are 6 different non-empty palindromic subsequences = 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.


https://leetcode.com/problems/count-different-palindromic-subsequences
This leetcode problem is asking "Count Different Palindromic Subsequences".
*/

void AllPalindromicSubsequences(string s){
    int n = s.size();
    int dp[n][n];

    // traversing diagonal wise: 
    // i.e. first principal diagonal (gap = 0) and then
    // diagonal above it (gap = 1) and so on...
    for(int gap = 0; gap < n; gap++) {
        for(int i=0, j=gap;  j<n;  i++, j++) {
            dp[i][j] = 0;
            if(gap == 0) {
                dp[i][j] = 1;
            } else if(gap == 1) {
                if(s[i] == s[j]) dp[i][j] = 3;
                else dp[i][j] = 2;
            } else {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1;
                } else {
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
                }
            }
        }
    }
    
    // dp[i][j] = total no. of palindromic subsequences in substring of s starting with index i and ending at index j
    // dp[0][n-1] = total no. of palindromic subsequences for whole string s
    cout << "Total palindromic subsequences = " << dp[0][n-1] << endl;
}

void solve() {
    int x, y;
    string s;
    cin >> s;
    AllPalindromicSubsequences(s);
}
 
int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
 
/*
Input:
abccbc

Output:
Total palindromic subsequences = 16
*/
