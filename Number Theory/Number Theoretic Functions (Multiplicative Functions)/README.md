In general Multiplicative functions (Number Theoretic Functions) is defined in such a way: \
Let f(x) be a multiplicative function and m & n are co-prime, then

f(m * n) = f(m) * f(n)

Note: \
Euler's Totient Function is multiplicative \
Φ(m * n) = Φ(m) * Φ(n), where m & n are co-prime

Some properties of multiplicative functions:

1) f(1) = 1
   Proof: f(m * n) = f(m) * f(n) \
   Put n = 1 \
   f(m) = f(m) * f(1) \
   f(m) * (1 - f(1)) = 0 \
   But f(m) is not zero; therefore f(1) = 1 \
  
2) h(n) = f(n) * g(n),  where f(n) and g(n) are multiplicative functions, \
   then h(n) is also multiplicative function \
   
   Proof: \
   To proove => h(a * b) = h(a) * h(b) \
   h(a * b) = f(a * b) * g(a * b) \
            = f(a) * f(b) * g(a) * g(b) \
            = [f(a) * g(a)] * [f(b) * g(b)] \
            = h(a) * h(b)
