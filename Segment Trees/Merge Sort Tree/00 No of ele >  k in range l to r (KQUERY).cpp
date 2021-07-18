// https://www.spoj.com/problems/KQUERY
// https://youtu.be/R0KRKi_LL6c

/*
Given a sequence of n numbers a1, a2, ..., an and a number of k-queries. A k-query is a triple (i, j, k) (1 ≤ i ≤ j ≤ n). 
For each k-query (i, j, k), you have to return the number of elements greater than k in the subsequence ai, ai+1, ..., aj.
*/


ll arr[N];
vector<ll> st[4 * N];

void merge(vector<ll>& a, vector<ll>& b, vector<ll>& c) {
    int i = 0 , j = 0, n = a.size(), m = b.size();
    while(i < n && j < m) {
        if(a[i] < b[j]) {
            c.push_back(a[i]) , i++;
        } else {
            c.push_back(b[j]) , j++;
        }
    }
 
    while(i < n) c.push_back(a[i]) , i++;
    while(j < m) c.push_back(b[j]) , j++;
}

void build(ll si , ll ss , ll se) {
    if(ss == se) {
        st[si].pb(arr[ss]);
        return;
    }
 
    ll mid = (ss + se)/2;
    build(2*si , ss , mid);
    build(2*si+1 , mid+1 , se);
 
    merge(st[2*si], st[2*si+1], st[si]);
}

ll query(ll si , ll ss , ll se , ll qs , ll qe, ll k) {
    if(qe < ss || qs > se) return 0;
 
    if(ss >= qs && se <= qe) {
        return st[si].end() - upper_bound(st[si].begin(), st[si].end(), k);
    };
 
    ll mid = (ss + se)/2;
    ll l = query(2*si , ss , mid , qs , qe, k);
    ll r = query(2*si+1 , mid+1 , se , qs , qe, k);
    
    return l + r;
}


void solve(){
    ll t, l, r, k;
    cin >> n;
    loop(i, 1, n) cin >> arr[i];
    build(1, 1, n);
    cin >> t;
    while(t--) {
        cin >> l >> r >> k;
        cout << query(1, 1, n, l, r, k) << endl;
    }
}
