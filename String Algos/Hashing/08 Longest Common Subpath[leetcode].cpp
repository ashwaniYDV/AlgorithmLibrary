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



/*
Intuition of `check() function`
---
The idea is to determine whether there exists a common subpath of a given length `len` across all paths. 
For each path, we compute the rolling hash of every subpath of length `len`. 
For the first path, we store the hashes of all its subpaths in a set. 
For every subsequent path, we only keep the hashes that are already present in the set, effectively taking the intersection of subpaths seen so far. 
If at any point the set becomes empty, it means no common subpath of length `len` exists, so we return `false`. 
If the set is still non-empty after processing all paths, then at least one subpath of length `len` is common to every path, so we return `true`.

```
check(len):
    common = {}
    for every path:
        generate hashes of every subpath of length len
        if first path:
            common = all hashes
        else:
            common = (common) ∩ (current hashes)

        if common becomes empty:
            return false

    return true
```
here ∩ = intersection
*/



// Method 1: Using 1 hash
class Solution {
public:
    #define ll long long
    ll base = 100007, MOD = 1e11L + 7;
    vector<ll> p;

    bool check(ll len, ll m, vector<vector<int>>& paths) {
        if (len == 0) return true;

        ll basePow = p[len - 1];
        unordered_set<ll> st;

        for (ll i = 0; i < m; i++) {
            if (paths[i].size() < len) return false;

            ll hash = 0;
            // first window
            for (ll j = 0; j < len; j++) {
                hash = (hash * base + (paths[i][j] + 1)) % MOD;
            }

            unordered_set<ll> temp;

            if (i == 0) {
                temp.insert(hash);
            } else if (st.count(hash)) {
                temp.insert(hash);
            }

            // rolling hash
            for (ll j = len; j < paths[i].size(); j++) {

                hash = (hash - ((paths[i][j - len] + 1) * basePow) % MOD + MOD) % MOD;
                hash = (hash * base + (paths[i][j] + 1)) % MOD;

                if (i == 0) {
                    temp.insert(hash);
                } else if (st.count(hash)) {
                    temp.insert(hash);
                }
            }

            st = move(temp); // we can also do (st = temp;) but its copying

            if (st.empty()) return false;
        }

        return true;
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

        // TTTTTFFFFFF
        while(lo <= hi) {
            ll mid = (lo + hi) / 2;
            if(check(mid, m, paths)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return hi;
    }
};








// Method 2: Using Double Hashing
class Solution {
public:
    #define ll long long

    ll base1 = 100007, base2 = 100009;
    ll MOD1 = 1000000007LL, MOD2 = 1000000009LL;

    vector<ll> p1, p2;

    bool check(ll len, ll m, vector<vector<int>>& paths) {
        if (len == 0) return true;

        ll basePow1 = p1[len - 1];
        ll basePow2 = p2[len - 1];

        set<pair<ll, ll>> st;

        for (ll i = 0; i < m; i++) {

            if (paths[i].size() < len)
                return false;

            ll hash1 = 0, hash2 = 0;

            // First window
            for (ll j = 0; j < len; j++) {
                hash1 = (hash1 * base1 + paths[i][j] + 1) % MOD1;
                hash2 = (hash2 * base2 + paths[i][j] + 1) % MOD2;
            }

            set<pair<ll, ll>> temp;

            if (i == 0) {
                temp.insert({hash1, hash2});
            } else if (st.count({hash1, hash2})) {
                temp.insert({hash1, hash2});
            }

            // Rolling hash
            for (ll j = len; j < paths[i].size(); j++) {

                hash1 = (hash1 - ((paths[i][j - len] + 1) * basePow1) % MOD1 + MOD1) % MOD1;
                hash1 = (hash1 * base1 + paths[i][j] + 1) % MOD1;

                hash2 = (hash2 - ((paths[i][j - len] + 1) * basePow2) % MOD2 + MOD2) % MOD2;
                hash2 = (hash2 * base2 + paths[i][j] + 1) % MOD2;

                if (i == 0) {
                    temp.insert({hash1, hash2});
                } else if (st.count({hash1, hash2})) {
                    temp.insert({hash1, hash2});
                }
            }

            st = move(temp);

            if (st.empty())
                return false;
        }

        return true;
    }

    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        ll lo = 0, hi = 1e9;

        for (auto &path : paths) {
            hi = min(hi, (ll)path.size());
        }

        p1.resize(hi);
        p2.resize(hi);

        p1[0] = 1;
        p2[0] = 1;

        for (ll i = 1; i < hi; i++) {
            p1[i] = p1[i - 1] * base1 % MOD1;
            p2[i] = p2[i - 1] * base2 % MOD2;
        }

        // TTTTTFFFFFF
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;

            if (check(mid, paths.size(), paths)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return hi;
    }
};
