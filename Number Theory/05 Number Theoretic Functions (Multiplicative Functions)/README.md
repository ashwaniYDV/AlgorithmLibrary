In general Multiplicative functions (Number Theoretic Functions) is defined in such a way: \
Let f(x) be a multiplicative function and m & n are co-prime, then

f(m * n) = f(m) * f(n)

Note: \
Euler's Totient Function is multiplicative \
Φ(m * n) = Φ(m) * Φ(n), where m & n are co-prime

Some properties of multiplicative functions:

1) f(1) = 1 
   
   Proof: \
   f(m * n) = f(m) * f(n) \
   Put n = 1 \
   f(m) = f(m) * f(1) \
   f(m) * (1 - f(1)) = 0 \
   But f(m) is not zero; therefore f(1) = 1
  
2) h(n) = f(n) * g(n),  where f(n) and g(n) are multiplicative functions, \
   then h(n) is also multiplicative function
   
   Proof: \
   To proove => h(a * b) = h(a) * h(b) \
   h(a * b) = f(a * b) * g(a * b) \
            = f(a) * f(b) * g(a) * g(b) \
            = [f(a) * g(a)] * [f(b) * g(b)] \
            = h(a) * h(b)


### Number-theoretic functions (multiplicative functions)

1) **Number-theoretic functions:** \
   [Euler's totient function](https://cp-algorithms.com/algebra/phi-function.html) \
   [Number of divisors / sum of divisors](https://cp-algorithms.com/algebra/divisors.html) \
   A multiplicative function is a function f(x) which satisfies => f(a⋅b)=f(a)⋅f(b)
   Both d(n) and σ(n) are multiplicative functions.
   
2) **Number of divisors: d (N)** \
   If the prime factorization of n = p1^e1⋅p2^e2...pk^ek, (where pi are distinct prime numbers), \
   then the number of divisors is: \
   d(n) = (e1+1)⋅(e2+1)...(ek+1)

3) **Sum of divisors: σ(n)** \
   n = p1^e1⋅p2^e2...pk^ek \
   σ(n) = [1+p1+p1^2+P1^3+...+p1^e1]⋅[1+p2+p2^2+P2^3+...+p2^e2]...[1+pk+pk^2+Pk^3+...+pk^ek] \
   σ(n) = [(p1^(e1+1) - 1) / (p1 - 1)]⋅[(p2(e2+1) - 1) / (p2 - 1)]...[(pk^(ek+1) - 1) / (pk - 1)] \
   Problems: \
   (a) https://codeforces.com/contest/1512/problem/G \
   (b) https://www.spoj.com/problems/COMDIV/ \
   (c) https://www.spoj.com/problems/DIVSUM/