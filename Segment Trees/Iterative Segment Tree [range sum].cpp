// https://codeforces.com/blog/entry/18051
// https://www.geeksforgeeks.org/iterative-segment-tree-range-minimum-query/


int arr[N];

struct segment_tree {
    vector<int> sgt;
    int n;
    segment_tree(int _n) {
        n = _n;
        sgt.resize(2 * n);
    }
    int merge(int x, int y) {
        return x + y;
    }
    void build() {
        for(int i = 0; i < n; i++) {
          sgt[n + i] = arr[i];
        }
        for(int i = n - 1; i >= 1; i--) {
            sgt[i] = merge(sgt[2 * i], sgt[2 * i + 1]);
        }
    }
    int query(int l, int r) {
        l += n;
        r += n;
        int res = 0;
        while(l <= r) {
            if(l&1) {
                res = merge(res, sgt[l]);
                l++;
            }
            if(!(r&1)) {
                res = merge(res, sgt[r]);
                r--;
            }
            l = l >> 1; // l=l/2;
            r = r >> 1; // r=r/2;
        }
        return res;
    }

    void pointUpdate(int idx, int val) {
        idx += n;
        sgt[idx] = val;

        while (idx > 1) {
            idx /= 2;
            sgt[idx] = merge(sgt[2 * idx], sgt[2 * idx + 1]);
        }
    }
};

void solve() {
    cin >> n;
    f(i, n) {
        cin >> arr[i];
    }
    
    segment_tree st(n);
    st.build();
    st.pointUpdate(1, 10);
    f(i, n) cout << st.query(i, i) << endl;
}
