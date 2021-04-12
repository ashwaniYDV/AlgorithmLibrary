## Some facts about GCD

1) If G is the GCD of n numbers, and if each number is then increased by some positive constant, what is the fastest way of calculating GCD of the numbers after the increment?
   [Quora link](https://www.quora.com/If-G-is-the-GCD-of-n-numbers-and-if-each-number-is-then-increased-by-some-positive-constant-what-is-the-fastest-way-of-calculating-GCD-of-the-numbers-after-the-increment)
   
   Question: https://codeforces.com/contest/1459/problem/C
   
   ```
    gcd(a,b)=gcd(a,b−a) 

    gcd(a,b,c)=gcd(a,gcd(b,c))   =gcd(gcd(a,b),c) 

    Based on these two, the following identity follows immediately:
    gcd(a1,a2,a3...an)=   gcd(a1,gcd(a2−a1,a3−a2...an−an−1)) 

    Now note that when you increment all numbers by a constant, their differences don't change at all and so the quantity  gcd(a2−a1,a3−a2...an−an−1)  doesnt' change either. And so we can see that the gcd of all the numbers changes just because  a1  changes.
    ```
    ```
    Lets say you have n numbers A1,A2……,An.
    
    From the associative property -: GCD(a,b,c) = GCD(GCD(a,b),c)

    From the elementary property -: GCD(a,b) = GCD(a,b-a)

    Now K is added to every number A1+K,A2+K,…….,An+K

    We want to calculate GCD(A1+K,A2+K,……..,An+K)

    From elementary property we can write GCD(a,b,c,d…..) = GCD(a,b-a,c-a,d-a…….) if a < b,c,d…..The way this helps us is that the variable K can be removed from the (n-1) terms in required expression.

    So GCD(A1+K,A2+K,……..,An+K) = GCD(A1+K,A2-A1,A3-A1,……,An-A1). using elementary property.

    Now by using associative property

    GCD(A1+K,A2-A1,A3-A1,……,An-A1) = GCD(A1+K,GCD(A2-A1,A3-A1,……..,An-A1)) where latter term can be pre-calculated as it is independent of K.
    ```
    
2) gcd(a1, a2, ..., an−1, an) is equal to gcd(a1, a2 − a1, a3 - a2, a4 - a3, ..., an−1 − an−2, an − an−1)
   ```
   gcd(a, b) = gcd(a, b − a)
   gcd(a, b, c) = gcd(a, gcd(b, c)) = gcd(gcd(a, b), c)
   Then we can extend our claim to multiple arguments by mathematical induction.

   gcd(a1, a2, ..., an−2, an−1, an) = gcd(a1, a2, ..., an−2, gcd(an−1, an))
   = gcd(a1, a2, ..., an−2, gcd(an−1, an − an−1))
   = gcd(a1, a2, ..., an−2, an−1, an − an−1)
   = gcd(a1, a2, ..., gcd(an−2, an−1), an − an−1)
   = gcd(a1, a2, ...,gcd(an−2, an−1 − an−2),an − an−1)
   = gcd(a1, a2, ...,an−2, an−1 − an−2, an − an−1)
   = gcd(a1, a2−a1, ...,an−1 − an−2,an − an−1)
   Therefore gcd(a1, a2, ..., an−1, an) == gcd(a1, a2 − a1, a3 - a2, a4 - a3, ..., an−1 − an−2, an − an−1)
   ```
   In general:
   ```
   gcd(a1 + k, a2 + k, ..., an−1 + k, an + k) == gcd(a1 + k, a2 − a1, a3 - a2, a4 - a3, ..., an−1 − an−2, an − an−1)

   gcd(a1 + bj, a2 + bj, ..., an−1 + bj, an + bj) == gcd(a1 + bj, a2 − a1, ...,an−1 − an−2, an − an−1).
   ```
   
## Other

1) Only perfect Squares have an odd number of factors.\
   For example, 9 has odd number of factors, 1, 3 and 9. 16 also has odd number of factors, 1, 2, 4, 8, 16. The reason for this is, for numbers other than perfect    squares, all factors are in the form of pairs, but for perfect squares, one factor is single and makes the total as odd.

2) **Number-theoretic functions:** \
   [Euler's totient function](https://cp-algorithms.com/algebra/phi-function.html) \
   [Number of divisors / sum of divisors](https://cp-algorithms.com/algebra/divisors.html) \
   Both d(n) and σ(n) are multiplicative functions.
   
3) **Number of divisors: d (N)** \
   If the prime factorization of n = p1^e1⋅p2^e2...pk^ek, (where pi are distinct prime numbers), \
   then the number of divisors is: \
   d(n) = (e1+1)⋅(e2+1)...(ek+1)
4) **Sum of divisors: σ(n)** \
   n = p1^e1⋅p2^e2...pk^ek \
   σ(n) = (1+p1+p1^2+P1^3+...+p1^e1)⋅(1+p2+p2^2+P2^3+...+p2^e2)...(1+pk+pk^2+Pk^3+...+pk^ek) \
   σ(n) = [(p1^(e1+1) - 1) / (p1 - 1)]⋅[(p2(e2+1) - 1) / (p2 - 1)]...[(pk^(ek+1) - 1) / (pk - 1)] \
   Problems: \
   (a) https://codeforces.com/contest/1512/problem/G
