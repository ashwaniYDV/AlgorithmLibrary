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
const int MAXN = 1e5 + 5;
const int N = 1e6+5;
int n, m;

int arr[N];
int st[4*N];

void build(int si, int ss, int se, int flag) {
    if(ss == se) {
        st[si] = arr[ss];
        return;
    }
 
    int mid = (ss + se)/2;
    build(2*si , ss , mid, 1 - flag);
    build(2*si+1 , mid+1 , se, 1 - flag);
 
    if(flag == 1) {
        st[si] = st[2*si] | st[2*si+1];
    } else {
        st[si] = st[2*si] ^ st[2*si+1];
    }
}


void update(int si, int ss, int se, int qi, int value, int flag) {
    if(ss == se) {
        // here ss == se == qi
        st[si] = value;
        return;
    }

    ll mid = (ss + se) / 2;
    
    if(qi <= mid) update(2*si, ss, mid, qi, value, 1 - flag);
    else update(2*si + 1, mid + 1, se, qi, value, 1 - flag);

    if(flag == 1) {
        st[si] = st[2*si] | st[2*si+1];
    } else {
        st[si] = st[2*si] ^ st[2*si+1];
    }
}


void solve() {
    int x, y, t;
    cin >> n >> m;

    for(int i = 1; i <= pow(2, n); i++){
        cin >> arr[i];
    }

    if(n % 2 == 0) build(1, 1, pow(2, n), 0);
    else build(1, 1, pow(2, n), 1);

    while(m--) {
        cin >> x >> y;

        if(n % 2 == 0) update(1, 1, pow(2, n), x, y, 0);
        else update(1, 1, pow(2, n), x, y, 1);

        cout << st[1] << endl;
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
