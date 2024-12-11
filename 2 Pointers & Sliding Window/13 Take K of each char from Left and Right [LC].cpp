// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/

/*
You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. 
Each minute, you may take either the leftmost character of s, or the rightmost character of s.
Return the min no of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.

Input: s = "aabaaaacaabc", k = 2
Output: 8
Explanation: 
Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
A total of 3 + 5 = 8 minutes is needed.
It can be proven that 8 is the minimum number of minutes needed.

Input: s = "a", k = 1
Output: -1
Explanation: It is not possible to take one 'b' or 'c' so return -1.
 

Constraints:
1 <= s.length <= 10^5
s consists of only the letters 'a', 'b', and 'c'.
0 <= k <= s.length
*/


/*
Intuition
---------
* Instead of deciding whether to take or skip each individual character, 
  we can use a sliding window approach to identify which characters we don't need to 'take' to get to at least k of each character.
* Find the longest window that leaves k of each character outside
*/

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> total(3, 0);

        for (char x : s) {
            total[x - 'a']++;
        }

        // Check if we have enough characters
        for (int i = 0; i < 3; i++) {
            if (total[i] < k) return -1;
        }

        vector<int> window(3, 0);
        int l = 0, maxWindow = 0;

        // Find the longest window that leaves k of each character outside
        for (int r = 0; r < n; r++) {
            window[s[r] - 'a']++;

            // Shrink window if we take too many characters
            while (total[0] - window[0] < k || total[1] - window[1] < k || total[2] - window[2] < k) {
                window[s[l] - 'a']--;
                l++;
            }

            maxWindow = max(maxWindow, r - l + 1);
        }

        return n - maxWindow;
    }
};



// TLE
class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k == 0) return 0;
        int n = s.size();
        vector<vector<int>> suf(n, vector<int>(3, 0));

        int res = INT_MAX;

        suf[n-1][0] = s[n-1] == 'a';
        suf[n-1][1] = s[n-1] == 'b';
        suf[n-1][2] = s[n-1] == 'c';

        if(suf[n-1][0] >= k && suf[n-1][1] >= k && suf[n-1][2] >= k) {
            res = min(res, 1);
        }

        for(int i = n-2; i >= 0; i--) {
            suf[i][0] = suf[i+1][0] + (s[i] == 'a');
            suf[i][1] = suf[i+1][1] + (s[i] == 'b');
            suf[i][2] = suf[i+1][2] + (s[i] == 'c');

            if(suf[i][0] >= k && suf[i][1] >= k && suf[i][2] >= k) {
                res = min(res, n - i);
            }
        }

        int la = 0, lb = 0, lc = 0;
        for(int i = 0; i < n; i++) {
            la += (s[i] == 'a');
            lb += (s[i] == 'b');
            lc += (s[i] == 'c');

            if(la >= k && lb >= k && lc >= k) {
                res = min(res, i+1);
            }

            int ra = max(0, k - la);
            int rb = max(0, k - lb);
            int rc = max(0, k - lc);

            // TTTTFFFF
            int lo = i+1, hi = n-1;
            while(lo <= hi) {
                int mid = (lo+hi) / 2;
                if(suf[mid][0] >= ra && suf[mid][1] >= rb && suf[mid][2] >= rc) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            cout << "i, hi = " << i << " " << hi << endl;

            if(i+1 <= n-1 && hi >= i+1 && hi <= n-1) {
                res = min(res, (i+1) + (n - hi));
            }
        }
        
        return res == INT_MAX ? -1 : res;
    }
};