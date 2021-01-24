// https://codeforces.com/problemset/problem/1249/B2

#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define int long long int
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
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<vector<ll>> matrix;
// ll dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
// ll dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const ll MAXN = 5e5 + 5;
const ll N = 2e5+5;
ll n, m;

ll par[N];

void initialize(){
    for(ll i=1; i<=n; i++){
        par[i]=-1;
    }
}
ll find_par(ll a){
    if(par[a]<0)
        return a;
    return par[a]=find_par(par[a]);
}
void union_set(ll a, ll b){
    a=find_par(a);
    b=find_par(b);
    if(a==b)
        return;
    if(par[a]>par[b])
        swap(a,b);
    par[a]+=par[b];
    par[b]=a;
}

// answer is size of connected component in which each 1..n belong
void solve() {
    ll x, y;
    cin >> n;
    initialize();
    loop(i, 1, n){
      cin >> x;
      union_set(i, x);
    }
    loop(i, 1, n) {
        ll p = find_par(i);
        cout << -1*par[p] << " ";
    }
    cout << endl;
}
 
int32_t main() {
    IOS
    ll T = 1;
    cin >> T;
    while(T--)
    solve();
    return 0;
}
