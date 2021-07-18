### Resources
* https://cp-algorithms.com/
* https://www.youtube.com/watch?v=dg1CUYrLrD0&list=PL5DyztRVgtRWblnyEHtajWijQffrfwLz6 
* https://www.youtube.com/watch?v=1xNbjMdbjug&list=PLgUwDviBIf0oFON1SRGcMqMIhiZ4EXx_F

### What to study
* Basic Euclidean algorithm
* Extended Euclidean algorithm

### Some facts about GCD
1) gcd(a1, a2, ..., an−1, an) is equal to gcd(a1, a2 − a1, a3 - a2, a4 - a3, ..., an−1 − an−2, an − an−1)
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

2) gcd(a1, a2, ..., an−1, an) is equal to gcd(a1, a2 − a1, a3 - a1, a4 - a1, ..., an−1 − a1, an − a1)

3) gcd(n, n+1) = 1  [Always try to utilize this property when que is like given an array and you can take any pair of numbers to make gcd 1 and so on]
   

### Other

1) Only perfect Squares have an odd number of factors.\
   For example, 9 has odd number of factors, 1, 3 and 9. 16 also has odd number of factors, 1, 2, 4, 8, 16. The reason for this is, for numbers other than perfect    squares, all factors are in the form of pairs, but for perfect squares, one factor is single and makes the total as odd.
2) Goldbach’s conjecture: Every even integer greater than 2 can be expressed as the sum of two primes.
3) Let F(N) = Total number of positive integers <= N which are divisible by a or b or c \
   F(N) = N/a + N/b + N/c - N/lcm(a, b) - N/lcm(b, c) - N/lcm(c, a) + N/lcm(a, b, c)


## Check divisibility of extra long numbers
   ```
   void solve() {
    string number;
    int divisor;
    cin >> number;
    cin >> divisor;
    n = number.size();

    vector<int> remainder(n);
    
    remainder[0] = (number[0] - '0') % divisor;
    for(int i = 1; i < n; i++) {
        remainder[i] = (remainder[i - 1] * 10 + (number[i] - '0')) % divisor;
    }

    if(remainder[n - 1] == 0) {
        cout << number << " is divisible by " << divisor << endl;
    } else {
        cout << number << " is NOT divisible by " << divisor << endl;
    }
} 
   ```
   