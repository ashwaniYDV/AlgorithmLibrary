// every elemnts occurs twice in the array excepttwo numbers which occurs once

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize "03"
#pragma GCC target("sse4")

#define ll long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;a<n?i<n:i>=n;a<n?i+=1:i-=1)
#define loop(i,a, n) for(ll i = a; i <= n; i++)
#define loopb(i,a, n) for(ll i = a; i >= n; i--)
#define pb push_back
#define pf push_front
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define setmem(x, k) memset(x, k, sizeof(x))
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define MOD 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int>	vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
const ll N = 1e6+5;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

ll find2UniqueNums(ll a[], ll n) {
	ll res = 0;
	f(i, n){
		res = res ^ a[i];
	}
	// find the rightmost set bit position
	ll temp = res;
	ll pos = 0;
	while(temp) {
		if(temp & 1){
			break;
		}
		pos++;
		temp = temp >> 1;
	}
	ll mask = 1 << pos;
	ll firstNum = 0, secondNum = 0;
	f(i, n){
		if(mask & a[i]){
			firstNum = firstNum ^ a[i];
		}
	}
	secondNum = res ^ firstNum;
	if(firstNum > secondNum) swap(firstNum, secondNum);
	cout << firstNum << " " << secondNum << endl;
}

void solve() {
    cin >> n;
    ll a[n];
    f(i, n) cin >> a[i];
    find2UniqueNums(a, n);
}

int32_t main() {
	IOS
	solve();
	cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n'; 
	return 0;
}
