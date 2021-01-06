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

bool isSubsetSumPartition(ll arr[], ll sum, ll pos, ll curr_sum){
	if(pos >= n) return false;
	if(curr_sum == sum) return true;

	if(isSubsetSumPartition(arr, sum, pos + 1, curr_sum + arr[pos]) || isSubsetSumPartition(arr, sum, pos + 1, curr_sum))
		return true;
	else
		return false;

}

void solve() {
	ll w, x, y, t, l, r, p, q;
	ll arr[] = {3, 1, 5, 9, 12}; 
    n = sizeof(arr) / sizeof(arr[0]);
    ll sum = 0;
    f(i,n){
    	sum += arr[i];
    }
    if(sum % 2 == 1){
    	printf("No subset cannot be partitioned into two set with equal sum");
    	return;
    }
    if (isSubsetSumPartition(arr, sum/2, 0, 0) == true)
        printf("Yes subset can be partitioned into two set with equal sum");
    else
        printf("No subset cannot be partitioned into two set with equal sum");
}

int32_t main() {
	IOS
	solve();
	cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n'; 
	return 0;
}
