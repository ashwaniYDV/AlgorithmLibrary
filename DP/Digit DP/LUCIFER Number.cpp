// https://www.spoj.com/problems/LUCIFER
// https://youtu.be/XfeWIsrCS1o

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
typedef long long int ll;
// #define int long long int
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<vector<ll>> matrix;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
const ll N = 1e5+2;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

bool isPrime(int x) {
    if(x <= 1) return false;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

ll l, r, digit, totalCount;
ll dp[11][2][60][60];

ll digit_dp(string str, ll pos = 0, ll tight = 1, ll eveSum = 0, ll oddSum = 0){
    if(pos == str.length()){
        if(str.size() % 2) {
            /*
            Eg: 1234
            My soln.
            eveSum = 1 + 3
            oddSum = 2 + 4

            Acc to que.
            eveSum = 3 + 1
            oddSum = 4 + 2
            */
            if(isPrime(oddSum - eveSum)) return 1;
            else return 0;
        }else{
            /*
            Eg: 12345

            My soln.
            eveSum = 1 + 3 + 5
            oddSum = 2 + 4

            Acc to que.
            eveSum = 4 + 2
            oddSum = 5 + 3 + 1
            */
            if(isPrime(eveSum - oddSum)) return 1;
            else return 0;
        }
    }

    if(dp[pos][tight][eveSum][oddSum] != -1) return dp[pos][tight][eveSum][oddSum];

    ll res = 0;
    if(tight == 1){
        for(ll i = 0; i <= str[pos] - '0'; i++){
            ll od = oddSum, ev = eveSum;
            if(pos % 2) {
                od += i;
            } else {
                ev += i;
            }
            if(i == str[pos] - '0'){
                res += digit_dp(str, pos + 1, 1, ev, od);
            }else{
                res += digit_dp(str, pos + 1, 0, ev, od);
            }
        }
    }else{
        for(ll i = 0; i <= 9; i++){
            ll od = oddSum, ev = eveSum;
            if(pos % 2) {
                od += i;
            } else {
                ev += i;
            }
            res += digit_dp(str, pos + 1, 0, ev, od);
        }
    }
    return dp[pos][tight][eveSum][oddSum] = res;
}

void solve(){
    cin >> l >> r;
    setmem(dp, -1);
    string str = to_string(r);
    ll ans1 = digit_dp(str);
    setmem(dp, -1);
    str = to_string(l - 1);
    ll ans2 = digit_dp(str);
    cout << ans1 - ans2 << endl;
}

int32_t main() {
    IOS
    clock_t begin = clock();
    ll T = 1;
    cin >> T;
    while(T--)
    solve();
    cerr<<"Time elapsed : "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
    return 0;
}
