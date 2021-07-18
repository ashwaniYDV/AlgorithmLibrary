// https://codeforces.com/contest/396/problem/C

/*
Problem:
You are given a rooted tree consisting of n vertices numbered from 1 to n. The root of the tree is a vertex number 1.
Initially all vertices contain number 0. Then come q queries, each query has one of the two types:
1) The format of the query: 1 v x k. 
   In response to the query, you need to add to the number at vertex v number x; to the numbers at the descendants of vertex v at distance 1, add x - k; and so on, 
   to the numbers written in the descendants of vertex v at distance i, you need to add x - (i*k). 
   The distance between two vertices is the number of edges in the shortest path between these vertices.
2) The format of the query: 2 v. 
   In reply to the query you should print the number written in vertex v modulo 1000000007 (10^9 + 7).
Process the queries given in the input.
*/



/*
Editorial:
We can write all vertices in the list in order of dfs, then the descendants of the vertex from a segment of this list. 
Let's count for every vertex its distance to the root level[v].

Let's create two segment trees st1 and st2. 
If we are given a query of the first type, in st1 we add x  +  level[v]*k to the segment corresponding to the vertex v, 
in st2 we add k to the segment corresponding to the vertex v.

If we are given a query of the second type, we write st1.get(v) - st2.get(v) * level[v].
The complexity is O(qlogn).

You can use any other data stucture that allows to add to the segment and to find a value of an arbitrary element.
Also there exists a solution using Heavy-Light decomposition.
*/



// Method 1: Segment Tree lazy range update and point query
const int N = 3e5+5;
int n, m;
vi g[N];

int subtreeSize[N], level[N];
int in[N];
int _timer;
 
// Euler Tour Technique (ETT)
void dfs(int u, int par, int lvl) {
    in[u] = _timer;
    _timer++;
    subtreeSize[u] = 1;
    level[u] = lvl;
    
    for(int v: g[u]) {
        if(v == par) continue;
        dfs(v, u, lvl + 1);
        subtreeSize[u] += subtreeSize[v];
    }
}

inline void add(int & a, int b) {
    a = (a + b) % MOD;
    if (a < 0) a += MOD;
}

struct SegTree {
    vi st, lazy;

    SegTree() {
        st = vector<int>(4*N, 0);
        lazy = vector<int>(4*N, 0);
    }

    void update(int si, int ss, int se, int qs, int qe, int val) {
        if(lazy[si] != 0) {
            int dx = lazy[si];
            lazy[si] = 0;
            // st[si] += dx * (se - ss + 1);
            add(st[si], dx * (se - ss + 1));


            if(ss != se){
                // lazy[2*si] += dx;
                add(lazy[2*si], dx);
                // lazy[2*si + 1] += dx;
                add(lazy[2*si + 1], dx);
            }
        }

        if(qe < ss || qs > se) return;

        if(ss >= qs && se <= qe){
            int dx = (se - ss + 1) * val;
            // st[si] += dx;
            add(st[si], dx);

            if(ss != se){
                // lazy[2*si] += val;
                add(lazy[2*si], val);
                // lazy[2*si + 1] += val;
                add(lazy[2*si + 1], val);
            }
            return;
        }

        int mid = (ss + se) / 2;
        
        update(2*si, ss, mid, qs, qe, val);
        update(2*si + 1, mid + 1, se, qs, qe, val);

        st[si] = (st[2*si] + st[2*si + 1] + MOD) % MOD;
    }

    int query(int si, int ss, int se, int qs, int qe) {
        if(lazy[si] != 0) {
            int dx = lazy[si];
            lazy[si] = 0;
            // st[si] += dx * (se - ss + 1);
            add(st[si], dx * (se - ss + 1));

            if(ss != se){
                // lazy[2*si] += dx;
                add(lazy[2*si], dx);
                // lazy[2*si + 1] += dx;
                add(lazy[2*si + 1], dx);
            }
        }

        if(qe < ss || qs > se) return 0;
     
        if(ss >= qs && se <= qe) return st[si];
     
        int mid = (ss + se)/2;
        int l = query(2*si , ss , mid , qs , qe);
        int r = query(2*si+1 , mid+1 , se , qs , qe);
        
        return (l + r + MOD) % MOD;
    }
};

void solve() {
    int x, y, z, q, u, v, k, par, type;
    cin >> n;
    
    loop(i, 2, n) {
        cin >> par;
        g[par].pb(i);
        g[i].pb(par);
    }
    
    _timer = 1;
    dfs(1 , -1, 0);
 
    SegTree st1, st2;

    cin >> q;

    while(q--) {
        cin >> type;
        if(type == 1) {
            cin >> u >> x >> k;
            st1.update(1, 1, n, in[u], in[u] + subtreeSize[u] - 1, x + level[u] * k);
            st2.update(1, 1, n, in[u], in[u] + subtreeSize[u] - 1, k);
        } else {
            cin >> u;
            int res = st1.query(1, 1, n, in[u], in[u]) - level[u] * st2.query(1, 1, n, in[u], in[u]);
            res = (res + MOD) % MOD;
            if(res < 0) res += MOD;
            cout << res << endl;
        }
    }
}


























// Method 1: BIT range update and point query
const int N = 3e5+5;
int n, m;
vi g[N];

int subtreeSize[N], level[N], in[N];
int _timer;
 
// Euler Tour Technique (ETT)
void dfs(int u, int par, int lvl) {
    in[u] = _timer;
    _timer++;
    subtreeSize[u] = 1;
    level[u] = lvl;
    
    for(int v: g[u]) {
        if(v == par) continue;
        dfs(v, u, lvl + 1);
        subtreeSize[u] += subtreeSize[v];
    }
}

inline void add(int & a, int b) {
    a = (a + b) % MOD;
    if (a < 0) a += MOD;
}

struct Fenwick {
    vi BIT;
    Fenwick() {
        BIT = vector<int>(N+5, 0);
    }
    void update(int i, int val) {
        while(i < N) {
            // BIT[i] += val;
            add(BIT[i], val);
            i += (i&-i);
        }
    }
    int query(int i) {
        int sum = 0;
        while(i > 0) {
            // sum += BIT[i];
            add(sum, BIT[i]);
            i -= (i&-i);
        }
        return sum;
    }
};

void solve() {
    int x, y, z, q, u, v, k, par, type;
    cin >> n;
    
    loop(i, 2, n) {
        cin >> par;
        g[par].pb(i);
        g[i].pb(par);
    }
    
    _timer = 1;
    dfs(1 , -1, 0);
 
    Fenwick bit1, bit2;

    cin >> q;

    while(q--) {
        cin >> type;
        if(type == 1) {
            cin >> u >> x >> k;
            int start = in[u], end = in[u] + subtreeSize[u] - 1;
            bit1.update(start, (x + level[u] * k));
            bit1.update(end + 1, -(x + level[u] * k));
            bit2.update(start, k);
            bit2.update(end + 1, -k);
        } else {
            cin >> u;
            int res = bit1.query(in[u]) - level[u] * bit2.query(in[u]);
            res = (res + MOD) % MOD;
            if(res < 0) res += MOD;
            cout << res << endl;
        }
    }
}
