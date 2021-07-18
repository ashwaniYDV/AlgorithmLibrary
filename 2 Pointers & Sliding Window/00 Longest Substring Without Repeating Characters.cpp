// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> freq;
        int left = 0, res = 0;
        for(int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            while(freq[s[right]] > 1) {
                freq[s[left]]--;
                left++;
            }
            
            res = max(res, right - left + 1);
        }
        return res;
    }
};
