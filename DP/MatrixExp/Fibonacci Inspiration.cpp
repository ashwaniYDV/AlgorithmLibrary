// https://www.codechef.com/LRNDSA10/problems/IEMCO8F


const ll K = 5;

matrix mul(matrix A, matrix B) {
    matrix C(K+1, vector<ll>(K+1));
    loop(i,1, K)
    	loop(j,1, K)
    		loop(k,1, K)
        		C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

matrix pow(matrix A, ll p) {
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

// returns the N-th term of Fibonacci sequence
ll fib(ll N, ll a, ll b, ll c, ll d, ll e) {
    // create vector F1
    vector<ll> F1(K+1);
    F1[1] = 3;
    F1[2] = 2;
    F1[3] = 1;
    F1[4] = 0;
    F1[5] = e;

    // create matrix T
    matrix T(K+1, vector<ll>(K+1));
    T[1][1] = a, T[1][2] = b, T[1][3] = c, T[1][4] = d, T[1][5] = 1;
    T[2][1] = 1, T[2][2] = 0, T[2][3] = 0, T[2][4] = 0, T[2][5] = 0;
    T[3][1] = 0, T[3][2] = 1, T[3][3] = 0, T[3][4] = 0, T[3][5] = 0;
    T[4][1] = 0, T[4][2] = 0, T[4][3] = 1, T[4][4] = 0, T[4][5] = 0;
    T[5][1] = 0, T[5][2] = 0, T[5][3] = 0, T[5][4] = 0, T[5][5] = 1;

    // raise T to the (N-1)th power
    if (N <= 4)
        return N - 1;

    T = pow(T, N-4);

    // the answer is the first row of T . F1
    ll res = 0;
    loop(i,1, K)
        res = (res + T[1][i] * F1[i]) % MOD;

    // res += e;
    return res % MOD;
}

void solve() {
	ll k, x, y, u, v, p, q;
	ll a, b, c, d, e;
    cin >> a >> b >> c >> d >> e >> n;
    a %= MOD;
    b %= MOD;
    c %= MOD;
    d %= MOD;
    e %= MOD;
    cout << fib(n, a, b, c, d, e) << endl;
}
 
int32_t main() {
	IOS
	ll T;
	cin >> T;
	while(T--)
	solve();
	cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n'; 
	return 0;
}
