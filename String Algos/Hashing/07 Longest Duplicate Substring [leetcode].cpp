// https://leetcode.com/problems/longest-duplicate-substring/

/*
Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. 
The occurrences may overlap.
Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".

Example 1:
Input: s = "banana"
Output: "ana"

Example 2:
Input: s = "abcd"
Output: ""
*/

#define ll long long
class Solution {
public:
    const ll p = 31;
    const ll mod = 1e9 + 9;
    vector<ll> p_pow, h;
    ll n;
    string ans = "";
    
    string check(ll len, string const& s) {
        unordered_map<ll, vector<ll>> mp;
        for (ll i = 0; i <= n - len; i++) {
            ll cur_h = (h[i + len] - h[i] + mod) % mod;
            cur_h = (cur_h * p_pow[n-1-i]) % mod;
            for(ll pos: mp[cur_h]) {
                string temp = s.substr(pos, len);
                string curr = s.substr(i, len);
                if(temp.compare(curr) == 0) {
                    return temp;
                }
            }
            mp[cur_h].push_back(i);
        }
        return "";
    }

    void hash_fun(string const& s) {
        p_pow.resize(n);
        p_pow[0] = 1;
        for (int i = 1; i < n; i++) {
            p_pow[i] = (p_pow[i-1] * p) % mod;
        }

        h.resize(n+1);
        for (int i = 0; i < n; i++) {
            h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod;
        }

        // binary searching over length from len = 1 to len = n
        // binary search for length of longest substring cuz if duplicate substring of len k is present then 
        // substring of len k-1 would of course be present, so search for greater lengths
        int low = 1, high = n;
        while(low <= high) {
            int mid = (high + low) / 2;
            
            string temp  = check(mid, s);
            if(temp.size() > ans.size()) {
                ans = temp;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    string longestDupSubstring(string s) {
        n = s.size();
        hash_fun(s);
        return ans;
    }
};














#define ll long long
class Solution {
public:
    const ll p = 31;
    const ll mod = 1e9 + 9;
    vector<ll> p_pow, h;
    ll n, pos;
    string ans = "";
    
    string check(ll len, string const& s) {
        unordered_map<ll, vector<ll>> mp;
        ll hash = h[len];
        mp[hash].push_back(0);
        
        for (ll i = 0; i < n-len; i++) {
            hash = (hash - ((s[i] - 'a') * p_pow[len-1]) % mod + mod) % mod;
            hash = (hash * p + (s[i+len] - 'a')) % mod;

            for(ll pos: mp[hash]) {
                string temp = s.substr(pos, len);
                string curr = s.substr(i + 1, len);
                if(temp.compare(curr)==0) {
                    return temp;
                }
            }
            mp[hash].push_back(i + 1);
        }
        return "";
    }

    void hash_fun(string const& s) {
        p_pow.resize(n);
        p_pow[0] = 1;
        for (int i = 1; i < n; i++) {
            p_pow[i] = (p_pow[i-1] * p) % mod;
        }

        h.resize(n+1);
        for (int i = 0; i < n; i++) {
            h[i+1] = ((h[i] * p) % mod + (s[i] - 'a')) % mod;
        }


        int low = 1, high = n;
        while(low <= high) {
            int mid = (high + low) / 2;
            
            string temp  = check(mid, s);
            if(temp.size() > ans.size()) {
                ans = temp;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    string longestDupSubstring(string s) {
        n = s.size();
        hash_fun(s);
        return ans;
    }
};















class Solution {
public:
    #define ll long long
    
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
    
    ll n;
    string ans = "";
    
    string check(ll len, string const& s, Hashing& hashStr) {
        unordered_map<ll, vector<ll>> mp;
        for (ll i = 0; i <= n - len; i++) {
            ll cur_h = hashStr.getHash(i, i + len - 1);
            for(ll pos: mp[cur_h]) {
                string temp = s.substr(pos, len);
                string curr = s.substr(i, len);
                if(temp.compare(curr) == 0) {
                    return temp;
                }
            }
            mp[cur_h].push_back(i);
        }
        return "";
    }

    string longestDupSubstring(string s) {
        n = s.size();
        
        Hashing hashStr;
        hashStr.init(s);
        
        // binary searching over length from len = 1 to len = n
        // binary search for length of longest substring cuz if duplicate substring of len k is present then 
        // substring of len k-1 would of course be present, so search for greater lengths
        int low = 1, high = n;
        while(low <= high) {
            int mid = (high + low) / 2;
            
            string temp  = check(mid, s, hashStr);
            if(temp.size() > ans.size()) {
                ans = temp;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};
