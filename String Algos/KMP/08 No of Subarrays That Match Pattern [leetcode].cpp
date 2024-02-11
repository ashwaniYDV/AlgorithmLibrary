// https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-ii

/*
You are given a 0-indexed integer array nums of size n, and a 0-indexed integer array pattern of size m consisting of integers -1, 0, and 1.
A subarray nums[i..j] of size m + 1 is said to match the pattern if the following conditions hold for each element pattern[k]:
  nums[i + k + 1] > nums[i + k] if pattern[k] == 1.
  nums[i + k + 1] == nums[i + k] if pattern[k] == 0.
  nums[i + k + 1] < nums[i + k] if pattern[k] == -1.
Return the count of subarrays in nums that match the pattern.
*/

/*
Create a second array nums2 such that 
  nums2[i] = 1 if nums[i + 1] > nums[i], 
  nums2[i] = 0 if nums[i + 1] == nums[i], and 
  nums2[i] = -1 if nums[i + 1] < nums[i].

The problem becomes: “Count the number of subarrays in nums2 that are equal to pattern.
*/

class Solution {
public:
    vector<int> prefix_function(string& s) {
        int n = (int)s.size();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j]) {
                j = pi[j-1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            pi[i] = j;
        }
        return pi;
    }

    int find_occurences(string& text, string& pattern){
        string s = pattern + '#' + text;

        int t = text.size(), p = pattern.size();

        vector<int> lps = prefix_function(s);

        int res = 0;
        for(int i = p + 1; i < lps.size(); i++) {
            if(lps[i] == p) {
                res++;
            }
        }
        return res;
    }

    int countMatchingSubarrays(vector<int>& nums, vector<int>& pat) {
        string text;
        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                text.push_back('1');
            }
            if (nums[i] == nums[i-1]) {
                text.push_back('0');
            }
            if (nums[i] < nums[i-1]) {
                text.push_back('2');
            }
        }

        string pattern;
        for(int x: pat) {
            if (x == 1) pattern.push_back('1');
            if (x == 0) pattern.push_back('0');
            if (x == -1) pattern.push_back('2');
        }

        return find_occurences(text, pattern);
        
    }
};
