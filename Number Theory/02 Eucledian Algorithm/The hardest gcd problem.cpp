// https://www.codechef.com/problems/GCDDIV

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
const int MAXN = 1024;
const int N = 1e6+5;
int n, m;

int maxFactor(int n) {
    int mx = 1;

    while(n % 2 == 0) {
        mx = 2;
        n /= 2;
    }

    for(int i = 3; i*i <= n; i += 2) {
        while(n % i == 0) {
            mx = i;
            n /= i;
        }
    }

    if(n > 2) mx = max(mx, n);

    return mx;
}

void solve() {
    int x, y, k;
    cin >> n >> k;
    int a[n];
    f(i, n) cin >> a[i];

    int gcdd = 0;
    f(i, n) gcdd = __gcd(gcdd, a[i]);

    int mx = maxFactor(gcdd);

    if(mx <= k) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main() {
    IOS
    int T = 1;
    cin >> T;
    while(T--)
    solve();
    return 0;
}
