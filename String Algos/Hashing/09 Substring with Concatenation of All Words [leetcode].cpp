/*
You are given a string s and an array of strings words of the same length. 
Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, 
in any order, and without any intervening characters.
You can return the answer in any order.

Example 1:
Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Example 2:
Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []

Example 3:
Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
 

Constraints:
1 <= s.length <= 10^4
s consists of lower-case English letters.
1 <= words.length <= 5000
1 <= words[i].length <= 30
words[i] consists of lower-case English letters.
*/

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
        ll pw_inv = power(base, mod - 2, mod);
        for(ll i = 1; i < N; i++) {
            p[i] = mult(p[i - 1], base, mod);
            p_inv[i] = mult(p_inv[i - 1], pw_inv, mod);
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

    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length(), num = words.size();
        if (n == 0 || num == 0) return {};
        int len = words[0].size();
        
        preprocess();
        vector<int> res;
        
        unordered_map<int, int> counts;
        for(string x: words) {
            initHash(x);
            counts[getHash(0, len - 1)]++;
        }

        initHash(s);
        for (int i = 0; i <= n - num * len ; i++) {
            unordered_map<int, int> seen;
            int j = 0;
            for (; j < num; j++) {
                int wordhash = getHash(i + j * len, i + j * len + len - 1);
                if (counts.find(wordhash) != counts.end()) {
                    seen[wordhash]++;
                    if (seen[wordhash] > counts[wordhash])
                        break;
                }
                else break;
            }
            if (j == num) res.push_back(i);
        }
        return res;
    }
};
