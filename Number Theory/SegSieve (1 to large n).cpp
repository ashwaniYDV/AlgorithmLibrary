// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435a5b/000000000077a8e6
// https://www.geeksforgeeks.org/segmented-sieve/

/*
Tested for finding primes from 1 to 1e9
*/

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_map;
// methods: find_by_order(k); & order_of_key(k); To make it an ordered_multiset, use pairs of (value, time_of_insertion) to distinguish values which are similar
 
typedef long long int ll;
#define int long long int
#define ld long double
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PRECISION(x) cout << setprecision(x); cout << fixed;
#define debug(x) cout << #x << " is: " << (x) << endl;
#define debug2(x,y) cout << (#x) <<", "<<(#y)<< " are: " << (x) <<", "<<(y)<< endl;
#define debugx(x) cout << #x << " is: " << (x) << endl; exit(0);
#define kickstart(testcase, res) cout << "Case #" << testcase << ": " << res << endl;
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
#define MOD2 998244353
#define INT_INF 1011111111
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 2e6+5;
const int N = 1e5+5;
int n, m;

vector<int> prGlobal;

// This functions finds all primes smaller than 'limit'
// using simple sieve of eratosthenes. It also stores
// found primes in vector prime[]
void simpleSieve(int limit, vector<int> &prime)
{
	// Create a boolean array "mark[0..n-1]" and initialize
	// all entries of it as true. A value in mark[p] will
	// finally be false if 'p' is Not a prime, else true.
	vector<bool> mark(limit + 1, true);

	for (int p=2; p*p<limit; p++)
	{
		// If p is not changed, then it is a prime
		if (mark[p] == true)
		{
			// Update all multiples of p
			for (int i=p*p; i<limit; i+=p)
				mark[i] = false;
		}
	}

	// Print all prime numbers and store them in prime
	for (int p=2; p<limit; p++)
	{
		if (mark[p] == true)
		{
			prime.push_back(p);
			prGlobal.push_back(p);
		}
	}
}

// Prints all prime numbers smaller than 'n'
void segmentedSieve(int n) {
	// Compute all primes smaller than or equal
	// to square root of n using simple sieve
	int limit = floor(sqrt(n))+1;
	vector<int> prime;
	prime.reserve(limit);
	simpleSieve(limit, prime);

	// Divide the range [0..n-1] in different segments
	// We have chosen segment size as sqrt(n).
	int low = limit;
	int high = 2*limit;

	// While all segments of range [0..n-1] are not processed,
	// process one segment at a time
	while (low < n)
	{
		if (high >= n)
		high = n;
		
		// To mark primes in current range. A value in mark[i]
		// will finally be false if 'i-low' is Not a prime,
		// else true.
		bool mark[limit+1];
		memset(mark, true, sizeof(mark));

		// Use the found primes by simpleSieve() to find
		// primes in current range
		for (int i = 0; i < prime.size(); i++)
		{
			// Find the minimum number in [low..high] that is
			// a multiple of prime[i] (divisible by prime[i])
			// For example, if low is 31 and prime[i] is 3,
			// we start with 33.
			int loLim = floor(low/prime[i]) * prime[i];
			if (loLim < low)
				loLim += prime[i];

			/* Mark multiples of prime[i] in [low..high]:
				We are marking j - low for j, i.e. each number
				in range [low, high] is mapped to [0, high-low]
				so if range is [50, 100] marking 50 corresponds
				to marking 0, marking 51 corresponds to 1 and
				so on. In this way we need to allocate space only
				for range */
			for (int j=loLim; j<high; j+=prime[i])
				mark[j-low] = false;
		}

		// Numbers which are not marked as false are prime
		for (int i = low; i<high; i++) {
			if (mark[i - low] == true) {
				prGlobal.push_back(i);
			}
		}

		// Update low and high for next segment
		low = low + limit;
		high = high + limit;
	}
}

vector<int> pref;
void precalc() {
	// int n = 1000000531;
	int n = 1000000009+1;
	segmentedSieve(n);
	for(int i = 0; i < prGlobal.size() - 1; i++) {
		pref.push_back(prGlobal[i] * prGlobal[i+1]);
	}
}

void solve(int testcase) {
	int x, y, z;
	cin >> n;
    x = lower_bound(pref.begin(), pref.end(), n) - pref.begin();
    cout << "Case #" << testcase << ": ";
    if(pref[x] == n)
        cout << pref[x] << endl;
    else
        cout << pref[x-1] << endl;
}
 
signed main() {
	IOS
	precalc();
	int t = 1;
	cin >> t;
	f(i, t) {
		solve(i+1);
	}
} 
