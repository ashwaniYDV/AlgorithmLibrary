#include<bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
typedef long long int ll;
#define int long long int
#define ld long double
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
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define MOD2 998244353
#define INT_INF 1011111111
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 2e5+5;
int n, m;

#define cd complex<double>
const double pi = 4*atan(1);
int FFT_N = 0;
vector<cd> omega;
 
void init_fft(int n) {
    FFT_N = n;
    omega.resize(n);
    double angle = 2 * pi / n;
    for (int i = 0; i < n; i++) {
        omega[i] = cd(cos(i*angle), sin(i*angle));
    }
}
 
void fft(vector<cd> &a) {
    int n = a.size();
    if(n == 1) return;

    int half = n >> 1;
    vector<cd> even(half), odd(half);
    for(int i = 0, j = 0; i < n; i += 2, j++) {
        even[j] = a[i];
        odd[j] = a[i+1];
    }

    fft(even);
    fft(odd);

    int denominator = FFT_N / n;
    for (int i = 0; i < half; i++) {
        cd cur = odd[i] * omega[i * denominator];
        a[i] = even[i] + cur;
        a[i+half] = even[i] - cur;
    }
}
 
void multiply(vector<int> &a, vector<int> &b, vector<int> &res) {
    vector<cd> f_a(a.begin(), a.end());
    vector<cd> f_b(b.begin(), b.end());
    
    int n = 1;
    while(n < 2 * max(a.size(), b.size())) {
        n <<= 1;
    }

    f_a.resize(n);
    f_b.resize(n);

    init_fft(n);
    fft(f_a);
    fft(f_b);

    for (int i = 0; i < n; i++) {
        f_a[i] = conj(f_a[i] *  f_b[i]);
    }
    fft(f_a);

    res.resize(n);
    for (int i = 0; i < n; i++) {
        res[i] = (long long)(f_a[i].real() / n + 0.5);
        res[i] %= MOD;
    }
}

void solve() {
    vector<int> a = {5, 0, 10, 6}, b = {1, 2, 4}, res;
    multiply(a, b, res);

    for(int x: res) cout << x << " ";
}
 
int32_t main() {
    IOS
    PRECISION(10)
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
