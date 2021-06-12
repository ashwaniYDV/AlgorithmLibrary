// https://www.spoj.com/problems/NHAY/


struct Hash_Str {
    /**********************************/
    int add(int a, int b, int mod) {
        int res = (a + b) % mod;
        if (res < 0) res += mod;
        return res;
    }
    int mult(int a, int b, int mod) {
        int res = (a * 1LL * b) % mod;
        if (res < 0) res += mod;
        return res;
    }
    int power(int a, int b, int mod) {
        a %= mod;
        int res = 1;
        while (b) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    /**********************************/

    int mod = 1e9 + 9, base = 31, n;
    vector<int> pw, inv, hash_str;
    
    void init(string s) {
        n = s.size();
        pw.resize(n+2), inv.resize(n+1), hash_str.resize(n+2);

        pw[0] = 1;
        for(int i = 1; i < n; i++) {
            pw[i] = mult(pw[i - 1], base, mod);
        }

        int pw_inv = power(base, mod - 2, mod);
        inv[0] = 1;
        for(int i = 1; i < n; i++) {
            inv[i] = mult(inv[i - 1], pw_inv, mod);
        }

        // build hash
        for(int i = 0; i < n; i++) {
            hash_str[i] = add((i == 0) ? 0 : hash_str[i - 1], mult(pw[i], s[i] - 'a' + 1, mod), mod);
        }
    }

    int getSubstringHash(int x, int y) {
        int res = add(hash_str[y], (x == 0) ? 0 : -hash_str[x - 1], mod);
        res = mult(res, inv[x], mod);
        return res;
    }
};

int getStringHash(string const& s) {
    int n = s.size();
    const int p = 31;
    const int mod = 1e9 + 9;

    vector<int> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % mod;

    vector<int> h(n + 1, 0);
    for (int i = 0; i < n; i++) {
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod;
    }

    return h[n];
}

void solve() {
    int x, y, z;
    string needle, haystack;
    cin >> needle;
    cin >> haystack;

    n = haystack.size(), m = needle.size();

    Hash_Str obj;
    obj.init(haystack);

    y = getStringHash(needle);
    for (int i = 0; i <= n - m; i++) {
        x = obj.getSubstringHash(i, i+m-1);
        if(x == y) {
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
