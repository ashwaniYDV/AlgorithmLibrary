// https://leetcode.com/problems/longest-common-subpath/

/*
Question:
Longest common substring given n strings.
*/

/*
Problem:
There is a country of n cities numbered from 0 to n - 1. In this country, there is a road connecting every pair of cities.
There are m friends numbered from 0 to m - 1 who are traveling through the country. Each one of them will take a path consisting of some cities. 
Each path is represented by an integer array that contains the visited cities in order. 
The path may contain a city more than once, but the same city will not be listed consecutively.
Given an integer n and a 2D integer array paths where paths[i] is an integer array representing the path of the ith friend, 
return the length of the longest common subpath that is shared by every friend's path, or 0 if there is no common subpath at all.
A subpath of a path is a contiguous sequence of cities within that path.

Example:
Input: 
n = 5, paths = [[0,1,2,3,4],
                [2,3,4],
                [4,0,1,2,3]]
Output: 
2
Explanation: The longest common subpath is [2,3].


Constraints:

1 <= n <= 10^5
m == paths.length
2 <= m <= 10^5
sum(paths[i].length) <= 10^5
0 <= paths[i][j] < n
The same city is not listed multiple times consecutively in paths[i].
*/


/*
Please note that we have to choose base wisely i.e. base >= 100000.
I liked the way you used rolling hash in reverse order... removing the use of modular inverse.

If we find a common subpath of length k using binary search, then it means we can search for longer common subpaths. 
If not, then it means that we have to reduce our search space by half. 
So we check possible length for a max of O(logn) times as that is the max length of the minimum sized path.
*/

// Method 1: Using 1 hash
class Solution {
public:
    #define ll long long    
    ll base = 100007, MOD = 1e11L + 7;
    vector<ll> p;
    
    bool check(ll len, ll n, vector<vector<int>>& paths) {
        unordered_set<ll> s;
        for(ll i = 0; i < n; i++) {
            if(paths[i].size() < len) {
                return false;
            }

            ll hash = 0;
            for(ll j = 0; j < len; j++) {
                hash = (hash + (((paths[i][j] + 1) * p[len - 1 - j]) % MOD)) % MOD;
            }
            
            unordered_set<ll> tempS;
            if(i == 0) {
                s.insert(hash);
            } else {
                if(s.find(hash) != s.end()) {
                    tempS.insert(hash);
                }
            }
            
            for(ll j = len; j < paths[i].size(); j++) {
                ll x = ((paths[i][j - len] + 1) * p[len - 1]) % MOD;
                hash = (hash - x + MOD) % MOD;
                hash = hash * base % MOD;
                hash = (hash + paths[i][j] + 1) % MOD;
                if(i == 0) {
                    s.insert(hash);
                } else {
                    if(s.find(hash) != s.end()) {
                        tempS.insert(hash);
                    }
                }
            }
            if(i > 0) {
                s = tempS;
            }
            if(s.size() == 0) {
                return false;
            }
        }
        return s.size() > 0;
    }
    
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int m = paths.size();
        ll lo = 0, hi = 1e9L;
        for(auto path: paths) {
            hi = min(hi, (ll)path.size());
        }
        p = vector<ll>(hi);
        p[0] = 1;
        for(ll i = 1; i < hi; i++) {
            p[i] = (ll)base * p[i - 1] % MOD;
        }
        while(lo < hi) {
            ll mid = (lo + hi + 1) / 2;
            if(check(mid, m, paths)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return hi;
    }
};











// Method 2: Using 2 hash
class Solution {
public:
    #define ll long long    
    ll base1 = 100007, base2 = 100009, MOD1 = 1e9L + 7, MOD2 = 1e11L + 7;
    vector<ll> p1, p2;
    
    bool check(ll len, ll n, vector<vector<int>>& paths) {
        set<pair<ll, ll>> s;
        for(ll i = 0; i < n; i++) {
            if(paths[i].size() < len) {
                return false;
            }

            ll hash1 = 0, hash2 = 0;
            for(ll j = 0; j < len; j++) {
                hash1 = (hash1 + (((paths[i][j] + 1) * p1[len - 1 - j]) % MOD1)) % MOD1;
                hash2 = (hash2 + (((paths[i][j] + 1) * p2[len - 1 - j]) % MOD2)) % MOD2;
            }
            
            set<pair<ll, ll>> tempS;
            if(i == 0) {
                s.insert({hash1, hash2});
            } else {
                if(s.find({hash1, hash2}) != s.end()) {
                    tempS.insert({hash1, hash2});
                }
            }
            
            for(ll j = len; j < paths[i].size(); j++) {
                ll x = ((paths[i][j - len] + 1) * p1[len - 1]) % MOD1;
                hash1 = (hash1 - x + MOD1) % MOD1;
                hash1 = (hash1 * base1) % MOD1;
                hash1 = (hash1 + paths[i][j] + 1) % MOD1;
                
                x = ((paths[i][j - len] + 1) * p2[len - 1]) % MOD2;
                hash2 = (hash2 - x + MOD2) % MOD2;
                hash2 = (hash2 * base2) % MOD2;
                hash2 = (hash2 + paths[i][j] + 1) % MOD2;
                
                if(i == 0) {
                    s.insert({hash1, hash2});
                } else {
                    if(s.find({hash1, hash2}) != s.end()) {
                        tempS.insert({hash1, hash2});
                    }
                }
            }
            if(i > 0) {
                s = tempS;
            }
            if(s.size() == 0) {
                return false;
            }
        }
        return s.size() > 0;
    }
    
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int m = paths.size();
        ll lo = 0, hi = 1e9L;
        for(auto path: paths) {
            hi = min(hi, (ll)path.size());
        }
        p1 = vector<ll>(hi);
        p2 = vector<ll>(hi);
        p1[0] = 1;
        p2[0] = 1;
        for(ll i = 1; i < hi; i++) {
            p1[i] = (ll)base1 * p1[i - 1] % MOD1;
            p2[i] = (ll)base2 * p2[i - 1] % MOD2;
        }
        while(lo < hi) {
            ll mid = (lo + hi + 1) / 2;
            if(check(mid, m, paths)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};
