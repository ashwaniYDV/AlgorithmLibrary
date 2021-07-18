// https://codeforces.com/problemset/problem/1249/B2

/*
There are n kids, each of them is reading a unique book. 
At the end of any day, the i-th kid will give his book to the pi-th kid (in case of i=pi the kid will give his book to himself). 
It is guaranteed that all values of pi are distinct integers from 1 to n (i.e. p is a permutation). 
The sequence p doesn't change from day to day, it is fixed.

For example, if n=6 and p=[4,6,1,3,5,2] then:
At the end of the first day 
    the book of the 1-st kid will belong to the 4-th kid, the 2-nd kid will belong to the 6-th kid and so on. 
At the end of the second day 
    the book of the 1-st kid will belong to the 3-th kid, the 2-nd kid will belong to the 2-th kid and so on.

Your task is to determine the number of day, book of i-th child is returned back to him for the first time for every i from 1 to n.

Consider the following example: p=[5,1,2,4,3]. 
The book of the 1-st kid will be passed to the following kids:

after the 1-st day it will belong to the 5-th kid,
after the 2-nd day it will belong to the 3-rd kid,
after the 3-rd day it will belong to the 2-nd kid,
after the 4-th day it will belong to the 1-st kid.
So after the fourth day, the book of the first kid will return to its owner. 

The book of the fourth kid will return to him for the first time after exactly one day.
*/


/*
answer is size of connected component in which each 1..n belong
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define endl "\n"
#define f(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define int long long

int n, m;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};


struct DSU {
    vector<int> par;
    DSU(int n) {
        par.resize(n+1, -1);
    }
    int findParent(int a) {
        if(par[a] < 0) return a;
        return par[a] = findParent(par[a]);
    }
    bool unionSet(int a, int b){
        a = findParent(a);
        b = findParent(b);
        if(a == b) return 0;
        if(par[a] > par[b]) swap(a,b);
        par[a] += par[b];
        par[b] = a;
        return 1;
    }
    bool sameSet(int x, int y) { 
        return findParent(x) == findParent(y); 
    }
    int size (int x) { 
        return -par[findParent(x)]; 
    }
};

// answer is size of connected component in which each 1..n belong
void solve() {
    int x, y;
    cin >> n;
    
    DSU dsu(n+1);

    for(int i = 1; i <= n; i++) {
      cin >> x;
      dsu.unionSet(i, x);
    }

    for(int i = 1; i <= n; i++) {
        cout << dsu.size(i) << " ";
    }

    cout << endl;
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
