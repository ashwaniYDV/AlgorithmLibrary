// https://codeforces.com/contest/1000/problem/F

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
const int MAXN = 5e5 + 5;
const int N = 1e6+5;
int n, m;
 
// sqrt(n)
int BLOCK = 555;
 
struct query {
    int l, r, i;
    inline bool operator<(const query &o) const {
        if(l/BLOCK != o.l/BLOCK)
            return l < o.l;
        return l/BLOCK & 1 ? r < o.r : r > o.r;
    }
} Q[500005];
 
int ar[500005] , ans[500005];
int freq[1000001];
// int cnt = 0;
 
vector<int> v;
bool alreadyInV[N];
 
inline void updateV(int pos) {
    if(freq[ar[pos]] == 1 && !alreadyInV[ar[pos]]) {
        alreadyInV[ar[pos]] = true;
        v.pb(ar[pos]);
    }
}
 
inline void add(int pos) {
    freq[ar[pos]]++;
    // if(freq[ar[pos]] == 1) cnt++;
    updateV(pos);
    
}
 
inline void remove(int pos) {
    freq[ar[pos]]--;
    // if(freq[ar[pos]] == 0) cnt--;
    updateV(pos);
}
 
 
void solve() {
    int q;
    cin >> n;
    BLOCK = sqrt(n);
    f(i, n) cin >> ar[i];
    cin >> q;
    f(i, q){
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i;
        Q[i].l--, Q[i].r--;
    }
    sort(Q, Q + q);
 
    int ML = 0 , MR = -1;
    f(i, q){
        int L = Q[i].l;
        int R = Q[i].r;
        
 
        while(ML < L){
            remove(ML) , ML++;
        }
        while(ML > L){
            ML-- , add(ML);
        }
        while(MR < R){
            MR++ , add(MR);
        }
        while(MR > R){
            remove(MR) , MR--;
        }
 
        while(!v.empty() && freq[v.back()] != 1) {
            alreadyInV[v.back()] = 0;
            v.pop_back();
        }
 
        ans[Q[i].i] = v.empty() ? 0 : v.back();
    }
 
    f(i, q) cout << ans[i] << endl;
}   
 
int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
