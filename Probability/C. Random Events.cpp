// https://codeforces.com/contest/1461/problem/C

/*
total prob = (success1) + (filure1*success2) + (filure1*filure2*success3) + (filure1*filure2*filure3*success4) + ...........
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
const int N = 1e5+5;
int n, m;


void solve() {
    int x, y, z, u, v;
    cin >> n >> m;
    int a[n+1];

    // index = largest i such that a[i] != i
    int index = 0;
    loop(i, 1, n) {
        cin >> a[i];
        if(a[i] != i) index = i;
    }

    double ans = 0.0;
    double prevFail = 1.0;
    f(i, m) {
        double prob;
        cin >> x >> prob;
        if(x >= index) {
            ans += prob*prevFail;
            prevFail *= (1 - prob);
        }
    }

    if(index == 0) {
        cout << 1.000000 << endl;
        return;
    }

    cout << ans << endl;

}
 
int32_t main() {
    IOS
    PRECISION(9)
    int T = 1;
    cin >> T;
    while(T--)
    solve();
    return 0;
}














/*
Method 2
total prob = 1 - allFailure;
           = 1 - (failure1*failure2*failure3*....)
*/

void solve() {
    int x, y, z, u, v;
    cin >> n >> m;
    int a[n+1];

    // index = largest i such that a[i] != i
    int index = 0;
    loop(i, 1, n) {
        cin >> a[i];
        if(a[i] != i) index = i;
    }

    double allFail = 1.0;
    f(i, m) {
        double prob;
        cin >> x >> prob;
        if(x >= index) {
            allFail *= (1 - prob);
        }
    }

    if(index == 0) {
        cout << 1.000000 << endl;
        return;
    }
    
    double ans = 1 - allFail;
    cout << ans << endl;

}
