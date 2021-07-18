// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

/*
Given an input stream of A of n characters consisting only of lower case alphabets. 
The task is to find the first non repeating character, each time a character is inserted to the stream. 
If there is no such character then append '#' to the answer.

Note: You need to tell the first non-repeating character in O(1) time at any moment.

Input: A = "aabc"
Output: "a#bb"
*/


// TLE O(26 * n) solution

class Solution {
public:
    // {x, y} , x = freq, y = first found index
    vector<pair<int, int>> v;

    int getIdx() {
        int minIndex = INT_MAX;
        for (auto it : v) {
            if (it.first == 1) {
                minIndex = min(minIndex, it.second);
            }
        }
        return minIndex == INT_MAX ? -1 : minIndex;
    }

    string FirstNonRepeating(string s) {
        v = vector<pair<int, int>>(26);
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            v[idx].first++;
            v[idx].second = i;

            idx = getIdx();
            if (idx == -1) res += "#";
            else res += s[idx];
        }
        return res;
    }
};
