// https://codeforces.com/contest/1459/problem/C

/*
You are given two positive integer sequences 𝑎1,…,𝑎𝑛 and 𝑏1,…,𝑏𝑚.
For each 𝑗=1,…,𝑚 find the greatest common divisor of 𝑎1+𝑏𝑗,…,𝑎𝑛+𝑏𝑗.

Problem Summary
----------------
If G is the GCD of n numbers, and if each number is then increased by some positive constant, 
what is the fastest way of calculating GCD of the numbers after the increment?
Solve this for m queries.
*/

/*
https://www.quora.com/If-G-is-the-GCD-of-n-numbers-and-if-each-number-is-then-increased-by-some-positive-constant-what-is-the-fastest-way-of-calculating-GCD-of-the-numbers-after-the-increment

Intuition 1
-----------
* Lets say you have n numbers A1,A2……,An.
* From the associative property-: GCD(a,b,c) = GCD(GCD(a,b),c)
* From the elementary property-: GCD(a,b) = GCD(a,b-a)
* Now K is added to every number A1+K,A2+K,…….,An+K
* We want to calculate GCD(A1+K,A2+K,……..,An+K)
* From elementary property we can write GCD(a,b,c,d…..) = GCD(a,b-a,c-a,d-a…….) if a < b,c,d…..
  The way this helps us is that the variable K can be removed from the (n-1) terms in required expression.
* So GCD(A1+K,A2+K,……..,An+K) = GCD(A1+K,A2-A1,A3-A1,……,An-A1) using elementary property.
* Now by using associative property:
  GCD(A1+K,A2-A1,A3-A1,……,An-A1) = GCD(A1+K,GCD(A2-A1,A3-A1,……..,An-A1)) where latter term can be pre-calculated as it is independent of K.

Intuition 2
-----------
If you're ready to do some precomputation, then you can reduce it to a constant time update. There are two important (though very basic) identities that we need to know before we discuss the solution. 

* gcd(a, b) = gcd(a, b−a) 
* gcd(a, b, c) = gcd(a, gcd(b, c)) = gcd(gcd(a, b), c) 
Based on these two, the following identity follows immediately:
* gcd(a1, a2, a3, ..., an) = gcd(a1, gcd(a2−a1, a3−a2, a4-a3, ..., an−an−1)) 

Now note that when you increment all numbers by a constant, their differences don't change at all 
and so the quantity gcd(a2−a1, a3−a2, a4-a3, ..., an−an−1)  doesnt' change either. 
And so we can see that the gcd of all the numbers changes just because a1 changes to a1+K.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    sort(a, a + n);
 
    int gcdd = 0;
    for(int i = 1; i < n; i++) {
        gcdd = __gcd(gcdd, a[i] - a[i-1]);
        // or we can do like this
        // gcdd = __gcd(gcdd, a[i] - a[0]);
    }
 
    for (int i = 0; i < m; ++i) {
        cout << __gcd(a[0] + b[i], gcdd) << " ";
    }
}

int32_t main() {
    solve();
    return 0;
}

