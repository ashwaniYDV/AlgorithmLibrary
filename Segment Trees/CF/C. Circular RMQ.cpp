// https://codeforces.com/contest/52/problem/C


const int N = 1e6+5;
int n, m;

int arr[N], tree[4 * N], lazy[4 * N];
 
void build(int node, int start, int end) {
    if(start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}
 
void update(int node, int start, int end, int l, int r, int val) {
    if(lazy[node] != 0) {
        tree[node] += lazy[node];
        if(start != end) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(l > end || r < start || l > r) return;

    if(l <= start && end <= r) {
        tree[node] += val;
        if(start != end) {
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
        lazy[node] = 0;
        return;
    }
    int mid = (start + end) / 2;
    update(2*node, start, mid, l, r, val);
    update(2*node+1, mid+1, end, l, r, val);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}
 
int query(int node, int start, int end, int l, int r) {
    if(lazy[node] != 0) {
        tree[node] += lazy[node];
        if(start != end) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(l > end || r<start || l > r)return INT_MAX;

    if(l <= start && end <= r) return tree[node];

    int mid = (start + end) / 2;
    return min(query(2*node, start, mid, l, r), query(2*node+1, mid+1, end, l, r));
}


void solve() {
    int q, t, x, y, l, r, v;
    cin >> n;
    loop(i, 1, n) cin >> arr[i];
    build(1, 1, n);

    cin >> q;

    string s;
    cin.ignore();
    int a[3];
    while(q--) {
        getline(cin, s, '\n');
        stringstream in (s);
        in >> a[0] >> a[1];
        if(in >> a[2]) {
            if(a[0] > a[1]) {
                update(1, 1, n, 1, a[1] + 1, a[2]);
                update(1, 1, n, a[0] + 1, n, a[2]);
            } else {
                update(1, 1, n, a[0] + 1, a[1] + 1, a[2]);
            }
        } else {
            if(a[0] > a[1]) {
                cout << min(query(1, 1, n, 1, a[1] + 1), query(1, 1, n, a[0] + 1, n)) << endl;
            }else{
                cout << query(1, 1, n, a[0] + 1, a[1] + 1) << endl;
            }
        }
    }
}





























// Struct Template
const int N = 2e5+5;
int n, m;
 
int arr[N];

struct Node {
    //Use required attributes
    int val;
    //Default Values
    Node() : val(INF) {};
};

struct SegTree {
    int N;
    vector<Node> st;
    vector<bool> cLazy;
    vector<int> lazy;

    void init(int n) {
        N = n;
        st.resize(4 * N + 5);
        cLazy.assign(4 * N + 5, false);
        lazy.assign(4 * N + 5, 0);
    }

    //Write reqd merge functions
    void merge(Node &cur, Node &l, Node &r) {
        cur.val = min(l.val, r.val);
    }
    
    //Handle lazy propagation appriopriately
    void propagate(int node, int L, int R) {
        if(L != R) {
            cLazy[node*2] = 1;
            cLazy[node*2 + 1] = 1;
            lazy[node*2] += lazy[node];
            lazy[node*2 + 1] += lazy[node];
        }
        st[node].val += lazy[node];
        cLazy[node] = 0;
        lazy[node] = 0;
    }

    void build(int node, int L, int R) {
        if(L == R) {
            st[node].val = arr[L];
            return;
        }
        int M = (L + R)/2;
        build(node*2, L, M);
        build(node*2 + 1, M + 1, R);
        merge(st[node], st[node*2], st[node*2+1]);
    }

    Node Query(int node, int L, int R, int i, int j) {
        if(cLazy[node]) 
            propagate(node, L, R);
        if(j < L || i > R) 
            return Node();
        if(i <= L && R <= j) 
            return st[node];

        int M = (L + R)/2;
        Node left = Query(node*2, L, M, i, j);
        Node right = Query(node*2 + 1, M + 1, R, i, j);
        Node cur;
        merge(cur, left, right);
        return cur;
    }

    Node pQuery(int node, int L, int R, int pos) {
        if(cLazy[node]) 
            propagate(node, L, R);
        if(L == R) 
            return st[node];

        int M = (L + R)/2;
        if(pos <= M)
            return pQuery(node*2, L, M, pos);
        else
            return pQuery(node*2 + 1, M + 1, R, pos);
    }   

    void Update(int node, int L, int R, int i, int j, int val) {
        if(cLazy[node]) 
            propagate(node, L, R);
        if(j < L || i > R) 
            return;

        if(i <= L && R <= j) {
            cLazy[node] = 1;
            lazy[node] = val;
            propagate(node, L, R);
            return;
        }
        int M = (L + R)/2;
        Update(node*2, L, M, i, j, val);
        Update(node*2 + 1, M + 1, R, i, j, val);
        merge(st[node], st[node*2], st[node*2 + 1]);
    }

    void pUpdate(int node, int L, int R, int pos, int val) {
        if(cLazy[node]) 
            propagate(node, L, R);
        if(L == R) {
            cLazy[node] = 1;
            lazy[node] = val;
            propagate(node, L, R);
            return;
        }

        int M = (L + R)/2;
        if(pos <= M)
            pUpdate(node*2, L, M, pos, val);
        else
            pUpdate(node*2 + 1, M + 1, R, pos, val);

        merge(st[node], st[node*2], st[node*2 + 1]);
    }

    Node query(int pos) {
        return pQuery(1, 1, N, pos);
    }

    Node query(int l, int r) {
        return Query(1, 1, N, l, r);
    }

    void update(int pos, int val) {
        pUpdate(1, 1, N, pos, val);
    }

    void update(int l, int r, int val) {
        Update(1, 1, N, l, r, val);
    }
};

void solve() {
    int q, t, x, y, l, r, v;
    cin >> n;
    loop(i, 1, n) cin >> arr[i];
    SegTree st;
    st.init(n);
    st.build(1, 1, n);

    cin >> q;

    string s;
    cin.ignore();
    int a[3];
    while(q--) {
        getline(cin, s, '\n');
        stringstream in (s);
        in >> a[0] >> a[1];
        if(in >> a[2]) {
            if(a[0] > a[1]) {
                st.update(1, a[1] + 1, a[2]);
                st.update(a[0] + 1, n, a[2]);
            } else {
                st.update(a[0] + 1, a[1] + 1, a[2]);
            }
        } else {
            if(a[0] > a[1]) {
                cout << min(st.query(1, a[1] + 1).val, st.query(a[0] + 1, n).val) << endl;
            }else{
                cout << st.query(a[0] + 1, a[1] + 1).val << endl;
            }
        }
    }
}
