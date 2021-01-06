// Scanline Algo concept

// Reference Problem:     https://www.codechef.com/BYTR20B/problems/AGCY
// Editorial:             https://discuss.codechef.com/t/agcy-editorial/83045

/*
Given an array, A of size N initially filled with 0's, 
For each query containing two integers L, R 
add 1 to A[L], 2 to A[L+1], 3 to A[L+2] ... (R-L+1) to A[R]. 
In general, add i+1 to A[L+i] for every L<=i <= R.
Do this for all q queries.
Find the final array.
*/

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
    int x, y, l, r, q;
    cin >> n >> q;
    vector<int> pref(n+5, 0);
    vector<int> res(n+5, 0);
    while(q--) {
        cin >> l >> r;
        pref[l] += 1;
        pref[r+1] -= 1;

        // res[l] += 1;      (do not do this line)
        res[r+1] -= (r - l + 1);
    }

    // normal prefix sum
    for(int i = 1; i <= n; i++) {
        pref[i] += pref[i - 1];
    }

    // answer generation
    for(int i = 1; i <= n; i++) {
        res[i] += (res[i - 1] + pref[i]);
    }

    for(int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
 
/*
Input: 
5
3
1 3
2 3
2 4

Output:
1 4 7 3 0 

Explanation:
After 1st query array is:    1, 2, 3, 0, 0
After 2nd query array is:    1, 3, 5, 0, 0
After 3rd query array is:    1, 4, 7, 3, 0
*/
