// https://codeforces.com/problemset/problem/1444/B

/*
Important Property:
No matter how we split the array, the cost of a partition will always be the same.
So answer = CostOfPartition * binomialCoefficient(2nCn)
*/


#include<bits/stdc++.h>
using namespace std;

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
#define MOD2 1000000007
#define MOD 998244353
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
const int MAXN = 300000+5;
const int N = 300000+5;
int n, m;

/*------------------------------------------------------*/
int power(int n, int p, int mod) {
    int res = 1;
    n %= mod;
    while (p > 0) {
        if (p & 1) res = (res * n) % mod;
        n = (n * n) % mod;
        p >>= 1;
    }
    return res;
}
int modInverse(int n, int p) { 
    return power(n, p - 2, p);
} 
 
int fact[MAXN] = {0};
void initFactorials(int mod) {
    fact[0] = fact[1] = 1;
      for (int i = 2; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i * 1LL) % mod;
    }
}
 
int nCrMod(int n, int r, int mod) {
    if (n < r) return 0;
    if (r == 0) return 1;
    int num = fact[n], den = (fact[r] * fact[n-r]) % mod;
    int inv = modInverse(den, mod);
    return (num * inv) % mod;
}
/*------------------------------------------------------*/


void solve() {
	initFactorials(MOD);

	cin >> n;
	m = 2*n;
	int a[m];
	f(i, m) cin >> a[i];

	vector<int> v1, v2;
	f(i, n) {
		v1.pb(a[i]);
		v2.pb(a[n + i]);
	}

	sort(all(v1));
	sort(all(v2), greater<>());

	int res = 0;
	f(i, n) {
		res += (abs(v1[i] - v2[i]));
		res %= MOD;
	}

	res = res * nCrMod(2*n, n, MOD);
	res = (res + MOD) % MOD;

	cout << res << endl;
}

signed main() {
    IOS
    int T = 1;
    // cin >> T;
    while (T--)
    	solve();
    return 0;
}
