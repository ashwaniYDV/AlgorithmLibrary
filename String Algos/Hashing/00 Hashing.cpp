// Method 1: Serial Order

struct Hashing {
    #define ll long long
    /**********************************/
    ll add(ll a, ll b, ll mod) {
        ll res = (a + b) % mod;
        if (res < 0) res += mod;
        return res;
    }
    ll mult(ll a, ll b, ll mod) {
        ll res = (a * 1LL * b) % mod;
        if (res < 0) res += mod;
        return res;
    }
    ll power(ll a, ll b, ll mod) {
        a %= mod;
        ll res = 1;
        while (b) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    /**********************************/

    ll mod = 1e9 + 9, base = 31, n;
    vector<ll> p, p_inv, hash;

    void init(string s) {
        n = s.size();
        p = vector<ll>(n);
        p_inv = vector<ll>(n);
        hash = vector<ll>(n);

        p[0] = 1;
        p_inv[0] = 1;
        ll base_inv = power(base, mod - 2, mod);
        for(ll i = 1; i < n; i++) {
            p[i] = mult(p[i - 1], base, mod);
            p_inv[i] = mult(p_inv[i - 1], base_inv, mod);
        }

        // build hash
        for(ll i = 0; i < n; i++) {
            hash[i] = add((i == 0) ? 0 : hash[i - 1], mult(p[i], s[i] - 'a' + 1, mod), mod);
        }
    }

    ll getHash(ll x, ll y) {
        ll res = add(hash[y], (x == 0) ? 0 : -hash[x - 1], mod);
        res = mult(res, p_inv[x], mod);
        return res;
    }
};



// Method 2: Reverse Order

struct Hashing {
    /**********************************/
    ll add(ll a, ll b, ll mod) {
        ll res = (a + b) % mod;
        if (res < 0) res += mod;
        return res;
    }
    ll mult(ll a, ll b, ll mod) {
        ll res = (a * 1LL * b) % mod;
        if (res < 0) res += mod;
        return res;
    }
    ll power(ll a, ll b, ll mod) {
        a %= mod;
        ll res = 1;
        while (b) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    /**********************************/

    ll base = 256, mod = 1e9L + 9, n;
    vector<ll> p, p_inv, hash;

    void init(string s) {
        n = s.size();
        p = vector<ll>(n);
        p_inv = vector<ll>(n);
        hash = vector<ll>(n);

        p[0] = 1;
        p_inv[0] = 1;
        ll base_inv = power(base, mod - 2, mod);
        for(ll i = 1; i <= n-1; i++) {
            p[i] = mult(p[i - 1], base, mod);
            p_inv[i] = mult(p_inv[i - 1], base_inv, mod);
        }

        for(ll i = 0; i < n; i++) {
            hash[i] = add((i == 0) ? 0 : hash[i - 1], mult(p[n - 1 - i], s[i] - 'a' + 1, mod), mod);
        }
    }

    ll getHash(ll l, ll r) {
        ll h = add(hash[r], (l == 0 ? 0 : -hash[l - 1]), mod);
        h = mult(h, p_inv[n - 1 - r], mod);
        return h;
    }
};


// Method 3: Another way

class Solution {
public:
    #define ll long long
    static const int N = 1e4+5;

    /**********************************/
    const ll mod = 1e9 + 9, base = 31;
    int p[N], p_inv[N];

    static ll add(ll a, ll b, ll mod) {
        ll res = (a + b) % mod;
        if (res < 0) res += mod;
        return res;
    }
    static ll mult(ll a, ll b, ll mod) {
        ll res = (a * 1LL * b) % mod;
        if (res < 0) res += mod;
        return res;
    }
    static ll power(ll a, ll b, ll mod) {
        a %= mod;
        ll res = 1;
        while (b) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    void preprocess() {
        p[0] = 1;
        p_inv[0] = 1;
        ll base_inv = power(base, mod - 2, mod);
        for(ll i = 1; i < N; i++) {
            p[i] = mult(p[i - 1], base, mod);
            p_inv[i] = mult(p_inv[i - 1], base_inv, mod);
        }
    }

    int n;
    vector<ll> hash;

    void initHash(string s) {
        n = s.size();
        hash = vector<ll>(n);
        // build hash
        for(ll i = 0; i < n; i++) {
            hash[i] = add((i == 0) ? 0 : hash[i - 1], mult(p[i], s[i] - 'a' + 1, mod), mod);
        }
    }

    ll getHash(ll x, ll y) {
        ll res = add(hash[y], (x == 0) ? 0 : -hash[x - 1], mod);
        res = mult(res, p_inv[x], mod);
        return res;
    }
    /**********************************/
}
