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
    cin >> n;
    loop(i, 1, n) cin >> arr[i];
    SegTree st;
    st.init(n);
    st.build(1, 1, n);
}
