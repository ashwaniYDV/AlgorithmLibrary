// https://www.spoj.com/problems/NHAY/
// A Needle in the Haystack [SPOJ]

/*
Write a program that finds all occurences of a given pattern in a given input string. 
This is often referred to as finding a needle in a haystack.
*/


struct Hash_Str {
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
    vector<ll> pw, inv, hash_str;

    void init(string s) {
        n = s.size();
        pw.resize(n+2), inv.resize(n+1), hash_str.resize(n+2);

        pw[0] = 1;
        for(ll i = 1; i < n; i++) {
            pw[i] = mult(pw[i - 1], base, mod);
        }

        ll pw_inv = power(base, mod - 2, mod);
        inv[0] = 1;
        for(ll i = 1; i < n; i++) {
            inv[i] = mult(inv[i - 1], pw_inv, mod);
        }

        // build hash
        for(ll i = 0; i < n; i++) {
            hash_str[i] = add((i == 0) ? 0 : hash_str[i - 1], mult(pw[i], s[i] - 'a' + 1, mod), mod);
        }
    }

    ll getSubstringHash(ll x, ll y) {
        ll res = add(hash_str[y], (x == 0) ? 0 : -hash_str[x - 1], mod);
        res = mult(res, inv[x], mod);
        return res;
    }
};

void solve() {
    int x, y, z;
    string needle, haystack;
    cin >> needle;
    cin >> haystack;

    n = haystack.size(), m = needle.size();

    Hash_Str obj;

    obj.init(needle);
    int needleHash = obj.getSubstringHash(0, m - 1);

    obj.init(haystack);
    
    for (int i = 0; i <= n - m; i++) {
        x = obj.getSubstringHash(i, i+m-1);
        if(x == needleHash) {
            cout << i << endl;
        }
    }
    cout << endl;
}

signed main() {
    IOS
    int t = 1;
    // cin >> t;
    while(cin >> n) {
        solve();
    }
}
