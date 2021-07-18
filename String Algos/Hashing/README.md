### Rabin Karp
```cpp
class Solution {
public:
    #define ll long long
    ll base = 256, mod = 1e9L + 9;

    ll binpow(ll a, ll b, ll m) {
        a %= m;
        ll res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    }

    bool check(int startPos, string& str, string& pat) {
        /* Check for characters one by one */
        for (int j = 0; j < pat.size(); j++) { 
            if (str[startPos + j] != pat[j]) return false; 
        }
        return true; 
    }
    
    void findPattern(string str, string pat) {
        int n = str.size(), m = pat.size(); 
        ll hashStr = 0, hashPat = 0; 

        // base_pow = base^(m-1) % mod 
        ll base_pow = binpow(base, m - 1, mod);

        // Calculate the hash value of pattern and string on first window of text 
        for (int i = 0; i < m; i++) { 
            hashPat = (hashPat * base + pat[i]) % mod; 
            hashStr = (hashStr * base + str[i]) % mod; 
        } 

        if ( hashPat == hashStr ) { 
            if (check(0, str, pat)) cout << 0 << " ";
        } 

        for (int i = m; i < n; i++) { 
            // Calculate hash value for next window of text: 
            // Remove leading digit, add trailing digit 
            hashStr = ((hashStr - (str[i - m] * base_pow)) * base + str[i]) % mod; 

            if (hashStr < 0) hashStr += mod;

            int startPos = i - m + 1;
            if (check(startPos, str, pat)) 
                cout << startPos << " ";
        } 
    }
};
```

### Hashing

```cpp
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
```
