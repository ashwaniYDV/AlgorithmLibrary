// https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/

// Method 1
const int N = 1e6+5;
int n, m;
 
int st[4*N], lazy[4*N], arr[N];

void build(int si , int ss , int se) {
    if(ss == se) {
        st[si] = arr[ss];
        return;
    }
 
    int mid = (ss + se)/2;
    build(2*si , ss , mid);
    build(2*si+1 , mid+1 , se);
 
    st[si] = st[2*si] + st[2*si+1];
}

void update(int si , int ss , int se , int qs, int qe, int val) {
    if(lazy[si] != 0) {
        st[si] += (se - ss + 1) * lazy[si];

        if(ss != se){
            lazy[2*si] += lazy[si];
            lazy[2*si + 1] += lazy[si];
        }
        lazy[si] = 0;
    }

    if(qe < ss || qs > se) return;

    if(ss >= qs && se <= qe){
        st[si] += (se - ss + 1) * val;

        if(ss != se){
            lazy[2*si] += val;
            lazy[2*si + 1] += val;
        }
        return;
    }

    int mid = (ss + se) / 2;
    
    update(2*si, ss, mid, qs, qe, val);
    update(2*si + 1, mid + 1, se, qs, qe, val);

    st[si] = st[2*si] + st[2*si + 1];
}

int query(int si , int ss , int se , int qs , int qe) {
    if(lazy[si] != 0) {
        st[si] += (se - ss + 1) * lazy[si];

        if(ss != se){
            lazy[2*si] += lazy[si];
            lazy[2*si + 1] += lazy[si];
        }
        lazy[si] = 0;
    }

    if(qe < ss || qs > se) return 0;
 
    if(ss >= qs && se <= qe) return st[si];
 
    int mid = (ss + se)/2;
    int l = query(2*si , ss , mid , qs , qe);
    int r = query(2*si+1 , mid+1 , se , qs , qe);
    
    return l + r;
}

void solve() {
    int q, t, l, r, val;
    cin >> n >> q;
    build(1 , 1 , n);

    while(q--) {
        cin >> t >> l >> r;
        if (t == 1){
            cout << query(1 , 1 , n , l , r)<<endl;
        } else {
            cin >> val;
            update(1, 1, n, l, r, val);
        }
    }
}






















// Method 2 (propagate function)
const int N = 1e6+5;
int n, m;
 
ll st[4*N], lazy[4*N], arr[N];

void build(ll si , ll ss , ll se) {
    if(ss == se) {
        st[si] = arr[ss];
        return;
    }
 
    ll mid = (ss + se)/2;
    build(2*si , ss , mid);
    build(2*si+1 , mid+1 , se);
 
    st[si] = st[2*si] + st[2*si+1];
}

void propagate(int si, int ss, int se) {
    st[si] += (se - ss + 1) * lazy[si];

    if(ss != se) {
        lazy[2*si] += lazy[si];
        lazy[2*si + 1] += lazy[si];
    }
    lazy[si] = 0;
}

void update(ll si , ll ss , ll se , ll qs, ll qe, ll val) {
    if(lazy[si] != 0){
        propagate(si, ss, se);
    }

    if(qe < ss || qs > se) return;

    if(ss >= qs && se <= qe){
        lazy[si] = val;
        propagate(si, ss, se);
        return;
    }

    ll mid = (ss + se) / 2;
    
    update(2*si, ss, mid, qs, qe, val);
    update(2*si + 1, mid + 1, se, qs, qe, val);

    st[si] = st[2*si] + st[2*si + 1];
}

ll query(ll si , ll ss , ll se , ll qs , ll qe) {
    if(lazy[si] != 0){
        propagate(si, ss, se);
    }

    if(qe < ss || qs > se) return 0;
 
    if(ss >= qs && se <= qe) return st[si];
 
    ll mid = (ss + se)/2;
    ll l = query(2*si , ss , mid , qs , qe);
    ll r = query(2*si+1 , mid+1 , se , qs , qe);
    
    return l + r;
}
