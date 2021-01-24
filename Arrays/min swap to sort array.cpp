/*
NOTE: Array must have distinct elements for the below solutions.
*/

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
typedef long long int ll;
// #define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define debug(x) cout << #x << " is: " << (x) << endl;
#define debugx(x) cout << #x << " is: " << (x) << endl; exit(0);
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;i<n;i++)
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
#define INF 1000111000111000111LL
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<vector<ll>> matrix;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
const ll N = 1e5+1;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

/*
Given an array of N distinct elements, find the minimum number of swaps required to sort the array.
Eg:
6
{ 3, 5, 2, 4, 6, 8}
*/
void fun1(vl a) {
    vector<ll> b = a;
    sort(all(b));
    map<ll, ll> mp;
    f(i, n){
        mp[b[i]] = i;
    }

    ll ct = 0;
    f(i, n){
        if(a[i] == b[i]) continue;

        ll pos = mp[a[i]];
        swap(a[i], a[pos]);
        ct++;
        i--;
    }
    cout << ct << endl;
}

/*
Minimum number of swaps required to sort an array of first N number (1.....n)
Eg:
5
{2, 1, 3, 5, 4}
*/
void fun2(vl a) {
    ll ct = 0;
    f(i, n){
        if(a[i] == i + 1) continue;

        swap(a[i], a[a[i] - 1]);
        ct++;
        i--;
    }
    cout << ct << endl;
}

void solve() {
    ll t, k, x, y, u, v;
    cin >> n;
    vector<ll> a(n);
    f(i, n) cin >> a[i];
    fun1(a);

    cin >> n;
    a = vector<ll>(n);
    f(i, n) cin >> a[i];
    fun2(a);
}

int32_t main() {
    IOS
    clock_t begin = clock();
    ll T = 1;
    // cin >> T;
    while(T--)
    solve();
    cerr<<"Time elapsed : "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
    return 0;
}

/*
INP:
6
3 5 2 4 6 8
4
4 3 1 2

OUT:
3
3
*/
