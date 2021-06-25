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

#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PRECISION(x) cout << setprecision(x); cout << fixed;
#define debug(x) cout << #x << " is: " << (x) << endl;
#define debugx(x) cout << #x << " is: " << (x) << endl; exit(0);
#define f(i,n) for(int i=0;i<n;i++)
#define fa(i,a,n) for(int i=a;i<n;i++)
#define loop(i,a, n) for(int i = a; i <= n; i++)
#define loopb(i,a, n) for(int i = a; i >= n; i--)
#define pb push_back
#define pf push_front
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5 + 5;
const int N = 1e5+5;
int n, m;

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
