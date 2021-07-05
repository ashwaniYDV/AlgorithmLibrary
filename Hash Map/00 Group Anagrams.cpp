// https://leetcode.com/problems/group-anagrams/

/*
Use an unordered_map to group the strings by their sorted counterparts. Use the sorted string as the key and all anagram strings as the value.

Moreover, since the string only contains lower-case alphabets, we can sort them using counting sort to improve the time complexity.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s: strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto it: mp) { 
            anagrams.push_back(it.second);
        }
        return anagrams;
    }
};







class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s: strs) {
            mp[strCountingSort(s)].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto it: mp) { 
            anagrams.push_back(it.second);
        }
        return anagrams;
    }
private:
    string strCountingSort(string s) {
        int counter[26] = {0};
        for (char c: s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};
