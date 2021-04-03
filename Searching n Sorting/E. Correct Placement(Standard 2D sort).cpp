/*
Que: https://codeforces.com/contest/1472/problem/E
Editorial: https://youtu.be/SWIsmxZ2OSM
Blog: http://codingwithrajarshi.blogspot.com/2018/07/moving-up-dimension-part-1.html
      http://codingwithrajarshi.blogspot.com/2018/07/moving-up-dimension-part-2.html
*/

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
const int MAXN = 5e5+5;
const int N = 1e6+5;
int n, m;

void solve() {
    int q, t, x, y, l, r, v;
    cin >> n;
    
    vector<pair<pair<int, int>, int>> arr; // {{w, -h}, index}
    
    loop(i, 1, n) {
        int h, w;
        cin >> h >> w;
        arr.pb({{w, -h}, i});
        arr.pb({{h, -w}, i});
    }
    
    sort(all(arr)); // sorted in increasing width and decreasing height
    
    int minheight = INF;
    int pos = -1;
    
    vector<int> ans(n+1, -1);
    
    for(auto tmp: arr){
        int w = tmp.F.F;
        int h = -tmp.F.S;
        int idx = tmp.S;

        if(h > minheight) {
            ans[idx] = pos;
        } else if(h < minheight) {
            minheight = h;
            pos = idx;
        }
    }
    
    loop(i, 1, n){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int32_t main() {
    IOS
    int T = 1;
    cin >> T;
    while(T--)
    solve();
    return 0;
}
