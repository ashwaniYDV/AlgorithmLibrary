// https://codeforces.com/contest/1547/problem/F
// https://www.geeksforgeeks.org/iterative-segment-tree-range-minimum-query/
// https://codeforces.com/blog/entry/18051

// https://youtu.be/ljVWVWgs2fQ

int arr[2 * (int)(2e5+5)];

struct segment_tree {
    vector<int> sgt;
    int n;
    segment_tree(int _n) {
        n = _n;
        sgt.resize(2 * n);
    }
    void build() {
        for(int i = 0; i < n; i++) {
          sgt[n + i] = arr[i];
        }
        for(int i = n - 1; i >= 1; i--) {
            sgt[i] = __gcd(sgt[2 * i], sgt[2 * i + 1]);
        }
    }
    int query(int l, int r) {
        l += n;
        r += n;
        int res = 0;
        while(l <= r) {
            if(l&1) {
                res=__gcd(res,sgt[l]);
                l++;
            }
            if(!(r&1)) {
                res=__gcd(res,sgt[r]);
                r--;
            }
            l=l>>1; // l=l/2;
            r=r>>1; // r=r/2;
        }
        return res;
    }
};
 
bool check(int mid, int n, segment_tree &st) {
    map<int, int> mp;
    for(int i = 0; i <= n - mid; i++){
      mp[st.query(i, i + mid - 1)]++;
    }
    return (mp.size() == 1);
}
void solve(){
    cin >> n;
    f(i, n) {
        cin >> arr[i];
        arr[n + i] = arr[i];
    }
    
    m = 2*n;
    segment_tree st(m);
    st.build();

    int lo = 1, hi = n;
    while(lo < hi) {
        int mid = (lo + hi) >> 1;
        if(check(mid, m, st)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    int res = lo;
    cout << res - 1 << endl;
}
 
signed main() {
    IOS
    clock_t begin = clock();
    int t = 1;
    cin >> t;
    f(i, t) {
        solve();
    }
    cerr<<"Time elapsed: "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
}
