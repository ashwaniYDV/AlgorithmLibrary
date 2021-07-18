// https://leetcode.com/problems/first-unique-character-in-a-string/
// https://www.geeksforgeeks.org/given-a-string-find-its-first-non-repeating-character/

/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1
*/


class Solution {
public:
    int firstUniqChar(string s) {
        // {x, y} , x = freq, y = first found index
        vector<pair<int, int>> v(26);
        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            v[idx].first++;
            v[idx].second = i;
        }

        int minIndex = INT_MAX;
        for (auto it : v) {
            if (it.first == 1) {
                minIndex = min(minIndex, it.second);
            }
        }
        return minIndex == INT_MAX ? -1 : minIndex;
    }
};
