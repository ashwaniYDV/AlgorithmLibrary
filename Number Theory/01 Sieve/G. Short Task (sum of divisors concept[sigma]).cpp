// https://codeforces.com/contest/1512/problem/G

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
const int MAXN = 2e5+5;
const int N = 1e7+5;
int n, m;

int res[N+5], sigma[N+5];

int spf[N+5];
bool prime[N+5];
void SieveAndSPF() {
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;

	// marking smallest prime factor for every number to be itself.
	for (int i = 1; i < N; i++) spf[i] = i;
	
	for(int p=2; p*p<=N; p++) { 
		if (prime[p] == true) {
			for(int i=p*p;i<=N;i+=p) {
				prime[i] = false; 
				spf[i] = min(spf[i], p);
			}
		} 
	}
}

void precompute() {
	SieveAndSPF();
	for(int i = 0; i < N; i++) {
		res[i] = -1;
	}

	sigma[1] = 1;
	for(int i = 2; i <= 1e7; i++) {
        if(prime[i]) {
        	// divisors of prime i = (1 and i)
            sigma[i] = 1 + i;
            continue;
        }
        int x = i, y = spf[x], z = y;
        int tempSigma = 1;
        while(x % y == 0) {
            x /= y;
            tempSigma += z;
            z *= y;
        }

        // using Number-Theoretic-Function property of sigma: sigma(a*b) = sigma(a)*sigma(b), where a, b are coprime
        tempSigma *= sigma[x];
        sigma[i] = tempSigma;
    }

    for(int i = 1; i <= 1e7; i++) {
        if(sigma[i] > 1e7) {
            continue;
        }
        if(res[sigma[i]] == -1) {
        	res[sigma[i]] = i;
        }
    }
}

void solve() {
	int x, y, z;
	cin >> n;
	cout << res[n] << endl;
}

signed main() {
	IOS
	precompute();
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
}
