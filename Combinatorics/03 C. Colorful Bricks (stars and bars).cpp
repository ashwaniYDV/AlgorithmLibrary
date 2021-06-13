// https://codeforces.com/problemset/problem/1081/C

/*
There are n bricks lined in a row on the ground. Chouti has got m paint buckets of different colors at hand, so he painted each brick in one of those m colors.
Having finished painting all bricks, Chouti was satisfied. 
He stood back and decided to find something fun with these bricks. 
After some counting, he found there are k bricks with a color different from the color of the brick on its left (the first brick is not counted, for sure).

So as usual, he needs your help in counting how many ways could he paint the bricks. 
Two ways of painting bricks are different if there is at least one brick painted in different colors in these two ways. 
Because the answer might be quite big, you only need to output the number of ways modulo 998244353.
*/


/*
Solution:
We need k+1 partitions of n number of bricks.
Let x1 + x2 + .... x(k+1) = n


    | x1 bricks | x2 bricks | ... | ... | x(k) bricks | x(k+1) bricks | 

So the 1st set of x1 bricks can be colored in any of (m) colors, 2d set of x2 bricks in any of (m-1) colors, 3rd set x3 of bricks in any of (m-1) colors...
and the (k+1)th set of bricks in any of (m-1) colors.


noOfCombinations = nCrMod(n-1, k-1);
noOfColorCombinations = m * (m-1) * (m-1) * ... * (m-1);



Let x1 + x2 + .... x(k+1) = n

Then x1 bricks are colored in any of m colors, x2 brocks are colored in any of remaining (m-1) colors which is not used in coloring x1 bricks.
x2 brocks are colored in any of remaining (m-1) colors which is not used in coloring x2 bricks...
ans so on.
*/


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
    int x, y, z, k;
    cin >> n >> m >> k;
    initFactorials();
    
    k++;

    int noOfCombinations = nCrMod(n-1, k-1);
    int noOfColorCombinations = m;
    loop(i, 1, k-1) {
        noOfColorCombinations = (noOfColorCombinations * (m - 1)) % MOD;
    }
    int res = (noOfCombinations * noOfColorCombinations) % MOD;
    cout << res << endl;
}
