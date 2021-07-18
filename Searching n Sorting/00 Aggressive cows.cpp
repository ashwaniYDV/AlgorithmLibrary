// https://www.spoj.com/problems/AGGRCOW/
// https://leetcode.com/problems/magnetic-force-between-two-balls/

/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. 
The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. 
To prevent the cows from hurting each other, John wants to assign the cows to the stalls, 
such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
*/


// TTTTTFFFFF


// Method 1
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

const int N = 1e6+5;
int n, m;

bool check(int mid, int c, vector<int>& a) {
    int cnt = 1, prevPos = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] - a[prevPos] >= mid) {
            prevPos = i, cnt++;
        }
    }
    return cnt >= c;
}
 
void solve() {
    int x, y, c;
    cin >> n >> c;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) cin >> a[i];
 
    sort(a.begin(), a.end());
 
    int lo = 0, hi = a[n-1];
    while(lo < hi) {
        // int mid = (lo + hi + 1) / 2;
        int mid = lo + (hi - lo + 1) / 2;

        if(check(mid, c, a)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo << endl;
}

int32_t main() {
    IOS
    #ifndef ONLINE_JUDGE 
      FRE 
    #endif
    int T = 1;
    cin >> T;
    while(T--) solve();
}






// Method 2
#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

const int N = 1e6+5;
int n, m;


bool check(int mid, int c, vector<int>& a) {
    int cnt = 1, prevPos = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] - a[prevPos] >= mid) {
            prevPos = i, cnt++;
        }
    }
    return cnt >= c;
}
 
void solve() {
    int x, y, c;
    cin >> n >> c;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) cin >> a[i];
 
    sort(a.begin(), a.end());
 
    int lo = 0, hi = a[n-1];
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if(check(mid, c, a)) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << hi << endl;
}

int32_t main() {
    IOS
    #ifndef ONLINE_JUDGE 
      FRE 
    #endif
    int T = 1;
    cin >> T;
    while(T--) solve();
}
