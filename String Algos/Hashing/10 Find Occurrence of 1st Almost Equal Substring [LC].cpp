// https://leetcode.com/problems/find-the-occurrence-of-first-almost-equal-substring/
// https://leetcode.com/problems/find-the-occurrence-of-first-almost-equal-substring/description/

/*
You are given two strings s and pattern.
A string x is called almost equal to y if you can change at most one character in x to make it identical to y.
Return the smallest starting index of a substring in s that is almost equal to pattern. If no such index exists, return -1.

Example 1:
Input: s = "abcdefg", pattern = "bcdffg"
Output: 1

Example 2:
Input: s = "ababbababa", pattern = "bacaba"
Output: 4

Constraints:
1 <= pattern.length < s.length <= 10^5
s and pattern consist only of lowercase English letters.
*/


class Solution {
public:
    #define ll long long

    // Large prime to avoid collisions
    // 1e9+7 was failing for a TC
    ll base = 31, mod = 1e13 + 7;
    
    int minStartingIndex(string s, string p) {
        int n = s.size(), m = p.size();
        
        unordered_map<ll, int> hashToIndex;

        // 1. Pre-calculate power of base for the window size
        ll power = 1;
        for (int i = 0; i < m; i++) power = (power * base) % mod;

        // 2. Rolling Hash for all substrings of 's' of length 'm'
        ll sHash = 0;
        for (int i = 0; i < n; i++) {
            sHash = (sHash * base + (s[i] - 'a' + 1)) % mod;
            if (i >= m) {
                // Remove the character falling out of the window
                sHash = (sHash - (s[i - m] - 'a' + 1) * power % mod + mod) % mod;
            }
            if (i >= m - 1) {
                // Store only the first occurrence of each hash
                if (!hashToIndex.count(sHash)) {
                    hashToIndex[sHash] = i - m + 1;
                }
            }
        }

        // 3. Calculate original hash of 'p'
        ll pHash = 0;
        for (char c : p) pHash = (pHash * base + (c - 'a' + 1)) % mod;

        // 4. Try changing each character in 'p' to find a match in 's'
        int minIdx = INT_MAX;
        ll currentPower = 1;
        
        for (int i = m - 1; i >= 0; i--) {
            // Remove the original character at p[i] from the hash
            ll baseHash = (pHash - (p[i] - 'a' + 1) * currentPower % mod + mod) % mod;
            
            for (char ch = 'a'; ch <= 'z'; ch++) {
                ll newHash = (baseHash + (ch - 'a' + 1) * currentPower) % mod;
                if (hashToIndex.count(newHash)) {
                    minIdx = min(minIdx, hashToIndex[newHash]);
                }
            }
            currentPower = (currentPower * base) % mod;
        }

        return minIdx == INT_MAX ? -1 : minIdx;
    }
};
