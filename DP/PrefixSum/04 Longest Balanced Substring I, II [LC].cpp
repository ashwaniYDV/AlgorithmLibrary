// https://leetcode.com/problems/longest-balanced-substring-ii/description/
// https://leetcode.com/problems/longest-balanced-substring-ii/solutions/7572703/on-prefix-difference-hashmap-intuition-d-jsjd/

/*
You are given a string s consisting only of the characters 'a', 'b', and 'c'.
A substring of s is called balanced if all distinct characters in the substring appear the same number of times.
Return the length of the longest balanced substring of s.

Example 1:
Input: s = "abbac"
Output: 4

Example 2:
Input: s = "aabcc"
Output: 3

Example 3:
Input: s = "aba"
Output: 2

Constraints:
1 <= s.length <= 10^5
s contains only the characters 'a', 'b', and 'c'.
*/


class Solution {
public:
    int maxOneChar(string s, int n) {
        int cnt = 1, res = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) cnt++;
            else cnt = 1;

            res = max(res, cnt);
        }
        return res;
    }

    int max2Chars(char x, char y, char z, string s, int n) {
        int res = 0;
        int i = 0;
        while(i < n) {
            if(s[i] == z) {
                i++;
                continue;
            }

            unordered_map<int, int> mp;
            int cnt = 0;
            mp[cnt] = i - 1;
            while(i < n && s[i] != z) {
                cnt += (s[i] == x) ? -1: 1;
                if(mp.count(cnt)) {
                    res = max(res, i - mp[cnt]);
                } else {
                    mp[cnt] = i;
                }
                i++;
            }
        }

        return res;
    }

    int max3Chars(string s, int n) {
        int res = 0;
        map<pair<int, int>, int> mp;
        int cntA = 0, cntB = 0, cntC = 0;
        mp[{0, 0}] = -1;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') cntA++;
            if(s[i] == 'b') cntB++;
            if(s[i] == 'c') cntC++;

            if(mp.count({cntA-cntB, cntB-cntC})) {
                res = max(res, i - mp[{cntA-cntB, cntB-cntC}]);
            } else {
                mp[{cntA-cntB, cntB-cntC}] = i;
            }
        }

        return res;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int res = max({
            // for single character
            maxOneChar(s, n),

            // finding max for 2 characters
            max2Chars('a', 'b', 'c', s, n),
            max2Chars('b', 'c', 'a', s, n),
            max2Chars('c', 'a', 'b', s, n),

            // finding max for considering all 3 character
            max3Chars(s, n)
        });
        return res;
    }
};












// https://codeforces.com/problemset/problem/873/B

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    unordered_map<int, int> mp;
    mp[0] = -1;
    int res = 0;
    int sum = 0;
    
    for(int i = 0; i < n; i++) {
        sum += s[i] == '0' ? -1 : 1;
        
        if(mp.count(sum)) {
            res = max(res, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }
    cout << res;

}

int main() {
    int t = 1;
    // cin >> t;
    while(t--) solve();
}
