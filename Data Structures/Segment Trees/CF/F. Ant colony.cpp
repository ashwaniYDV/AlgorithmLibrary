// https://codeforces.com/contest/474/problem/F

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
const int MAXN = 5e5+5;
const int N = 1e6+5;
int n, m;

int arr[N];
int st[4 * N];

void build(int si , int ss , int se) {
    if(ss == se) {
        st[si] = arr[ss];
        return;
    }
 
    int mid = (ss + se)/2;
    build(2*si , ss , mid);
    build(2*si+1 , mid+1 , se);

   st[si] = __gcd(st[si*2], st[si*2+1]);
}

int query(int si , int ss , int se , int qs , int qe) {
    if(qe < ss || qs > se) return 0;
 
    if(ss >= qs && se <= qe) {
        return st[si];
    };
 
    int mid = (ss + se)/2;
    int l = query(2*si , ss , mid , qs , qe);
    int r = query(2*si+1 , mid+1 , se , qs , qe);
    
    return __gcd(l, r);
}


void solve(){
    int t, l, r, k, q;
    cin >> n;
    map<int, vector<int>> mp;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        mp[arr[i]].pb(i);
    }

    build(1, 1, n);

    cin >> q;
    while(q--){
        cin >> l >> r;
        int gcd = query(1, 1, n, l, r);
        int ans = r - l + 1;
        if(mp.count(gcd)){
            int tmp = upper_bound(all(mp[gcd]), r) - lower_bound(all(mp[gcd]),l);
            ans -= tmp;
        }
        cout << ans << endl;
    }
} 
 
int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
