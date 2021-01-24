// https://codeforces.com/problemset/problem/1234/D

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
const int N = 5e5+5;
int n, m;

string str;

int st[4*N];

void build(int si, int ss, int se) {
    if(ss == se) {
        st[si] = 1 << (str[ss] - 'a');
        return;
    }
 
    int mid = (ss + se)/2;
    build(2*si , ss , mid);
    build(2*si+1 , mid+1 , se);
 
    st[si] = st[2*si] | st[2*si+1];
}


void update(int si, int ss, int se, int qi, char value) {
    if(ss == se) {
        // here ss == se == qi
        st[si] = 1 << (value - 'a');
        return;
    }

    ll mid = (ss + se) / 2;
    
    if(qi <= mid) update(2*si, ss, mid, qi, value);
    else update(2*si + 1, mid + 1, se, qi, value);

    st[si] = st[2*si] | st[2*si+1];
}

int query(int si , int ss , int se , int qs , int qe) {
    if(qe < ss || qs > se)
        return 0;
 
    if(ss >= qs && se <= qe)
        return st[si];
 
    int mid = (ss + se)/2;
    int l = query(2*si , ss , mid , qs , qe);
    int r = query(2*si+1 , mid+1 , se , qs , qe);

    return l | r;
}


void solve() {
    int x, y, k, l, r;
    cin >> str;
    cin >> m;
    n = str.size();
    str = "#" + str;
    build(1, 1, n);

    char ch;
    while(m--) {
        cin >> x;
        if(x == 1) {
            cin >> y >> ch;
            update(1, 1, n, y, ch);
        } else {
            cin >> l >> r;
            cout << __builtin_popcount(query(1, 1, n, l, r)) << endl;
        }
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
