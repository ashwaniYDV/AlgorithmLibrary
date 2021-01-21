// https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
// https://youtu.be/BQ9E-2umSWc

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
const int N = 20;
int n, m;

int binpow(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// d is the number of characters in the input alphabet 
#define d 256 

void search(string str, string pat, int q) { 
    int n = str.size(), m = pat.size(); 
    int hashStr = 0, hashPat = 0; 

    // h = d^(m-1) % q 
    int h = binpow(d, m - 1, q);

    // Calculate the hash value of pattern and string on first window of text 
    for (int i = 0; i < m; i++) { 
        hashPat = (hashPat * d + pat[i]) % q; 
        hashStr = (hashStr * d + str[i]) % q; 
    } 

    // Slide the pattern over text one by one 
    for (int i = 0; i <= n - m; i++) { 

        // Check the hash values of current window of text and pattern. 
        // If the hash values match then only check for characters on by one.
        if ( hashPat == hashStr ) { 
            /* Check for characters one by one */
            for (int j = 0; j < m; j++) { 
                if (str[i+j] != pat[j]) break; 

                // if p == t and pat[0...m-1] = str[i, i+1, ...i+m-1] 
                if (j == m-1) cout << "Pattern found at index "<< i << endl; 
            } 
        } 

        // Calculate hash value for next window of text: 
        // Remove leading digit, add trailing digit 
        if ( i < n-m ) { 
            hashStr = ((hashStr - str[i] * h) * d + str[i+m]) % q; 

            // We might get negative value of t, converting it to positive 
            if (hashStr < 0) 
            hashStr = (hashStr + q); 
        } 
    } 
} 


void solve() {
    string str = "GEEKS FOR GEEKS"; 
    string pat = "GEEK"; 
    int q = 101; // A prime number 
    search(str, pat, q); 
}

int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
