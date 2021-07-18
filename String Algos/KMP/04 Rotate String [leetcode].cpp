// https://leetcode.com/problems/rotate-string/

/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position.
For example, if s = "abcde", then it will be "bcdea" after one shift.

Example 1:
Input: s = "abcde", goal = "cdeab"
Output: true
*/

class Solution {
public:
    // generates PI array (or LPS [largest prefix suffix])
    vector<int> prefix_function(string &s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j]) {
                j = pi[j-1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            pi[i] = j;
        }
        return pi;
    }

    bool find_occurences(string &text, string &pattern){
        string cur = pattern + '#' + text;
        int sz1 = text.size(), sz2 = pattern.size();
        vector<int> lps = prefix_function(cur);

        for(int i = sz2 + 1; i <= sz1 + sz2; i++) {
            if(lps[i] == sz2) {
                return true;
            }
        }
        return false;
    }
    
    bool rotateString(string s, string goal) {
        if(s == goal) return true;
        if(s.size() != goal.size()) return false;
        
        s += s;
        return find_occurences(s, goal);
    }
};

















// Method 2 (hashing)
class Solution {
public:
    #define ll long long
    
    struct HashStr {
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
    
    bool rotateString(string s, string goal) {
        if(s == goal) return true;
        if(s.size() != goal.size()) return false;
        
        ll n = s.size();
        HashStr h;
        h.init(s);
        ll hash = h.getSubstringHash(0, n-1);
        
        h.init(goal);
        for(ll i = 0; i < n-1; i++) {
            ll x1 = h.getSubstringHash(0, i);
            ll x2 = h.getSubstringHash(i+1, n-1);
            
            ll y = x2 + (x1 * h.power(h.base, n - 1 - i, h.mod)) % h.mod;
            y = (y + h.mod) % h.mod;
            
            if(y == hash) return true;
        }
        return false;
    }
};
