// https://youtu.be/qtqMTgmDpQg

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

typedef long long int ll;
#define int long long int
#define ld long double
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PRECISION(x) cout << setprecision(x); cout << fixed;
#define debug(x) cout << #x << " is: " << (x) << endl;
#define debug2(x,y) cout << (#x) <<", "<<(#y)<< " are: " << (x) <<", "<<(y)<< endl;
#define debugx(x) cout << #x << " is: " << (x) << endl; exit(0);
#define kickstart(testcase, res) cout << "Case #" << testcase << ": " << res << endl;
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
#define MOD2 998244353
#define INT_INF 1011111111
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 500+5;
int n, m;

struct node {
	int i, j;
	string pathSoFar;
};

void solve() {
	int sum;
	cin >> n >> sum;
	vi a(n);
	f(i, n) cin >> a[i];

	int dp[n+1][sum + 1];
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int j = 1; j <= sum; j++) {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= sum; j++) { 
            if(j < a[i - 1]){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
            }
        }
    }
    
    if(!dp[n][sum]) {
    	cout << "Not possible" << endl;
    	return;
    }

    // reverse engineering
    queue<node> q;
    q.push({n, sum, ""});

    while(!q.empty()) {
    	node x = q.front();
    	q.pop();

    	if(x.i == 0 || x.j == 0) {
    		cout << x.pathSoFar << endl;
    		continue;
    	}

    	// excluded
    	if(dp[x.i - 1][x.j]) {
    		q.push({x.i - 1, x.j, x.pathSoFar});
    	}
    	// included
    	if((x.j >= a[x.i - 1]) && dp[x.i - 1][x.j - a[x.i - 1]]) {
    		q.push({x.i - 1, x.j - a[x.i - 1], to_string(a[x.i - 1]) + " " + x.pathSoFar});
    	}
    }
}

signed main() {
	IOS
	int T = 1;
	// cin >> T;
	while(T--)
	solve();
	return 0;
}
