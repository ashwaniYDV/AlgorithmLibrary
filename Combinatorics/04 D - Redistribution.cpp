// https://atcoder.jp/contests/abc178/tasks/abc178_d

/*
Given is an integer S. Find how many sequences there are whose terms are all integers greater than or equal to 3, and whose sum is equal to S. 
The answer can be very large, so output it modulo 10^9+7.

Constraints
1 ≤ S ≤ 2000
All values in input are integers.

Example:
Iput: 7
Output: 3
3 sequences satisfy the condition: {3, 4} , {4, 3} and {7}
*/
 
/************************************************************************************/
int binpow(int n, int p) {
    int res = 1;
    while (p > 0) {
        if (p & 1) res = res * n;
        n = n * n;
        p >>= 1;
    }
    return res;
}
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
 
/*
Rotate Left by rotL
rotate(v.begin(), v.begin()+rotL, v.end());
Rotate Right by rotR
rotate(v.begin(), v.begin()+ n-rotR, v.end());
*/
/************************************************************************************/


void solve() {
    int x, y, z;
    int s;
    cin >> s;

    initFactorials();

    int res = 0;
    for(int r = 1; r <= s; r++) {
        n = s - r*3;
        if(n < 0) break;
        
        res += nCrMod(n+r-1, r-1);
        res = (res + MOD) % MOD;
    }
    cout << (res+MOD) % MOD << endl;
    
}
