#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
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
 
int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
