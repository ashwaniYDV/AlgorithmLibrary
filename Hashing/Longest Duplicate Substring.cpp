// https://leetcode.com/problems/longest-duplicate-substring/

#define ll long long
class Solution {
public:
    const ll p = 31;
    const ll mod = 1e9 + 9;
    vector<ll> p_pow, h;
    ll n, pos;
    string ans, str;
    
    bool check(ll len, string const& s) {
        unordered_map<ll, vector<ll>> mp;
        for (ll i = 0; i <= n - len; i++) {
            ll cur_h = (h[i + len] - h[i] + mod) % mod;
            cur_h = (cur_h * p_pow[n-1-i]) % mod;
            for(ll pos: mp[cur_h]) {
                string temp = s.substr(pos, len);
                string curr = s.substr(i, len);
                if(temp.compare(curr)==0) {
                    str = temp;
                    return true;
                }
            }
            mp[cur_h].push_back(i);
        }
        return false;
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
        ans = "";
        while(low <= high) {
            int mid = (high + low) / 2;
            str  = "";
            if(check(mid, s)) {
                if(str.size() > ans.size()) ans = str;
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
