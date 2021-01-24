// https://codeforces.com/contest/380/problem/C
// Blog: https://codeforces.com/blog/entry/15890

/*
For each node (for example x), we keep three integers : 
1. ans = Answer for it's interval. 
2. open = The number of "("s after deleting the brackets who belong to the correct bracket sequence in this interval with length ans. 
3. close = The number of ")"s after deleting the brackets who belong to the correct bracket sequence in this interval with length ans.


Lemma : For merging to nodes 2x and 2x + 1 (children of node x) all we need to do is this :

temp = min(open[2 * x], close[2 * x + 1])
ans[x] = ans[2 * x] + ans[2 * x + 1] + 2*temp
open[x] = open[2 * x] + open[2 * x + 1] - temp
close[x] = close[2 * x] + close[2 * x + 1] - temp
*/

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

string s;
struct node{
    int ans;
    int open;
    int close;
};
node st[4*N];

void build(int si , int ss , int se) {
    if(ss == se) {
        if(s[ss] == '(') {
            st[si].open = 1;
            st[si].close = 0;
            st[si].ans = 0;
        } else {
            st[si].open = 0;
            st[si].close = 1;
            st[si].ans = 0;
        }
        return;
    }
 
    int mid = (ss + se)/2;
    build(2*si , ss , mid);
    build(2*si+1 , mid+1 , se);
 
    int temp = min(st[2*si].open , st[2*si+1].close);

    st[si].ans = st[2*si].ans + st[2*si+1].ans + 2*temp;
    st[si].open = st[2*si].open + st[2*si+1].open - temp;
    st[si].close = st[2*si].close + st[2*si+1].close - temp;
}


node query(int si , int ss , int se , int qs , int qe) {
    if(qe < ss || qs > se)
        return {0, 0, 0};
 
    if(ss >= qs && se <= qe)
        return st[si];
 
    int mid = (ss + se)/2;
    node l = query(2*si , ss , mid , qs , qe);
    node r = query(2*si+1 , mid+1 , se , qs , qe);
 

    int temp = min(l.open , r.close);

    node tempNode;
    tempNode.ans = l.ans + r.ans + 2*temp;
    tempNode.open = l.open + r.open - temp;
    tempNode.close = l.close + r.close - temp;

    return tempNode;
}

void solve() {
    int x, y, t, l, r;
    cin >> s;
    n = s.size();
    s = "#" + s;
    build(1 , 1 , n);

    cin >> t;
    while(t--) {
        cin >> l >> r;

        node tempNode = query(1, 1, n, l, r);
        cout << tempNode.ans << endl;
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
