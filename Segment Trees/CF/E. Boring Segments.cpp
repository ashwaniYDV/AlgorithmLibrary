// https://codeforces.com/contest/1555/problem/E


const int N = 1e6+5;
int n, m;
 
ll arr[N], tree[4 * N], lazy[4 * N];
 
void build(ll node, ll start, ll end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    ll mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
 
void update(ll node, ll start, ll end, ll l, ll r, ll val) {
    if (lazy[node] != 0) {
        tree[node] += lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (l > end || r < start || l > r) return;
    if (l <= start && end <= r) {
        tree[node] += val;
        if (start != end) {
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
        }
        lazy[node] = 0;
        return;
    }
    ll mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, val);
    update(2 * node + 1, mid + 1, end, l, r, val);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
 
ll query(ll node, ll start, ll end, ll l, ll r) {
    if (lazy[node] != 0) {
        tree[node] += lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (l > end || r < start || l > r) return INT_MAX;
    if (l <= start && end <= r) return tree[node];
    ll mid = (start + end) / 2;
    return min(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
}
 
struct range {
    int l, r, w;
    bool operator<(const range& a){
        return w < a.w;
    }
};
 
void solve() {
    int x, y, z, k, l, r;
    cin >> n >> m;
    vector<range> a(n);
 
    f(i, n) {
        cin >> l >> r >> x;
        a[i] = {l, r - 1, x};
    }
 
    sort(all(a));
 
    // 2 pointer technique
    int left = 0, ans = INF;
    for(int right = 0; right < n; right++) {
        update(1, 1, m - 1, a[right].l, a[right].r, +1);

        while(query(1, 1, m - 1, 1, m - 1) > 0) {
        // while(tree[1] > 0) {
            ans = min(ans, a[right].w - a[left].w);
            update(1, 1, m - 1, a[left].l, a[left].r, -1);
            left++;
        }
    }
    cout << ans << endl;
}
