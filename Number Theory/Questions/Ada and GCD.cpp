// https://www.spoj.com/problems/ADAGCD/

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
const int N = 1e7+5;
int n, m;


ll bin_pow(ll x, ll n){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return bin_pow((x*x)%MOD,n/2);
    else
        return (x*bin_pow((x*x)%MOD,(n-1)/2))%MOD;
}

// smallest prime factor
int spf[N];
void SPF() { 
    spf[1] = 1; 
    // marking smallest prime factor for every number to be itself.
    for (int i = 2; i < N; i++) spf[i] = i; 
  
    // separately marking spf for every even number as 2 
    for (int i=4; i<N; i+=2) spf[i] = 2;
  
    for (int i=3; i*i<N; i++) { 
        // checking if i is prime 
        if (spf[i] == i) { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<N; j+=i) 
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) spf[j] = i; 
        } 
    } 
} 

unordered_map<int, int> mp1, mp2, temp;

// A O(log n) function returning primefactorization by dividing by smallest prime factor at every step 
void getFactorization(int x) { 
    while (x != 1) {
        mp1[spf[x]]++; 
        x = x / spf[x]; 
    } 
} 


void solve() {
    int x, y, k;
    SPF();
    cin >> n;
    f(i, n) {
        cin >> m;
        f(j, m) {
            cin >> x;
            getFactorization(x);
        }

        if(i == 0) {
            mp2 = mp1;
        }

        for(auto i: mp1) {
            temp[i.F] = min(mp1[i.F], mp2[i.F]);
        }

        mp1.clear();
        mp2.clear();
        mp2 = temp;
        temp.clear();
    }

    int res = 1;
    for(auto i: mp2) {
        res = res * bin_pow(i.F, i.S);
        res %= MOD;
    }

    cout << res << endl;
}

int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
