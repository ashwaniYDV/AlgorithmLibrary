// https://www.scaler.com/hire/test/problem/very-large-power/
// watch video solution of scaler

/*
Given two Integers A, B. You have to calculate (A ^ (B!)) % (1e9 + 7).

Problem Constraints
1 <= A, B <= 5e5
*/

/*
Fermats Little Theorem:
-----------------------
a^p ≡ a (mod p)
a^(p-1) ≡ 1 (mod p)


Misconception:
--------------
{A^(B!)} % p = {A^(B! % p)} % p
above equation is not true
modulo only applies to +, -, *, / and not to exponents


Solution:
---------

Let:
A^(B!) = [A^(p-1)] * [A^(p-1)] * ... * [A^(p-1)] * [A^x]
such that B! = (p-1) + (p-1) + ... + (p-1) + x

taking % p
{A^(B!)} % p = {[A^(p-1)] * [A^(p-1)] * ... * [A^(p-1)] * [A^x]} % p
{A^(B!)} % p = {1 * 1 * ... * 1 * [A^x]} % p
{A^(B!)} % p = [A^x] % p

where:
x = (B!) % (p-1)
*/

int fast_power(long long A, long long B, long long mod) {
    long long ans = 1;
    while (B > 0) {
        if (B & 1) {
            ans = (ans * A) % mod;
        }
        A = (A % mod * A % mod) % mod;
        B = B >> 1;
    }
    return ans % mod;
}

int Solution::solve(int A, int B) {

    long long fact = 1;
    long long mod = (1e9 + 7);

    // calculating factorial of B
    for (long long i = 2; i <= B; i += 1) {
        // (mod-1) is used accoring to Fermat Little theorem.
        fact = (fact * i) % (mod - 1);
    }
    int ans = fast_power(A, fact, mod);
    return ans;
}
