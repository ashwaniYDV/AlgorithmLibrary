// https://leetcode.com/problems/wiggle-subsequence/
// https://www.quora.com/Is-it-possible-to-compute-longest-alternating-subsequence-of-a-sequence-O-n-time-If-so-how

// same concept of valley as in 'buy and sell stocks at any number of times' problem 

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> a;
        
        // Removing consecutive duplicates
        for(int i = 0; i < n; i++) {
            if(a.size() == 0 || nums[i] != a.back()) 
                a.push_back(nums[i]);
        }
        
        n = a.size();
        if(n <= 1) return n;
        
        // A subsequence will have atlesast 2 size (i.e first and last element)
        int LAS = 2;
        
        for(int i = 1; i < n-1; i++) {
            // valleys and peaks will occur when we count element to answer
            // either current element is smaller or greater than both adjacent elements
            if((a[i] < a[i-1] && a[i] < a[i+1]) || (a[i] > a[i-1] && a[i] > a[i+1])) 
                LAS++;
        }
        
        return LAS;
    }
};
