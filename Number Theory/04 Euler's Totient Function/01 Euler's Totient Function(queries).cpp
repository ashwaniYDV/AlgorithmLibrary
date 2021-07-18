/*
Que: Given q queries. Find number of co-primes of n from 1...n
(Coprime of n is x if gcd(n, x) = 1)
Euler's Totient Function (Phi Function) in O(Nlog(logN)) time
Φ(n) = n * (p1 - 1)/p1 * (p2 - 1)/p2 * (p3 - 1)/p3 * ...
where n = p1^x1 * p2^x2 * p3^x3 * ...
NOTE:
O(sqrt(N)) -> Problems involving single query
O(Nlog(logN)) -> Problems involving multiple query where each queriy can be answered in O(1) after precalculation
*/


// // https://youtu.be/Fv77-SOTxy8
ll phi[N + 1];

// Euler Phi Function in O(Nlog(logN)) [preprocessing time]
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

void solve() {
    ll t;
    init_phi();
    cin >> t;
    while(t--) {
        cin >> n;
        cout << phi[n] << endl;
    }
} 








// https://cp-algorithms.com/algebra/phi-function.html
void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
