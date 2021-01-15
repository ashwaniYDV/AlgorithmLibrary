// https://codingblocks.com/resources/travelling-salesman/

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
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
// const ll N = 1e5+5;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
// ll n, m;

const ll N = 4;
ll dp[int(pow(2, N))][N];

ll dis[N][N] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}
};

// all cities have been visited (1111)
ll VISITED_ALL = (1 << N) - 1;

ll tsp(ll mask, ll curCity) {
    // base case
    if (mask == VISITED_ALL) {
        return dis[curCity][0];
    }

    if(dp[mask][curCity] != -1) return dp[mask][curCity];

    ll minDistance = INT_MAX;

    // try to go to unvisited cities
    for(ll city = 0; city < N; city++) {
        if((mask & (1 << city)) == 0) {
            ll tempDis = dis[curCity][city] + tsp(mask | (1 << city), city);
            minDistance = min(minDistance, tempDis);
        }
    }

    return dp[mask][curCity] = minDistance;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cout << "Min weight hamiltonian path weight: ";
    cout << tsp(1, 0) << endl;
}

int32_t main() {
    IOS
    solve();
    cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n'; 
    return 0;
}
