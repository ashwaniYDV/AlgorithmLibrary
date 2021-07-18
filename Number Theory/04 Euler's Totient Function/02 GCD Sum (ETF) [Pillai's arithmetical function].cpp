/*
Pillai's arithmetical function
*/

/*
GCD Sum using Euler Totient Function
Que: Given q queries with integer n,
gcd(1, n) + gcd(2, n) + gcd(3, n) + ... + gcd(n, n) = ______ 
// https://youtu.be/khCze6j1vXg
NOTE:
preprocessing init_phi time = O(Nlog(logN))
Overal for q queries, time = O(Nlog(log(N)) + Q.sqrt(N))
*/

/*
Naive Approach: (Time Complexity: O(N * log N))
A simple solution is to iterate over all numbers from 1 to N and find their gcd with N itself and keep on adding them.

Efficient Approach: 
To optimize the above-mentioned approach, we need to observe that GCD(i, N) gives one of the divisors of N. 
So if divisors of N are = d1, d2, ..., dm
Then GCD(i, N) = belongs to one of {d1, d2, ..., dm}
So, instead of running a loop from 1 to N, we can check for each divisor of N that how many numbers are there with GCD(i, N) same as that divisor.

So we have to find the number of integers from 1 to N with GCD d, where d is a divisor of N. 
Let us consider x1, x2, x3,..., xn as the different integers from 1 to N such that their GCD with N is d.
Since, GCD(xi, N) = d, then GCD(xi/d, N/d) = 1
So, count of integers from 1 to N whose GCD with N is d is Euler Totient Function of (N/d).

Illustration: 
For example N = 12, its divisors are 1, 2, 3, 4, 6, 12. 
Numbers in range [1, 12] whose GCD with 12 is:

1 are {1, 5, 7, 11}
2 are {2, 10}
3 are {3, 9}
4 are {4, 8}
6 is {6}
12 is {12}
So answer is; 1*4 + 2*2 + 3*2 + 4*2 + 6*1 + 12*1 = 40.
*/



// Method 1: CodeNCode
ll n, m;
ll phi[N + 1];

// Euler Phi Function in O(Nlog(logN)) [preprocessing time (similar to sieve)]
void init_phi() {
    for(ll i = 1; i <= N; i++) {
        phi[i] = i;
    }

    for(ll i = 2; i <= N; i++) {
        if(phi[i] == i) {
            for(ll j = i; j <= N; j += i) {
            phi[j] *= (i - 1);
            phi[j] /= i;
           } 
        }
    }
}

ll getCount(ll d, ll n) {
    return phi[n / d];
}

void solve() {
    ll t;
    init_phi();
    cin >> t;
    while(t--){
        cin >> n;
        ll res = 0;
        // all divisors of n
        for(ll i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                ll d1 = i;
                ll d2 = n / i;

                res += d1 * getCount(d1, n);

                if(d1 != d2) 
                    res += d2 * getCount(d2, n);
            }
        }
        cout << res << endl;
    }
} 





























// Method 2: (GFG) (Phi is not precomputed initially)
// C++ Program to find the Sum of GCD of all integers up to N with N itself

int getCount(int d, int n) {
    int no = n / d;

    int result = no;

    for (int i = 2; i * i <= no; i++) {
        if (no % i == 0) {
            while (no % i == 0) {
                no /= i;
            }
            result -= result / i;
        }
    }

    if (no > 1) {
        result -= result / no;
    }

    return result;
}

// Finding GCD of pairs
int sumOfGCDofPairs(int n) {
    int res = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            // Calculate the divisors
            int d1 = i;
            int d2 = n / i;

            // Return count of numbers from 1 to N with GCD d with N
            res += d1 * getCount(d1, n);

            // Check if d1 and d2 are equal then skip this
            if (d1 != d2) res += d2 * getCount(d2, n);
        }
    }

    return res;
}

void solve() {
    int n = 100;
    cout << sumOfGCDofPairs(n);
} 













// Method 3: (Method 2 another version)
int getPhiOfNbyD(int d, int n) {
    int no = n / d;

    int res = no;
    for(int i = 2; i * i <= no; i++) {
        if(no % i == 0) {
            res *= (i - 1);
            res /= i;

            while(no % i == 0) {
                no /= i;
            }
        }
    }
    if(no > 1) {
        res *= (no - 1);
        res /= no;
    }
    return res;
}

// Finding GCD of pairs
int sumOfGCDofPairs(int n) {
    int res = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            // Calculate the divisors
            int d1 = i;
            int d2 = n / i;

            // Return count of numbers from 1 to N with GCD d with N
            res += d1 * getPhiOfNbyD(d1, n);

            // Check if d1 and d2 are equal then skip this
            if (d1 != d2) res += d2 * getPhiOfNbyD(d2, n);
        }
    }

    return res;
}


void solve() {
    int n = 100;
    cout << sumOfGCDofPairs(n);
}
