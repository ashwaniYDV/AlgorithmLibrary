// https://codeforces.com/contest/1549/problem/D


/*
British mathematician John Littlewood once said about Indian mathematician Srinivasa Ramanujan that "every positive integer was one of his personal friends."
It turns out that positive integers can also be friends with each other! You are given an array a of distinct positive integers.
Define a subarray ai,ai+1,…,aj to be a friend group if and only if there exists an integer m ≥ 2 such that 
ai % m = ai+1 % m = … = aj % m, where x % y denotes the remainder when x is divided by y.
Print the size of the largest friend group in a.
*/

/*
The key observation is to construct the difference array D of size N−1, where D[i] = abs(A[i+1]−A[i]). 
If a given subarray is a friend group, then every difference is a multiple of some m. 
Since every element of A is distinct, the case when D[i] = 0 can be ignored.

We can now convert this into a GCD (greatest common divisor) problem. 
It follows that A[i…j] is a friend group if and only if gcd(D[i…j−1]) > 1. 
Indeed, the value m that we want is equal to this GCD.

To solve the problem, we can use a segment tree to find the largest possible subarray beginning at i, 
and then max over all subarray answers using sliding window or 2 pointers to get the final answer.
*/

int n, m;
vector<int> tree, dif;

void build(int si, int sl, int sr) {
    if(sl == sr) {
        tree[si] = dif[sl];
        return;
    }
    int mid = (sl + sr) / 2;
    build(si * 2 + 1, sl, mid);
    build(si * 2 + 2, mid + 1, sr);
    tree[si] = __gcd(tree[si * 2 + 1], tree[si * 2 + 2]);
}

int query(int si, int sl, int sr, int ql, int qr) {
    if(ql > sr || qr < sl || sl > sr) return 0;
    
    if(ql <= sl && sr <= qr) return tree[si];

    int mid = (sl + sr) / 2;
    int lt = query(si * 2 + 1, sl, mid, ql, qr);
    int rt = query(si * 2 + 2, mid + 1, sr, ql, qr);
    return __gcd(lt, rt);
}

void solve() {
    cin >> n;
    vector<int> a(n);
    dif = vector<int>(n);
    tree = vector<int> (4*n);

    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 1; i < n; i++) {
        dif[i] = abs(a[i] - a[i-1]);
    }

    int res = 1;
    build(0, 0, n - 1);

    int l = 1, r = 1;
    while(r < n) {
        int gcd = query(0, 0, n-1, l, r);
        if(gcd != 1) {
            res = max(res, (r - l + 1) + 1);
            r++;
        } else {
            l++;
        }
    }

    cout << res << endl;
}
 
signed main() {
    IOS
    clock_t begin = clock();
    int t = 1;
    PRECISION(10);
    cin >> t;
    f(i, t) {
        solve();
    }
    cerr<<"Time elapsed: "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
}
