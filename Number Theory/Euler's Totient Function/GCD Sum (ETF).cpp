/*
GCD Sum using Euler Totient Function
Que: Given q queries with integer n,
gcd(1, n) + gcd(2, n) + gcd(3, n) + ... + gcd(n, n) = ______ 
// https://youtu.be/khCze6j1vXg
NOTE:
preprocessing init_phi time = O(Nlog(logN))
Overal for q queries, time = O(Nlog(log(N)) + Q.sqrt(N))
*/

/*
Naive Approach: (Time Complexity: O(N * log N))
A simple solution is to iterate over all numbers from 1 to N and find their gcd with N itself and keep on adding them.

Efficient Approach: 
To optimize the above-mentioned approach, we need to observe that GCD(i, N) gives one of the divisors of N. 
So if divisors of N are = d1, d2, ..., dm
Then GCD(i, N) = belongs to one of {d1, d2, ..., dm}
So, instead of running a loop from 1 to N, we can check for each divisor of N that how many numbers are there with GCD(i, N) same as that divisor.

So we have to find the number of integers from 1 to N with GCD d, where d is a divisor of N. 
Let us consider x1, x2, x3,..., xn as the different integers from 1 to N such that their GCD with N is d.
Since, GCD(xi, N) = d, then GCD(xi/d, N/d) = 1
So, count of integers from 1 to N whose GCD with N is d is Euler Totient Function of (N/d).

Illustration: 
For example N = 12, its divisors are 1, 2, 3, 4, 6, 12. 
Numbers in range [1, 12] whose GCD with 12 is:

1 are {1, 5, 7, 11}
2 are {2, 10}
3 are {3, 9}
4 are {4, 8}
6 is {6}
12 is {12}
So answer is; 1*4 + 2*2 + 3*2 + 4*2 + 6*1 + 12*1 = 40.
*/

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
typedef long long int ll;
#define int long long int
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
#define endl "\n"
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<vector<ll>> matrix;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
const ll N = 1e6;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

ll phi[N + 1];

// Euler Phi Function in O(Nlog(logN)) [preprocessing time (similar to sieve)]
void init_phi() {
    for(ll i = 1; i <= N; i++) {
        phi[i] = i;
    }

    for(ll i = 2; i <= N; i++) {
        if(phi[i] == i) {
            for(ll j = i; j <= N; j += i) {
            phi[j] *= (i - 1);
            phi[j] /= i;
           } 
        }
    }
}

ll getCount(ll d, ll n) {
    return phi[n / d];
}

void solve() {
    ll t;
    init_phi();
    cin >> t;
    while(t--){
        cin >> n;
        ll res = 0;
        // all divisors of n
        for(ll i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                ll d1 = i;
                ll d2 = n / i;

                res += d1 * getCount(d1, n);

                if(d1 != d2) 
                    res += d2 * getCount(d2, n);
            }
        }
        cout << res << endl;
    }
} 
 
int32_t main() {
    IOS
    clock_t begin = clock();
    ll T = 1;
    // cin >> T;
    while(T--)
    solve();
    cerr<<"Time elapsed : "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
    return 0;
}





























// Method 2: (GFG) (Phi is not precomputed initially)
// C++ Program to find the Sum of GCD of all integers up to N with N itself
#include <bits/stdc++.h>
using namespace std;


int getCount(int d, int n) {
	int no = n / d;

	int result = no;

	// Consider all prime factors of no. and subtract their multiples from result
	for (int p = 2; p * p <= no; ++p) {

		// Check if p is a prime factor
		if (no % p == 0) {

			// If yes, then update no and result
			while (no % p == 0)
				no /= p;
			result -= result / p;
		}
	}

	// If no has a prime factor greater than sqrt(n) then at-most one such prime factor exists
	if (no > 1)
		result -= result / no;

	// Return the result
	return result;
}

// Finding GCD of pairs
int sumOfGCDofPairs(int n) {
	int res = 0;

	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			// Calculate the divisors
			int d1 = i;
			int d2 = n / i;

			// Return count of numbers from 1 to N with GCD d with N
			res += d1 * getCount(d1, n);

			// Check if d1 and d2 are equal then skip this
			if (d1 != d2)
				res += d2 * getCount(d2, n);
		}
	}

	return res;
}

// Driver code
int main() {
	int n = 12;

	cout << sumOfGCDofPairs(n);

	return 0;
}
