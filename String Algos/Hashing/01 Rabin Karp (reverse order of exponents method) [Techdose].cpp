// https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
// https://youtu.be/BQ9E-2umSWc


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
