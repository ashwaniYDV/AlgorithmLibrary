// https://cses.fi/problemset/task/1077
// https://youtu.be/a96aJIs_C00

/*
Special check for odd n even k--------------
If its odd, then the total number of elements other than the middle is even(k-1). So, half will be smaller and half will be larger.
So,  even if we inc or dec the middle, we don't need to recalculate. For Eg:
let array be - [1,2,3,7,8]. Here answer is 2+1+4+5 = 12
Change the middle to 5. Then answer is  (2+2) + (1+2) + (4-2) + (5-2) = 12.
So, if we add a new element and remove an older one, we just need to delete the previous diff and add the new difference.
Consider the previous example. If we add 9 to the array. Then although the middle changes the total value of previous elements is still 12. But we will add (9-new middle) to the answer. Since we remove one element, the previous diff is subtracted. 
Hence proved.

If it is even, then the number of smaller elements and the number of larger elements may differ by one, since k-1 will be an odd number.
So, let's say the number of smaller elements Is 2 and the number of larger elements is 3(k=6) initially.
We cannot guarantee that it stays the same in the new window. It may change to 3 smaller and 2 larger. Hence we apply the other logic to it.
*/

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
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1024;
const int N = 1e7+5;
int n, m;


void solve() {
    int k;
    cin >> n >> k;
    vector<int> a(n);
    f(i, n) cin >> a[i];

    ordered_set s;
    for (int i = 0; i < k; i++) s.insert(a[i]);
    ll old_m = *s.find_by_order((k + 1) / 2 - 1);
    ll d = 0;
    for (int i = 0; i < k; i++) d += abs(a[i] - old_m);
    cout << d;
    for (int i = 0; i < n - k; i++) {
        s.erase(s.find_by_order(s.order_of_key(a[i])));
        s.insert(a[i + k]);
        ll new_mid = *s.find_by_order((k + 1)/ 2 - 1);
        d = d + abs(new_mid - a[i + k]) - abs(old_m - a[i]);
        if (k % 2 == 0) d -= (new_mid - old_m);
        old_m = new_mid;
        cout << " " << d;
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
