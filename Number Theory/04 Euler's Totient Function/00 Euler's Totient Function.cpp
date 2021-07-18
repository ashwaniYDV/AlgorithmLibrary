
/*
Que: Find number of co-primes of n from 1...n
(Coprime of n is x if gcd(n, x) = 1)
Euler's Totient Function (Phi Function) in O(sqrt(N))
Φ(n) = n * [1 - (1/p1)] * [1 - (1/p2)] * [1 - (1/p3)] * ...
Φ(n) = n * [(p1 - 1)/p1] * [(p2 - 1)/p2] * [(p3 - 1)/p3] * ...
where n = p1^x1 * p2^x2 * p3^x3 * ...
NOTE:
O(sqrt(N)) -> Problems involving single query
O(Nlog(logN)) -> Problems involving multiple query where each queriy can be answered in O(1) after precalculation
*/




// Euler Phi Function in O(sqrt(N))
ll phi(ll n) {
    ll res = n;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            res *= (i - 1);
            res /= i;

            while(n % i == 0) {
                n /= i;
            }
        }
    }
    if(n > 1) {
        res *= (n - 1);
        res /= n;
    }
    return res;
}









// https://cp-algorithms.com/algebra/phi-function.html
// Euler Phi Function
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
