// https://codeforces.com/contest/61/problem/E

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
vector<int> st[4 * N];

void merge(vector<int>& a, vector<int>& b, vector<int>& c) {
    int i = 0 , j = 0, n = a.size(), m = b.size();
    while(i < n && j < m) {
        if(a[i] < b[j]) {
            c.push_back(a[i]) , i++;
        } else {
            c.push_back(b[j]) , j++;
        }
    }
 
    while(i < n) c.push_back(a[i]) , i++;
    while(j < m) c.push_back(b[j]) , j++;
}

void build(int si , int ss , int se) {
    if(ss == se) {
        st[si].pb(arr[ss]);
        return;
    }
 
    int mid = (ss + se)/2;
    build(2*si , ss , mid);
    build(2*si+1 , mid+1 , se);
 
    // Method 1 (Creating our own merge function)
    // merge(st[2*si], st[2*si+1], st[si]);

    // Method 2 (Using C++ STL merge function)
    merge(st[2*si].begin(), st[2*si].end(), st[2*si + 1].begin(), st[2*si + 1].end(), back_inserter(st[si]));
}

int query(int si , int ss , int se , int qs , int qe, int value, int type) {
    if(qe < ss || qs > se) return 0;
 
    if(ss >= qs && se <= qe) {
        if(type == 1)
            return st[si].end() - upper_bound(st[si].begin(), st[si].end(), value);
        else
            return lower_bound(st[si].begin(), st[si].end(), value) - st[si].begin();
    };
 
    int mid = (ss + se)/2;
    int l = query(2*si , ss , mid , qs , qe, value, type);
    int r = query(2*si+1 , mid+1 , se , qs , qe, value, type);
    
    return l + r;
}


void solve(){
    int t, l, r, k;
    cin >> n;
    loop(i, 1, n) cin >> arr[i];
    build(1, 1, n);
    int ans = 0;
    // index 1 and n ele do not have any ele towards left and right respectively
    for(int i = 2; i <= n-1; i++) {
        ans += query(1, 1, n, 1, i-1, arr[i], 1) * query(1, 1, n, i+1, n, arr[i], 0);
    }
    cout << ans << endl;
} 
 
int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
