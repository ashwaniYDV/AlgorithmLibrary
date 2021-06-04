// https://codeforces.com/problemset/problem/1288/C

/*
Problem:
You are given two integers n and m. Calculate the number of pairs of arrays (a, b) such that all the 5 conditions are satisfied:
1) the length of both arrays is equal to m
2) each element of each array is an integer between 1 and n (inclusive)
3) ai ≤ bi for any index i from 1 to m
4) array a is sorted in non-descending order
5) array b is sorted in non-ascending order

As the result can be very large, you should print it modulo 10^9+7.




Solution: (Using previous question concept)

Let's consider the following sequence:

a1, a2, ..., am, bm, bm-1, bm-2 ..., b1

Since a1 <= am and am <= bm and bm <= b1

It's sequence of length 2m sorted in non-descending order, where each element of each sequence is an integer between 1 and n.

So the question just boils down to create all such array where size = 2m and range of numbers is from 1 to n (Using previous question concept).

We can find the number of such sequences by simple combinatorics — it's combination with repetitions.
So the answer is (2m+n-1)C(n-1)
*/

const int MAXN = 2e3+5;
int n, m;

/************************************************************************************/
int power(int n, int p) {
    int res = 1;
    n %= MOD;
    while (p > 0) {
        if (p & 1) res = (res * n) % MOD;
        n = (n * n) % MOD;
        p >>= 1;
    }
    return res;
}
int modInverse(int n, int p) { 
    return power(n, p - 2);
} 
 
int fact[MAXN], inv[MAXN], invfact[MAXN];
void initFactorials() {
    fact[0] = 1;
      for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i * 1LL) % MOD;
    }
 
    //calculate inverses of [1,N] mod p
    inv[1]=1;
    for(int i=2;i<MAXN;i++)inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
 
    invfact[0]=1;
    for(int i=1;i<MAXN;i++)invfact[i]=(invfact[i-1]*inv[i])%MOD;
}
 
int nCrMod(int n, int r) {
    if (n < r) return 0;
    if (r == 0) return 1;
    int num = fact[n], den = (fact[r] * fact[n-r]) % MOD;
    int inv = modInverse(den, MOD);
    return (num * inv) % MOD;
}
/************************************************************************************/

void solve() {
    cin >> n >> m;
    initFactorials();
    cout << nCrMod(2*m + n-1, n-1) << endl;
}
