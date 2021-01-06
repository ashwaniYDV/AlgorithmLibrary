// https://codeforces.com/contest/1466/problem/E

#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
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
    cin >> n;
    int a[n];
    int cnt[64] = {0};

    f(i, n){
        cin >> a[i];
        for(int j = 0; j <= 62; j++) {
            if((1ll << j) & a[i]) {
                cnt[j]++;
            }
        }
    }

    int ans = 0;

    f(j, n) {
        int sum1 = 0;
          for(int b = 0; b <= 62; b++) {
            if((1ll << b) & a[j]) {
                  sum1 += (((1ll << b)%MOD) * (cnt[b])) % MOD;
            }
            sum1 %= MOD;
        }

        int sum2 = 0;
        for(int b = 0; b <= 62; b++) {
            if((1ll << b) & a[j]) {
                  sum2 += (((1ll << b)%MOD)*n) % MOD;
            } else {
                  sum2 += (((1ll<<b)%MOD) * (cnt[b])) % MOD;
            }
            sum2 %= MOD;
        }
          
        ans += (sum1 * sum2) % MOD;
        if(ans >= MOD) ans -= MOD;
    }

    cout << ans << endl;
}
 
int32_t main() {
    IOS
    int T = 1;
    cin >> T;
    while(T--)
    solve();
    return 0;
}
